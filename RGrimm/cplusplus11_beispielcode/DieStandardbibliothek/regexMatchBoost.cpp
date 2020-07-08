
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

  // regular expression for a number, not including an exponent
  std::string numberRegEx(R"([-+]?([0-9]*\.[0-9]+|[0-9]+))");

  // regular expression holder
  std::tr1::regex rgx(numberRegEx);

  // using const char*
  const char* numChar{"2011"};
  if (std::tr1::regex_match(numChar,rgx)){
    std::cout << numChar << " is a number." << std::endl;
  }

  // using std::string
  const std::string numStr{"3.14159265359"};
  if (std::tr1::regex_match(numStr,rgx)){
    std::cout << numStr << " is a number." << std::endl;
  }

  // using bidirectional iterators
  const std::vector<char> numVec{{'-','2','.','7','1','8','2','8','1','8','2','8'}};
  if (std::tr1::regex_match(numVec.begin(),numVec.end(),rgx)){
    for (auto c: numVec){ std::cout << c ;};
    std::cout << " is a number." << std::endl;
  }

  std::cout << std::endl;

}
