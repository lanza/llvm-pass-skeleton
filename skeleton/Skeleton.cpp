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

#include <llvm/IR/ConstantsContext.h>
#include <llvm/IR/Statepoint.h>
void printTheClass(User *V) {
#define T(u) (u::classof(V))
  if T (User) {
    errs() << "User\n";
    if T (Operator) {
      errs() << "Operator\n";
      if T (OverflowingBinaryOperator) {
        errs() << "OverflowingBinaryOperator\n";
      } else if T (PossiblyExactOperator) {
        errs() << "PossiblyExactOperator\n";
      } else if T (FPMathOperator) {
        errs() << "FPMathOperator\n";
      }
    } else if T (Instruction) {
      errs() << "Instruction\n";
      if T (StoreInst) {
        errs() << "StoreInst\n";
      } else if T (FenceInst) {
        errs() << "FenceInst\n";
      } else if T (AtomicCmpXchgInst) {
        errs() << "AtomicCmpXchgInst\n";
      } else if T (AtomicRMWInst) {
        errs() << "AtomicRMWInst\n";
      } else if T (GetElementPtrInst) {
        errs() << "GetElementPtrInst\n";
      } else if T (SelectInst) {
        errs() << "SelectInst\n";
      } else if T (ExtractElementInst) {
        errs() << "ExtractElementInst\n";
      } else if T (InsertElementInst) {
        errs() << "InsertElementInst\n";
      } else if T (ShuffleVectorInst) {
        errs() << "ShuffleVectorInst\n";
      } else if T (InsertValueInst) {
        errs() << "InsertValueInst\n";
      } else if T (PHINode) {
        errs() << "PHINode\n";
      } else if T (LandingPadInst) {
        errs() << "LandingPadInst\n";
      } else if T (ReturnInst) {
        errs() << "ReturnInst\n";
      } else if T (BranchInst) {
        errs() << "BranchInst\n";
      } else if T (SwitchInst) {
        errs() << "SwitchInst\n";
      } else if T (IndirectBrInst) {
        errs() << "IndirectBrInst\n";
      } else if T (ResumeInst) {
        errs() << "ResumeInst\n";
      } else if T (CatchSwitchInst) {
        errs() << "CatchSwitchInst\n";
      } else if T (CatchReturnInst) {
        errs() << "CatchReturnInst\n";
      } else if T (CleanupReturnInst) {
        errs() << "CleanupReturnInst\n";
      } else if T (UnreachableInst) {
        errs() << "UnreachableInst\n";
      } else if T (UnaryInstruction) {
        errs() << "UnaryInstruction\n";
        if T (AllocaInst) {
          errs() << "AllocaInst\n";
        } else if T (LoadInst) {
          errs() << "LoadInst\n";
        } else if T (VAArgInst) {
          errs() << "VAArgInst\n";
        } else if T (ExtractValueInst) {
          errs() << "ExtractValueInst\n";
        } else if T (FreezeInst) {
          errs() << "FreezeInst\n";
        } else if T (UnaryOperator) {
          errs() << "UnaryOperator\n";
        } else if T (CastInst) {
          errs() << "CastInst\n";
          if T (TruncInst) {
            errs() << "TruncInst\n";
          } else if T (ZExtInst) {
            errs() << "ZExtInst\n";
          } else if T (SExtInst) {
            errs() << "SExtInst\n";
          } else if T (FPTruncInst) {
            errs() << "FPTruncInst\n";
          } else if T (FPExtInst) {
            errs() << "FPExtInst\n";
          } else if T (UIToFPInst) {
            errs() << "UIToFPInst\n";
          } else if T (SIToFPInst) {
            errs() << "SIToFPInst\n";
          } else if T (FPToUIInst) {
            errs() << "FPToUIInst\n";
          } else if T (FPToSIInst) {
            errs() << "FPToSIInst\n";
          } else if T (IntToPtrInst) {
            errs() << "IntToPtrInst\n";
          } else if T (PtrToIntInst) {
            errs() << "PtrToIntInst\n";
          } else if T (BitCastInst) {
            errs() << "BitCastInst\n";
          } else if T (AddrSpaceCastInst) {
            errs() << "AddrSpaceCastInst\n";
          } else {
            assert(false && "Unknown type");
          }
        }
      } else if T (BinaryOperator) {
        errs() << "BinaryOperator\n";
        if T (ICmpInst) {
          errs() << "ICmpInst\n";
        } else if T (FCmpInst) {
          errs() << "FCmpInst\n";
        } else {
          assert(false && "Unknown type");
        }
      } else if T (CmpInst) {
        errs() << "CmpInst\n";
      } else if T (CallBase) {
        errs() << "CallBase\n";
        if T (CallInst) {
          assert(false);
        } else if T (InvokeInst) {
          errs() << "InvokeInst\n";
        } else if T (CallBrInst) {
          errs() << "CallBrInst\n";
        } else if T (GCStatepointInst) {
          errs() << "GCStatepointInst\n";
        } else {
          assert(false && "Unknown type");
        }
      } else if T (FuncletPadInst) {
        errs() << "FuncletPadInst\n";
        if T (CleanupPadInst) {
          errs() << "CleanupPadInst\n";
        } else if T (CatchPadInst) {
          errs() << "CatchPadInst\n";
        } else {
          assert(false && "Unknown type");
        }
      } else {
        assert(false && "Unknown type");
      }
    } else if T (Constant) {
      errs() << "Constant\n";
      if T (ConstantData) {
        errs() << "ConstantData\n";
        if T (ConstantInt) {
          errs() << "ConstantInt\n";
        } else if T (ConstantFP) {
          errs() << "ConstantFP\n";
        } else if T (ConstantAggregateZero) {
          errs() << "ConstantAggregateZero\n";
        } else if T (ConstantPointerNull) {
          errs() << "ConstantPointerNull\n";
        } else if T (ConstantDataSequential) {
          assert(false);
        } else if T (ConstantTokenNone) {
          errs() << "ConstantTokenNone\n";
        } else if T (UndefValue) {
          assert(false);
        } else {
          assert(false && "Unknown type");
        }
      } else if T (ConstantAggregate) {
        errs() << "ConstantAggregate\n";
        if T (ConstantArray) {
          errs() << "ConstantArray\n";
        } else if T (ConstantStruct) {
          errs() << "ConstantStruct\n";
        } else if T (ConstantVector) {
          errs() << "ConstantVector\n";
        } else {
          assert(false && "Unknown type");
        }
      } else if T (BlockAddress) {
        errs() << "BlockAddress\n";
      } else if T (DSOLocalEquivalent) {
        errs() << "DSOLocalEquivalent\n";
      } else if T (ConstantExpr) {
        errs() << "ConstantExpr\n";
        if T (UnaryConstantExpr) {
          errs() << "UnaryConstantExpr\n";
        } else if T (BinaryConstantExpr) {
          errs() << "BinaryConstantExpr\n";
        } else if T (SelectConstantExpr) {
          errs() << "SelectConstantExpr\n";
        } else if T (ExtractElementConstantExpr) {
          errs() << "ExtractElementConstantExpr\n";
        } else if T (InsertElementConstantExpr) {
          errs() << "InsertElementConstantExpr\n";
        } else if T (ShuffleVectorConstantExpr) {
          errs() << "ShuffleVectorConstantExpr\n";
        } else if T (ExtractValueConstantExpr) {
          errs() << "ExtractValueConstantExpr\n";
        } else if T (InsertValueConstantExpr) {
          errs() << "InsertValueConstantExpr\n";
        } else if T (GetElementPtrConstantExpr) {
          errs() << "GetElementPtrConstantExpr\n";
        } else if T (CompareConstantExpr) {
          errs() << "CompareConstantExpr\n";
        } else if T (ConstantPlaceHolder) {
          errs() << "ConstantPlaceHolder\n";
        } else {
          assert(false && "Unknown type");
        }
      } else if T (GlobalValue) {
        errs() << "GlobalValue\n";
        if T (GlobalIndirectSymbol) {
          errs() << "GlobalIndirectSymbol\n";
          if T (GlobalAlias) {
            errs() << "GlobalAlias\n";
          } else if T (GlobalIFunc) {
            errs() << "GlobalIFunc\n";
          } else {
            assert(false && "Unknown type");
          }
        } else if T (GlobalObject) {
          errs() << "GlobalObject\n";
          if T (Function) {
            errs() << "Function\n";
          } else if T (GlobalVariable) {
            errs() << "GlobalVariable\n";
          } else {
            assert(false && "Unknown type");
          }
        } else {
          assert(false && "Unknown type");
        }
      } else if T (DerivedUser) {
        errs() << "DerivedUser\n";
        if T (MemoryAccess) {
          errs() << "MemoryAccess\n";
          if T (MemoryUseOrDef) {
            errs() << "MemoryUseOrDef\n";
            if T (MemoryUse) {
              errs() << "MemoryUse\n";
            } else if T (MemoryDef) {
              errs() << "MemoryDef\n";
            } else {
              assert(false && "Unknown type");
            }
          } else if T (MemoryPhi) {
            errs() << "MemoryPhi\n";
          } else {
            assert(false && "Unknown type");
          }
        } else {
          assert(false && "Unknown type");
        }
      } else {
        assert(false && "Unknown type");
      }
    } else {
      assert(false && "Unknown type");
    }
  } else {
    assert(false && "Unknown type");
  }
}

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
        auto asStruct = cast<ConstantStruct>(
            cast<GlobalVariable>(operandZero)->getOperand(0));
        auto arg1 =
            cast<ConstantDataArray>(
                cast<GlobalVariable>(asStruct->getOperand(0))->getOperand(0))
                ->getAsCString();
        auto arg2 =
            cast<ConstantDataArray>(
                cast<GlobalVariable>(asStruct->getOperand(1))->getOperand(0))
                ->getAsCString();
        errs() << anno << ": " << arg1 << "->" << arg2 << '\n';
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
