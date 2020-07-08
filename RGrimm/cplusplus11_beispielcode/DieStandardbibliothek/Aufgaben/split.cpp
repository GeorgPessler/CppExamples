#include <regex>

#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> split(std::string input,const std::string& sep){

  std::regex regBookNeg(sep);
  std::sregex_token_iterator tokenIteratorBegin(input.begin(),input.end(),regBookNeg,-1);

  const std::sregex_token_iterator tokenIteratorEnd;
  std::vector<std::string> myStrings;
  while ( tokenIteratorBegin != tokenIteratorEnd){
    myStrings.push_back(*tokenIteratorBegin++);
  }

  return myStrings;
}

int main(){

  std::cout << std::endl;

  for ( auto s: split("Only for testing purpose."," ") ) std::cout << s << " ";

  std::cout << std::endl;

  for ( auto s: split("Split:me:at:the:colon.",":") ) std::cout << s << " ";

  std::cout << std::endl;

  for ( auto s: split("/home/rainer/workspace/C++0xBook","/") ) std::cout << s << " ";

  std::cout << "\n\n";

}
