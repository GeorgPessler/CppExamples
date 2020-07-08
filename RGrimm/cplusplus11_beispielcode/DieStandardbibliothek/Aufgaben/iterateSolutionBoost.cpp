
// replace #include <boost/tr1/regex.hpp> with
//         #include <regex>
// and
// std::tr1:: with std:: in the source code

#include <boost/tr1/regex.hpp>

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>

int main(){

  std::cout << std::endl;

  const char* privateAddress="192.168.178.21";

  // regular expression for IP4 adresses
  const char* ip4RegEx(R"((\d{1,3})\.(\d{1,3})\.(\d{1,3})\.(\d{1,3}))");

  // regular expression holder
  std::tr1::regex rgx(ip4RegEx);

  // search result holder
  std::tr1::cmatch cmatch;

  // looking for the exact match
  if (std::tr1::regex_match(privateAddress,cmatch,rgx)){

    for ( auto cap: cmatch ){

      std::cout << "capture group: " << cap << std::endl;
      if (cap.matched){

        // print each character in hexadecimal notation, including the base
        std::cout << "hex: ";
        std::for_each(cap.first,cap.second,[](int v){std::cout << std::showbase << std::hex << v << " ";});
        std::cout << "\n\n";

      }

    }

  }

}
