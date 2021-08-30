#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/Operator.h"
#include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"
using namespace llvm;

#define DEBUG_TYPE "skeleton-pass"

namespace {
struct SkeletonPass : public ModulePass {
  static char ID;
  SkeletonPass() : ModulePass(ID) {}

  StringRef getPassName() { return "skeleton-pass"; }

  virtual bool runOnModule(Module &M) override {
    errs() << "HI" << '\n';
    auto &Ctx = M.getContext();
    auto LogOp = M.getOrInsertFunction("logop", Type::getVoidTy(Ctx),
                                       Type::getInt32Ty(Ctx));
    bool Changed = false;
    for (auto &F : M) {
      for (auto &BB : F) {
        for (auto &I : BB) {
          if (auto *Add = dyn_cast<AddOperator>(&I)) {
            IRBuilder<> B(&I);
            B.SetInsertPoint(&BB, ++B.GetInsertPoint());

            Value *LHS = Add->getOperand(0);
            Value *RHS = Add->getOperand(1);
            auto *Mul = B.CreateMul(LHS, RHS);
            Add->replaceAllUsesWith(Mul);

            Value *Args = {Add};
            B.CreateCall(LogOp, Args);

            Value *Args2 = {Mul};
            B.CreateCall(LogOp, Args2);

            Changed = true;
          }
        }
      }
    }

    auto GlobalAnnotations = M.getNamedGlobal("llvm.global.annotations");
    auto *a = cast<ConstantArray>(GlobalAnnotations->getOperand(0));

    for (int i = 0; i < a->getNumOperands(); ++i) {
      auto e = cast<ConstantStruct>(a->getOperand(i));
      if (auto fn = dyn_cast<Function>(e->getOperand(0)->getOperand(0))) {
        auto anno = cast<ConstantDataArray>(
                        cast<GlobalVariable>(e->getOperand(1)->getOperand(0))
                            ->getOperand(0))
                        ->getAsCString();
        auto eleFour = e->getOperand(4);
        auto argOneBitcastExpression = cast<ConstantExpr>(eleFour);
        auto operandZero = argOneBitcastExpression->getOperand(0);
        auto asStruct = cast<ConstantAggregate>(operandZero);
        auto arg1 =
            cast<ConstantDataArray>(asStruct->getOperand(1))->getAsCString();
        errs() << anno << ", " << arg1 << '\n';
        fn->addFnAttr(anno);
      }
    }

    std::vector<Function *> FunctionsToCall;

    for (auto &F : M) {
      if (F.hasFnAttribute("invoke_me")) {
        errs() << F.hasName() << " needs invoked!\n";
        FunctionsToCall.push_back(&F);
      }
    }

    auto *F = M.getFunction("main");

    auto &EBB = F->getEntryBlock();

    IRBuilder<> Builder{&EBB, EBB.getFirstInsertionPt()};
    for (auto *FnToCall : FunctionsToCall) {
      Value *Args = {ConstantInt::get(IntegerType::getInt32Ty(Ctx), 44)};
      auto Callee = M.getOrInsertFunction(
          FnToCall->getName(), Type::getInt32Ty(Ctx), Type::getInt32Ty(Ctx));
      Builder.CreateCall(Callee, Args);
    }

    return Changed;
  }
};
} // namespace

char SkeletonPass::ID = 0;

// Automatically enable the pass.
// http://adriansampson.net/blog/clangpass.html
static void registerSkeletonPass(const PassManagerBuilder &,
                                 legacy::PassManagerBase &PM) {
  errs() << "register" << '\n';
  PM.add(new SkeletonPass());
}
static RegisterStandardPasses
    // RegisterMyPass(PassManagerBuilder::EP_EarlyAsPossible,
    // RegisterMyPass(PassManagerBuilder::EP_ModuleOptimizerEarly,
    RegisterMyPass(PassManagerBuilder::EP_EnabledOnOptLevel0,
                   registerSkeletonPass);

static RegisterStandardPasses
    // RegisterMyPass(PassManagerBuilder::EP_EarlyAsPossible,
    RegisterMyPassWithOpts(
        PassManagerBuilder::EP_ModuleOptimizerEarly,
        // RegisterMyPass(PassManagerBuilder::EP_EnabledOnOptLevel0,
        registerSkeletonPass);
