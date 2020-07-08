#include <regex>

#include <iostream>
#include <string>
#include <vector>

int main(){

  std::cout << std::endl;

  // a few books
  std::string text{"Pete Becker,The C++ Standard Library Extensions,2006:Nicolai Josuttis,The C++ Standard Library,1999:Andrei Alexandrescu,Modern C++ Design,2001"};

  // regular expression for a book
  std::regex regBook(R"((\w+)\s(\w+),([\w\s\+]*),(\d{4}))");

  // get all books from text
  std::sregex_iterator bookItBegin(text.begin(),text.end(),regBook);
  const std::sregex_iterator bookItEnd;

  // iterate over each match_results
  while ( bookItBegin != bookItEnd){
    auto match= *bookItBegin++;
    // show each capture group
    for ( size_t i= 0; i < match.size(); ++i){
      std::cout << i << ": "  << match[i] << std::endl;
    }
    std::cout << std::endl;
  }

}
