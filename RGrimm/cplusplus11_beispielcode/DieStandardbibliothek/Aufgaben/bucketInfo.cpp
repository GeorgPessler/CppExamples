#include <iostream>
#include <string>
#include <unordered_map>

int main(){

  std::unordered_map<std::string,int> myDict{{{"one",1},{"two",2},{"three",3},{"four",4},{"five",5}}};

  auto numBuck = myDict.bucket_count();
  std::cout << "myDict.bucket_count(): " << myDict.bucket_count() << std::endl;

  for ( std::size_t n=0; n < numBuck; ++n){
    std::cout << "myDict.bucket_size(" << n << "): " << myDict.bucket_size(n) << std::endl;
    for ( auto b= myDict.begin(n); b != myDict.end(n); ++b){
        std::cout << "(" << b->first << "," << b->second << ")"  << std::endl;
    }
  }

}
