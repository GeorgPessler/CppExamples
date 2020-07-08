class Foo {
public: 
  Foo(char x, int y) {}
  Foo(int y) : Foo('a', y) {} // Foo(int) delegates to Foo(char,int)
};