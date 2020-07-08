#include <iostream>
#include <type_traits>

template <typename T>
struct RemoveConst
{
    typedef T type;
};

template <typename T>
struct RemoveConst< const T>
{
    typedef T type;
};


template <typename T>
void checkConst()
{
    if (std::is_const<T>::value == true  ) {
        std::cout << "const " << std::endl;
    }
    else {
        std::cout << "not const" << std::endl;
    }
}

int main(){

  std::cout << "int : "; checkConst<int>();
  std::cout << "const int: "; checkConst<const int>();
  std::cout << "RemoveConst<int>::type > "; checkConst< RemoveConst<int>::type >();
  std::cout << "RemoveConst<const int>::type > : "; checkConst< RemoveConst<const int>::type >();
  typedef RemoveConst<const int>::type NotConstFromConstInt;
  std::cout << "NotConstFromConstInt : "; checkConst< NotConstFromConstInt >();
  NotConstFromConstInt i= 10;

}

