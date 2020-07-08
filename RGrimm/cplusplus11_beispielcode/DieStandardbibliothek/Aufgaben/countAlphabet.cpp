#include <regex>

#include <ctype.h>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>

int main(){

  std::cout << std::endl;

  // Bjarne Stroustrup about C++0x on http://www2.research.att.com/~bs/C++0xFAQ.html
  std::string text("That's a (to me) amazingly frequent question. It may be the most frequently asked question. Surprisingly, C++0x feels like a new language: The pieces just fit together better than they used to and I find a higher-level style of programming more natural than before and as efficient as ever.");

  // regular expression for a char
  std::regex charReg("[a-zA-Z]");

  // get all chars from text
  std::sregex_iterator charItBegin(text.begin(),text.end(),charReg);
  const std::sregex_iterator charItEnd;

  // use unordered_map to count the wourds
  std::unordered_map<char, std::size_t> allchars;

  // count the chars
  for (; charItBegin != charItEnd;++charItBegin){
    ++allchars[tolower(charItBegin->str()[0])];
  }

  std::map<int,std::vector<char>> charOccurrence;

  for ( auto charIt= allchars.begin(); charIt != allchars.end(); ++charIt){
    charOccurrence[charIt->second].push_back(charIt->first);
  }

  for ( auto pair= charOccurrence.begin(); pair != charOccurrence.end(); ++pair){
    std::cout << pair->first << ": (";
    for (auto eIt= charOccurrence[pair->first].begin(); eIt != charOccurrence[pair->first].end(); ++eIt ) std::cout << *eIt << " ";
    std::cout << ")" << std::endl;

  }

  std::cout << std::endl;

}

