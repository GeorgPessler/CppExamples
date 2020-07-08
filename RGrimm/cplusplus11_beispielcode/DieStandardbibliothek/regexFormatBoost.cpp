
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

  std::string future{"Future"};
  int len= sizeof(future);

  const std::string unofficial{"unofficial,C++0x"};
  const std::string official{"official,C++11"};

  std::tr1::regex regValues{"(.*),(.*)"};


  std::string standardText{"The $1 name of the new C++ standard is $2."};

  // using std::regex_replace
  std::string textNow= std::tr1::regex_replace(unofficial,regValues,standardText );

  std::cout <<  std::setw(len) << std::left << "Now: " << textNow << std::endl;

  // using std::match_results
  // typedef match_results<string::const_iterator> smatch;
  std::tr1::smatch smatch;
  if ( std::tr1::regex_match(official,smatch,regValues)){

    std::string textFuture= smatch.format(standardText);
    std::cout <<  std::setw(len) << std::left << "Future: " << textFuture << std::endl;

  }

  std::cout << std::endl;

}
