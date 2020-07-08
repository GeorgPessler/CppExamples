
// replace #include <boost/tr1/regex.hpp> with
//         #include <regex>
// and
// std::tr1:: with std:: in the source code

#include <boost/tr1/regex.hpp>

#include <iostream>
#include <string>

int main(){

  std::cout << std::endl;

  std::string theQuestion="C++ or c++, that's the question.";

  // regular expression for c++
  std::string regExprStr(R"(c\+\+)");
  // std::string regExprStr("c\\+\\+");

  // regular expression object
  std::tr1::regex rgx(regExprStr);

  // search result holder
  std::tr1::smatch smatch;

  std::cout << theQuestion << std::endl;

  // looking for a partial match (case sensitive)
  if (std::tr1::regex_search(theQuestion,smatch,rgx)){

    std::cout << std::endl;
    std::cout << "The answer is case sensitive: " << smatch[0] <<  std::endl;

  }

  // regular expression object (case insensitive)
  std::tr1::regex rgxIn(regExprStr,std::tr1::regex::ECMAScript|std::tr1::regex::icase);

  // looking for a partial match (case sensitive)
  if (std::tr1::regex_search(theQuestion,smatch,rgxIn)){

    std::cout << std::endl;
    std::cout << "The answer is case insensitive: " << smatch[0] << std::endl;

  }

  std::cout << std::endl;

}
