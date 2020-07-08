// replace #include <boost/tr1/regex.hpp> with
//         #include <regex>
// and
// std::tr1:: with std:: in the source code

#include <boost/tr1/regex.hpp>
//#include <regex>

#include <iostream>
#include <iterator>
#include <string>

int main(){

  std::cout << std::endl;

  // regular expression holder for number
  std::tr1::regex crgx(R"(\d+)");

  // std::string
  std::tr1::smatch smatch;

  std::string inputText("This is close to the final draft international standard formally accepted by a 21-0 national vote in August 2011. Unless the ISO bureaucracy is unusually slow, the standard will be officially issued this year so that it will be referred to as C++11 or C++2011.");

  std::string::const_iterator begin= inputText.begin();
  std::string::const_iterator end= inputText.end();

  while ( std::tr1::regex_search(begin, end, smatch,crgx)){

    std::cout << "number: " << smatch[0] << std::endl;
    begin += smatch.position() + smatch.length();

  }

  std::cout << std::endl;

}

