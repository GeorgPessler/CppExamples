#include <iostream>
#include <stdexcept>
#include <string>

void printf_(const char *s){
  while (*s) {
    if (*s == '%' && *(++s) != '%')
      throw std::runtime_error("invalid format string: missing arguments");
      std::cout << *s++;
  }
}

template<typename T, typename... Args>
void printf_(const char *s, T value, Args... args){
  while (*s) {
    if (*s == '%' && *(++s) != '%') {
      std::cout << value;
      ++s;
      printf_(s, args...); // call even when *s == 0 to detect extra arguments
      return;
    }
    std::cout << *s++;
  }
  throw std::logic_error("extra arguments provided to printf");
}


int main() {

  std::cout << std::endl;

  const char* m = "The value of %s is about %g.\n";
  printf_(m,"pi", 3.14159);
  printf(m,"pi", 3.14159);

  /*
  printf_("A string: %s");
  */
  printf("A string: %s");

  std::cout << std::endl;

}

