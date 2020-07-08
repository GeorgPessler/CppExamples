#include <iostream>

struct Base{
  void showMe(){std::cout << "Base" << std::endl;};
  //virtual void showMe(){std::cout << "Base" << std::endl;};
};

struct DerLeft: Base{
  void showMe(){std::cout << "DerLeft" << std::endl;};
  // void showMe()= delete;
};

struct DerDerLeft: DerLeft{
  void showMe(){std::cout << "DerDerLeft" << std::endl;};
};


struct DerDerDerLeft: DerDerLeft{
  void showMe(){std::cout << "DerDerDerLeft" << std::endl;};
  // void showMe()= delete
};

struct DerRight: Base{
  void showMe(){std::cout << "DerRight" << std::endl;};
};

struct DerRightRight: DerRight{
  void showMe(){std::cout << "DerRightRight" << std::endl;};
  //void showMe()= delete;
};

int main(){

  Base* base= new Base;
  DerLeft* derLeft= new DerLeft;
  DerDerLeft* derDerLeft= new DerDerLeft;
  DerDerDerLeft* derDerDerLeft= new DerDerDerLeft;
  DerRight* derRight= new DerRight;
  DerRightRight* derDerRight= new DerRightRight;

  base->showMe();
  derLeft->showMe();
  derDerLeft->showMe();
  derDerDerLeft->showMe();
  derRight->showMe();
  derDerRight->showMe();

}
