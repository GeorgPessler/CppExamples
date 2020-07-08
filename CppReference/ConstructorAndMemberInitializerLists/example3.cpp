struct S {
    int n = 42;   // default member initializer
    S() : n(7) {} // will set n to 7, not 42
};