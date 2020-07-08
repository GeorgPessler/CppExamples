#include <algorithm>
#include <cassert>
#include <iostream>
#include <list>
#include <string>
#include <vector>

template<typename InputIter>
std::string join(InputIter begin, InputIter end, std::string sep) {

  // Container must be not empty
  assert( begin != end);
  return std::accumulate(++begin,end,*begin,[sep](std::string a, std::string b){ return a + sep + b;});

}

int main(){

  std::cout << std::endl;

  std::list<std::string> myList{"Programming","in","C++11","in","a","functional","style."};

  // starting with 10
  std::vector<int> myVec(20);
  std::iota(myVec.begin(),myVec.end(),10);

  std::cout << "myVec: ";
  for (auto i: myVec) std::cout << i << " ";
  std::cout << std::endl;
  std::cout << "myList: ";
  for (auto i: myList) std::cout << i << " ";

  std::cout << "\n\n" << "std::transform" << std::endl;

  // i -> i*i
  std::transform(myVec.begin(),myVec.end(),myVec.begin(),[](int i){ return i*i; });
  std::cout << "    myVec: ";
  for (auto i: myVec) std::cout << i << " ";


  // string -> (string,string.length())
  std::vector<std::pair<std::string,int>> listLength;
  std::transform(myList.begin(),myList.end(),std::back_inserter(listLength),[](std::string s){ return std::make_pair(s,s.length());});
  std::cout << std::endl << "    ";
  for (auto i: listLength) std::cout << "(" << i.first << "," << i.second << ") ";

  std::cout << "\n\n" << "std::remove_if and std::remove_copy_if" << std::endl;

  auto it= std::remove_if(myVec.begin(),myVec.end(),[](int i){ return (i < 200) or( i > 500); });
  myVec.erase(it,myVec.end());
  std::cout << "    myVec: ";
  for (auto i: myVec) std::cout << i << " ";
  std::cout << std::endl;

  std::string myString{"Programming in C++11 in a functional style."};
  std::string lowerChars;

  // lower -> lowerChars
  std::remove_copy_if(myString.begin(),myString.end(),std::back_inserter(lowerChars),[](char c){ return std::isupper(c);});

  std::cout << "    lowerChars: " << lowerChars << std::endl;

  std::cout << "\n" << "std::accumulate" << std::endl;

  // mean of myVec
  double sum= static_cast<double>(std::accumulate(myVec.begin(),myVec.end(),0, [](int a, int b){ return a+b;}));
  std::cout << "    mean of myVec: " << sum/myVec.size() << std::endl;

  // join the strings with ":"
  std::string myListJoin= std::accumulate(myList.begin(),myList.end(),std::string(""),[](std::string a, std::string b){ return a + ":" + b;});

  std::cout << "    joined myList:" << myListJoin << std::endl;

  std::cout << std::endl;

  std::cout << join(myList.begin(),myList.end(),"#");

  std::cout << std::endl;

  std::cout << join(myList.begin(),myList.end()," => ");

  std::vector<std::string> myVec2(myList.begin(),myList.end());

  std::cout << std::endl;

  std::cout << join(myVec2.rbegin(),myVec2.rend()," <= ");

  std::cout << std::endl << std::endl;

}
