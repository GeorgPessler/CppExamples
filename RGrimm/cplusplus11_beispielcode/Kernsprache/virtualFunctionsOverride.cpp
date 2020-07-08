class Base {

  void func1();
  virtual void func2(float);
  virtual void func3() const;
  virtual long func4(int);

  virtual void f();
  virtual void h(int) final;
};

class Derived: public Base {

  // ill-formed; no virtual method func1 exists
  virtual void fun1() override;

  // ill-formed: bad type
  virtual void func2(double) override;

  // ill-formed: const missing
  virtual void func3() override;

  // ill-formed: wrong return type
  virtual int func4(int) override;

  // well-formed: f override Base::f
  virtual void f() override;

  // well-formed: a new (final) virtual method
  virtual void g(long) final;

  // ill-formed: base method declared final
  virtual void h(int);

  // well-formed: a new virtual function
  virtual void h(double);

};

int main(){

  Base base;
  Derived derived;

};
