#include <algorithm>
#include <iostream>
#include <string>
#include <vector>


int main(){

  std::cout << std::endl;

  std::vector<int> vecInt={1,2,3,4,5,6,7,8,9,10};

  std::string seperator="";
  auto sepEmp= [seperator](int i){std::cout << i << seperator;};

  seperator=":";
  auto sepColon=[seperator](int i){std::cout << i << seperator;};

  seperator="-";
  auto sepHyphen=[seperator](int i){std::cout << i << seperator;};

  seperator=",";
  auto sepComma=[seperator](int i){std::cout << i << seperator;};


  std::for_each(vecInt.begin(),vecInt.end(),sepEmp);
  std::cout << std::endl;

  std::for_each(vecInt.begin(),vecInt.end(),sepColon);
  std::cout << std::endl;

  std::for_each(vecInt.begin(),vecInt.end(),sepHyphen);
  std::cout << std::endl;

  std::for_each(vecInt.begin(),vecInt.end(),sepComma);
  std::cout << std::endl;

  std::cout << std::endl;

}


