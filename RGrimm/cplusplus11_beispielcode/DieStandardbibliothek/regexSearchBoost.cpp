
// replace #include <boost/tr1/regex.hpp> with
//         #include <regex>
// and
// std::tr1:: with std:: in the source code

#include <boost/tr1/regex.hpp>

#include <iostream>
#include <string>

int main(){

  std::cout << std::endl;

  // regular expression holder for time
  std::tr1::regex crgx("([01]?[0-9]|2[0-3]):[0-5][0-9]");

  // const char*
  std::cout << "const char*" << std::endl;
  std::tr1::cmatch cmatch;

  const char* ctime{"Now it is 23:10."};

  if (std::tr1::regex_search(ctime,cmatch,crgx)){

     std::cout << ctime << std::endl;
     std::cout << "Time: " << cmatch[0] << std::endl;

   }

  std::cout << std::endl;

  // std::string
  std::cout << "std::string" << std::endl;
  std::tr1::smatch smatch;

  std::string stime{"Now it is 23:25."};
  if (std::tr1::regex_search(stime,smatch,crgx)){

    std::cout << stime << std::endl;
    std::cout << "Time: " << smatch[0] << std::endl;

  }

  std::cout << std::endl;

  // regular expression holder for time
  std::tr1::wregex wrgx(L"([01]?[0-9]|2[0-3]):[0-5][0-9]");

  // const wchar_t
  std::cout << "const wchar_t* " << std::endl;
  std::tr1::wcmatch wcmatch;

  const wchar_t* wctime{L"Now it is 23:47."};

  if (std::tr1::regex_search(wctime,wcmatch,wrgx)){

       std::wcout << wctime << std::endl;
       std::wcout << "Time: " << wcmatch[0] << std::endl;

  }

  std::cout << std::endl;

  // std::wstring
  std::cout << "std::wstring" << std::endl;
  std::tr1::wsmatch wsmatch;

  std::wstring  wstime{L"Now it is 00:03."};

  if (std::tr1::regex_search(wstime,wsmatch,wrgx)){

    std::wcout << wstime << std::endl;
    std::wcout << "Time: " << wsmatch[0] << std::endl;

  }

  std::cout << std::endl;

}
