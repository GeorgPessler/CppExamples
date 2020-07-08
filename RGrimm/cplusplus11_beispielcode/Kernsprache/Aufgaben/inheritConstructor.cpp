class Base{
public:
  Base(int){};
};

class DerivePublic: public Base{
public:
 using Base::Base;
};

class DeriveProtected: protected Base{
public:
  using Base::Base;
};

class DerivePrivate: private Base{
public:
  using Base::Base;
};

int main(){
  Base(1);
  DerivePublic(1);
  DeriveProteced(1);
  DerivePrivate(1);

}
