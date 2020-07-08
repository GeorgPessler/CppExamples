// replace #include <boost/tr1/regex.hpp> with
//         #include <regex>
// and
// std::tr1:: with std:: in the source code

#include <boost/tr1/regex.hpp>
//#include <regex>

#include <iostream>
#include <iterator>
#include <string>
#include <vector>


int main(){

  std::cout << std::endl;

  // regular expression holder for number
  std::tr1::regex crgx(R"(\d+)");

  // std::string
  std::tr1::smatch smatch;

  std::string inputText("This is close to the final draft international standard formally accepted by a 21-0 national vote in August 2011. Unless the ISO bureaucracy is unusually slow, the standard will be officially issued this year so that it will be referred to as C++11 or C++2011.");

  std::string myResult;
  std::string replace("$& ");
  std::tr1::regex_replace(std::back_inserter(myResult),
      inputText.begin(),inputText.end(),crgx,replace,std::tr1::regex_constants::format_no_copy);

  std::cout << myResult << std::endl;

  std::cout << std::endl;

}
