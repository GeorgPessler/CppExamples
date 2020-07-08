#include <iostream>

struct MyData{
  int data;
};

int main(){
  std::cout << std::endl;

  // for new
  MyData* pMD= new MyData;
  MyData mD;

  // for &
  MyData* pMD2= &mD;

  // for *
  MyData mD2= *pMD2;

  // for ->
  pMD->data=15;
  std::cout <<"Value of data= " << pMD->data << std::endl;

  // for ->*
  int MyData::*pmd = &MyData::data;
  pMD->*pmd = 20;
  std::cout <<"Value of data= " << (pMD->*pmd) << std::endl;

  // for delete
  delete pMD;

  std::cout << std::endl;
}
