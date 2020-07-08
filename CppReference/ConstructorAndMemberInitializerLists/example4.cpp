struct A {
    A() : v(42) { }  // Error
    const int& v;
};