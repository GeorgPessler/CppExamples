#include <regex>

#include <iostream>
#include <string>

int main(){

  std::cout << std::endl;

  // regular expression
  std::regex rgx(R"(\d+)");

  std::string str="C++98 war der bis 2011 gültige C++ Standard, sieht man von seiner kleinen technischen Korrektur 2003 (C++03), formal ISO/IEC 14882:2003, ab.";

  // define the iterator range
  std::sregex_token_iterator it(str.begin(),str.end(),rgx);
  std::sregex_token_iterator end;

  // iterate over the tokens
  while (it != end) std::cout << *it++ << " ";

  std::cout << "\n\n";

}
