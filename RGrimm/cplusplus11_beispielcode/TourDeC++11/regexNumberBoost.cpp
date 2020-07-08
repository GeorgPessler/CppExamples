
// replace #include <boost/tr1/regex.hpp> with
//         #include <regex>
// and
// std::tr1:: with std:: in the source code

#include <boost/tr1/regex.hpp>

#include <iostream>
#include <string>

int main(){

  std::cout << std::endl;

  std::string text="abc1234def567";

  std::string regExprStr(R"(\d+)");

  // regular expression holder
  std::tr1::regex rgx(regExprStr);

  // looking for a total match
  if (std::tr1::regex_match(std::string("1234"),rgx))
    std::cout << regExprStr << " match 1234" << '\n';

  // search result holder
  std::tr1::smatch smatch;
  // looking for a partial match
  if (std::tr1::regex_search(text,smatch,rgx))
    std::cout << "The first match of " << regExprStr << " after " << smatch.prefix() << " in " << text <<  '\n';

  // replace the match
  std::string result;
  std::string replString{"ABC"};
  std::tr1::regex_replace(back_inserter(result),text.begin(),text.end(),rgx,replString);
  std::cout << "replace " << regExprStr << " in " << text << " with " << replString << ": " << result  << std::endl;

  std::cout << std::endl;

}
