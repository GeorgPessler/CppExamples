#include <functional>
#include <iostream>
#include <string>

class CreateClosure{
public:
  void setName(const std::string& n){
    name=n;
  }
  std::function< std::string() > getIt(){
    return [this]{ return name;};
  }
private:
  std::string name;
};

int main(){

  std::cout << std::endl;

  CreateClosure creatClos;

  creatClos.setName("first");
  auto first= creatClos.getIt();
  std::cout << "first(): " << first() << std::endl;

  creatClos.setName("second");
  std::cout << "createClos.getIt()(): " << creatClos.getIt()() << std::endl;

  std::cout << std::endl;

}
