#include <algorithm>
#include <deque>
#include <iostream>
#include <string>

int main(){

  std::cout << std::endl;
  std::deque<std::string> myDeq;
  myDeq.push_back("Only");
  myDeq.push_back("for");
  myDeq.push_back("testing");
  myDeq.push_back("purpose");
  myDeq.push_back(".");

  auto minMax= std::minmax_element(myDeq.begin(),myDeq.end());
  std::cout << "(min,max): " << "(" << *(minMax.first) <<  "," << *(minMax.second) << ")" << std::endl;

  std::cout << std::endl;

  auto minMaxLength= std::minmax_element(myDeq.begin(),myDeq.end(),[](const std::string& f, const std::string& s){ return f.length() < s.length(); });
  std::cout << "(min,max): " << "(" << *(minMaxLength.first) <<  "," << *(minMaxLength.second) << ")" << std::endl;

}
