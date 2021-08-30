// godbolt: -Xclang -load -Xclang build/skeleton/libSkeletonPass.so -S -emit-llvm -flegacy-pass-manager -O3

int puts(char const*);

__attribute__((annotate("invoke_me","muffin")))
int doThing(int a) {
  puts("I got called!");
  return a;
}

int main(int argc, char const **argv) {
  int a = 42 + argc;
  return a;
}

