
// replace #include <boost/tr1/regex.hpp> with
//         #include <regex>
// and
// std::tr1:: with std:: in the source code

#include <boost/tr1/regex.hpp>

#include <iostream>
#include <string>
#include <unordered_map>

int main(){

  std::cout << std::endl;

  // Bjarne Stroustrup about C++0x on http://www2.research.att.com/~bs/C++0xFAQ.html
  std::string text{"That's a (to me) amazingly frequent question. It may be the most frequently asked question. Surprisingly, C++0x feels like a new language: The pieces just fit together better than they used to and I find a higher-level style of programming more natural than before and as efficient as ever."};

  // regular expression for a word
  std::tr1::regex wordReg(R"(\w+)");

  // get all words from text
  std::tr1::sregex_iterator wordItBegin(text.begin(),text.end(),wordReg);
  const std::tr1::sregex_iterator wordItEnd;

  // use unordered_map to count the wourds
  std::unordered_map<std::string, std::size_t> allWords;

  // count the words
  for (; wordItBegin != wordItEnd;++wordItBegin){
    ++allWords[wordItBegin->str()];
  }

  for ( auto wordIt: allWords) std::cout << "(" << wordIt.first << ":" << wordIt.second << ")" ;

  std::cout << "\n\n";

}
