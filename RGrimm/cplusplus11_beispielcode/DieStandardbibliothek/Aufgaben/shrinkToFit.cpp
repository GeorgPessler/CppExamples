#include <iostream>
#include <vector>

int main(){
  std::vector<int> myVec;
  myVec.push_back(1);
  myVec.push_back(2);
  std::cout << "myVec.capacity(): " << myVec.capacity() << std::endl;
  std::cout << "myVec.size(): " << myVec.size() << std::endl;

  std::cout << std::endl;

  myVec.reserve(100);

  std::cout << "myVec.capacity(): " << myVec.capacity() << std::endl;
  std::cout << "myVec.size(): " << myVec.size() << std::endl;

  std::cout << std::endl;

  myVec.shrink_to_fit();

  std::cout << "myVec.capacity(): " << myVec.capacity() << std::endl;
  std::cout << "myVec.size(): " << myVec.size() << std::endl;

}
