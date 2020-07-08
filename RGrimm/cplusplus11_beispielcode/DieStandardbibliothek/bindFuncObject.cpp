#include <functional>
#include <iomanip>
#include <iostream>

class Family{
public:
  Family(const std::string& s):family(s){}

  std::string getName(const std::string& first){
    return family + ", " + first;
  }
private:
  std::string family;
};

int main(){

  std::cout << std::endl;
  int len= 23;

  // using methods
  Family grimm("Grimm");
  std::cout << std::setw(len) << std::left << "grimm.getName(Rainer): " << grimm.getName("Rainer") << std::endl;

  std::cout << std::endl;

  // using std::bind with objects
  Family mann("Mann");
  std::function<std::string(const std::string&)> mannCrea= std::bind(&Family::getName,mann,std::placeholders::_1);

  std::cout << std::setw(len) << std::left << "mannCrea(Heinrich): " << mannCrea("Heinrich") << std::endl;
  std::cout << std::setw(len) << std::left << "mannCrea(Golo): " << mannCrea("Golo") << std::endl;
  std::cout << std::setw(len) << std::left << "mannCrea(Thomas): " << mannCrea("Thomas") << std::endl;

  std::cout << std::endl;

}
