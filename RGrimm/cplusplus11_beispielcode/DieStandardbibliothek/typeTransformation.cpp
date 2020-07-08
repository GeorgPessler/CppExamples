#include <iostream>
#include <type_traits>

using namespace std;

int main(){

  cout << endl;

  cout << boolalpha;

  // basic invocations
  cout << "is_const<int>::value: " << is_const<int>::value << endl;
  cout << "is_const<const int>::value: " << is_const<const int>::value << endl;

  cout << endl;

  // add const to int
  cout << "is_const<add_const<int>::type>::value: " <<  is_const<add_const<int>::type>::value << endl;

  cout << endl;

  // declare new types
  typedef add_const<int>::type myConstInt;
  cout << "is_const<myConstInt>::value: " << is_const<myConstInt>::value << endl;
  typedef const int myConstInt2;
  cout << "is_same<myConstInt,myConstInt2>::value: " << is_same<myConstInt,myConstInt2>::value << endl;

  cout << endl;

  // recursive invocation
  cout << "is_same<int,remove_const<add_const<int>::type>::type>::value: " << is_same<int,remove_const<add_const<int>::type>::type>::value << endl;
  cout << "is_same<const int, add_const<add_const<int>::type>::type>::value: " << is_same<const int,add_const<add_const<int>::type>::type>::value << endl;

  cout << endl;

}
