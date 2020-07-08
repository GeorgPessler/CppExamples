#include <cctype>
#include <iostream>
#include <string>

int main(){

  std::cout << std::endl;

  // initial string
  std::string testStr{"Only for Testing Purpose."};
  for (auto c: testStr) std::cout << c;
  std::cout << std::endl;

  // each character upper
  for (auto& c: testStr) c=std::toupper(c);
  for (auto c: testStr) std::cout << c;
  std::cout << std::endl;

  // switch each character from upper to lower case and vice versa
  testStr= {"Only for Testing Purpose."};
  for (auto& c: testStr) c=std::isupper(c)? std::tolower(c): std::toupper(c);
  for (auto c: testStr) std::cout << c;
  std::cout << std::endl;

  std::cout << std::endl;

}
