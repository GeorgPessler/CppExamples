#include <iostream>
#include <map>
#include <unordered_map>

int main(){

  std::cout << std::endl;

  // using the C++ map
  std::map<std::string,int> m { {"Dijkstra",1972},{"Scott",1976},{"Wilkes",1967},{"Hamming",1968} };
  m["Ritchie"] = 1983;
  for(auto p : m) std::cout << '{' << p.first << ',' << p.second << '}';

  std::cout << std::endl;

  // using the C++0x unordered_map
  std::unordered_map<std::string,int> um { {"Dijkstra",1972},{"Scott",1976},{"Wilkes",1967},{"Hamming",1968} };
  um["Ritchie"] = 1983;
  for(auto p : um) std::cout << '{' << p.first << ',' << p.second << '}';

  std::cout << std::endl;

  std::cout << std::endl;
}
