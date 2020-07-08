
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

  std::string unofficialStandardName{"The unofficial name of the new C++ standard is C++0x."};
  std::cout << std::setw(len) << std::left << "Now: " << unofficialStandardName << std::endl;

  // replace C++0x with C++11
  std::tr1::regex rgxCpp(R"(C\+\+0x)");
  std::string newCppName{"C++11"};

  std::string newStandardName{std::tr1::regex_replace(unofficialStandardName,rgxCpp,newCppName)};
  std::cout << std::setw(len) << std::left <<  "Now: " << newStandardName << std::endl;

  // replace unofficial with official
  std::tr1::regex rgxOff{"unofficial"};
  std::string makeOfficial{"official"};

  std::string officialName{std::tr1::regex_replace(newStandardName,rgxOff,makeOfficial)};
  std::cout << std::setw(len) << std::left  << "Future: " << officialName << std::endl;

  std::cout << std::endl;

}
