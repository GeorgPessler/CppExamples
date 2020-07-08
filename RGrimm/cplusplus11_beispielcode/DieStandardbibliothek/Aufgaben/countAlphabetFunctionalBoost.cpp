
// replace #include <boost/tr1/regex.hpp> with
//         #include <regex>
// and
// std::tr1:: with std:: in the source code

#include <algorithm>
#include <ctype.h>
#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>

struct CountChar{
  void operator()(char a){
    if (isalpha(a)) ++allchars[tolower(a)];
  }
  std::unordered_map<char, std::size_t> allchars;
};

int main(){

  std::cout << std::endl;

  // Bjarne Stroustrup about C++0x on http://www2.research.att.com/~bs/C++0xFAQ.html
  std::string text("That's a (to me) amazingly frequent question. It may be the most frequently asked question. Surprisingly, C++0x feels like a new language: The pieces just fit together better than they used to and I find a higher-level style of programming more natural than before and as efficient as ever.");

  auto dict= std::for_each(text.begin(),text.end(),CountChar());

  std::map<int,std::vector<char>> charOccurrence;

  for ( auto charIt= dict.allchars.begin(); charIt != dict.allchars.end(); ++charIt){
    charOccurrence[charIt->second].push_back(charIt->first);
  }

  for ( auto pair= charOccurrence.begin(); pair != charOccurrence.end(); ++pair){
    std::cout << pair->first << ": (";
    for (auto eIt= charOccurrence[pair->first].begin(); eIt != charOccurrence[pair->first].end(); ++eIt ) std::cout << *eIt << " ";
    std::cout << ")" << std::endl;

  }

  std::cout << std::endl;

}

