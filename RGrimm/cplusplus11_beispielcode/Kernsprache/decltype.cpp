#include <vector>

int func(int){ return 1; }

int main(){

  auto i= 5;                                  // int
  decltype(i) iD= i;                          // int

  auto& intRef=i;                             // int&
  decltype(intRef) intRefD= intRef;           // int&

  auto* intPoint= &i;                         // int*
  decltype(intPoint) intPointD= intPoint;     // int*

  const auto constInt= i;                     // const int
  decltype(constInt) constIntD= constInt;     // const int

  volatile auto volInt=i;                     // volatile int
  decltype(volInt) volIntD= volInt;           // volatile int

  static auto staticInt= 10;                  // static int
  decltype(staticInt) staticIntD= staticInt;  // static int

  const std::vector<int> myVec;

  auto vec = myVec;                           // std::vector<int>
  decltype(vec) vecD= vec;                    // const std::vector<int>&

  auto& vecRef = vec;                         // const std::vector<int>&
  decltype(vecRef) vecRefD= vecRef;           // const std::vector<int>&

  int myData[10];

  auto v1 = myData;                           // int*
  decltype(v1) v1D= v1;                       // int (&)[10]

  auto& v2 = myData;                          // int (&)[10]
  decltype(v2) v2D= v2;                       // int (&)[10]

  auto myFunc= func;                          // func*
  decltype(myFunc) myFuncD= myFunc;           // (int)(*)(int)

  auto& myFuncRef= func;                      // (int)(*)(int)
  decltype(myFuncRef) myFuncRefD= myFuncRef;  // (int)(*)(int)

}

