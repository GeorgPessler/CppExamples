
// replace #include <boost/tr1/regex.hpp> with
//         #include <regex>
// and
// std::tr1:: with std:: in the source code

#include <boost/tr1/regex.hpp>

#include <iomanip>
#include <iostream>
#include <string>

void showCaptureGroups(const std::string& regEx, const std::string& text){

  // regular expression holder
  std::tr1::regex rgx(regEx);

  // result holder
  std::tr1::smatch smatch;

  // result evaluation
  if (std::tr1::regex_search(text,smatch,rgx)){
    std::cout << std::setw(12) << regEx << std::setw(12) << text << std::setw(12) << smatch[0]  << std::setw(10) << smatch[1] << std::setw(10) << smatch[2] << std::setw(10) << smatch[3] << std::endl;
  }

}

int main(){

  std::cout << std::endl;

  std::cout << std::setw(12) << "reg Expr" << std::setw(12) << "text" << std::setw(12) << "smatch[0]" << std::setw(10) << "smatch[1]" << std::setw(10) << "smatch[2]" << std::setw(10) << "smatch[3]" << std::endl;

  showCaptureGroups("abc+","abccccc");

  showCaptureGroups("(a+)(b+)(c+)","aaabccc");

  showCaptureGroups("(abc)+","abcabc");

  showCaptureGroups("((abc)+)","abcabc");

  showCaptureGroups("(ab)(abc)+","ababcabc");

  showCaptureGroups("(a(b))(abc)+","ababcabc");

  std::cout << std::endl;

}
