// godbolt: -Xclang -load -Xclang build/skeleton/libSkeletonPass.so -S
// -emit-llvm -flegacy-pass-manager -O3

int puts(char const *);

#define JNI(javaSymbol, nativeSymbol)                                          \
  __attribute__((annotate("JNIRegistration", javaSymbol, nativeSymbol)))

#define JNIFunc(returnType, name, javaSymbol, ...)                             \
  __attribute__((annotate("JNIRegistration", javaSymbol, #name))) returnType   \
  name(__VA_ARGS__)

JNIFunc(int, doStuff, "muffin", int q) { return 4; }

JNI("muffin", "doThing")
int doThing(int a) {
  puts("I got called!");
  return a;
}

int main(int argc, char const **argv) {
  int a = 42 + argc;
  return a;
}
