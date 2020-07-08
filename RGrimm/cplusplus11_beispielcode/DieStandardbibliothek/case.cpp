#include <regex>

#include <iostream>
#include <string>

int main(){

  std::cout << std::endl;

  std::string theQuestion="C++ or c++, that's the question.";

  // regular expression for c++
  std::string regExprStr(R"(c\+\+)");
  // std::string regExprStr("c\\+\\+");

  // regular expression object
  std::regex rgx(regExprStr);

  // search result holder
  std::smatch smatch;

  std::cout << theQuestion << std::endl;

  // looking for a partial match (case sensitive)
  if (std::regex_search(theQuestion,smatch,rgx)){

    std::cout << std::endl;
    std::cout << "The answer is case sensitive: " << smatch[0] <<  std::endl;

  }

  // regular expression object (case insensitive)
  std::regex rgxIn(regExprStr,std::regex_constants::ECMAScript|std::regex_constants::icase);

  // looking for a partial match (case sensitive)
  if (std::regex_search(theQuestion,smatch,rgxIn)){

    std::cout << std::endl;
    std::cout << "The answer is case insensitive: " << smatch[0] << std::endl;

  }

  std::cout << std::endl;

}
