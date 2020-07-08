#include <string>
#include <iostream>
#include <type_traits>

template<typename T>
class IsClass{
  private:

    typedef char One;
    typedef struct { char a[2]; } Two;

    template<typename C> static One test(int C::*);
    template<typename C> static Two test(...);

  public:
    static const bool Yes= sizeof(IsClass<T>::test<T>(0)) == 1;
    static const bool No= (!Yes);
};

int main(){

  std::cout << std::boolalpha << std::endl;

  // use IsClass
  std::cout << "IsClass<std::string>::Yes: " << IsClass<std::string>::Yes << std::endl;
  std::cout << "IsClass<std::string>::No: " << IsClass<std::string>::No << std::endl;
  std::cout << "IsClass<int>::Yes: " << IsClass<int>::Yes << std::endl;
  std::cout << "IsClass<int>::No: " << IsClass<int>::No << std::endl;

  std::cout << std::endl;

  // the C++0x functionality
  std::cout << "std::is_class<std::string>::value: " << std::is_class<std::string>::value << std::endl;
  std::cout << "!(std::is_class<std::string>::value): " << !(std::is_class<std::string>::value) << std::endl;
  std::cout << "std::is_class<int>::value: " << std::is_class<int>::value << std::endl;
  std::cout << "!(std::is_class<int>::value): " << (!std::is_class<int>::value) << std::endl;

  std::cout << std::endl;

}
