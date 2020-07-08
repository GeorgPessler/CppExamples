
// replace #include <boost/tr1/regex.hpp> with
//         #include <regex>
// and
// std::tr1:: with std:: in the source code

#include <boost/tr1/regex.hpp>

#include <iostream>
#include <string>
#include <vector>

int main(){

  std::cout << std::endl;

  std::vector<std::string> myStrings{"2011","3.14159","-3.44E+4","-1.02E-4"};

  // regular expression for a number, including an exponent
  std::string numberRegEx(R"([-+]?([0-9]+\.?[0-9]*|\.[0-9]+)([eE][-+]?[0-9]+)?)");

  // regular expression holder
  std::tr1::regex rgx(numberRegEx);

  for ( auto const& s: myStrings){
    // using std::string
    if (std::tr1::regex_match(s,rgx)){
      std::cout << s << " is a number." << std::endl;
    }
    else{
      std::cout << s << " is no number." << std::endl;
    }
  }

  std::cout << std::endl;

}
