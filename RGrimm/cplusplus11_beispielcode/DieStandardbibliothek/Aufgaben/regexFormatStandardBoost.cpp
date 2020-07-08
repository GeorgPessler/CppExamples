
// replace #include <boost/tr1/regex.hpp> with
//         #include <regex>
// and
// std::tr1:: with std:: in the source code

#include <boost/tr1/regex.hpp>

#include <iomanip>
#include <iostream>
#include <string>

int main(){

  std::cout << std::endl;

  const std::string year2011{"2011,11"};
  const std::string year2012{"2012,12"};

  std::tr1::regex regValues{"(.*),(.*)"};

  std::string standardText{"This is close to the final draft international standard formally accepted by a 21-0 national vote in August $1. Unless the ISO bureaucracy is unusually slow, the standard will be officially issued this year so that it will be referred to as C++$2 or C++$1. "};

  // using std::regex_replace
  std::string text2011= std::tr1::regex_replace(year2011,regValues,standardText );

  std::string text2012= std::tr1::regex_replace(year2012,regValues,standardText );

  std::cout << text2011 << std::endl;

  std::cout << std::endl;

  std::cout << text2012 << std::endl;

  std::cout << std::endl;


}
