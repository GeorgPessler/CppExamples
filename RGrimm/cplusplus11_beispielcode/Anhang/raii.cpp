#include <iostream>
#include <string>

class ResourceGuard{
  private:
    const std::string resource;
  public:
    ResourceGuard(const std::string& res):resource(res){
      std::cout << "Acquire the " << resource << "." <<  std::endl;
    }
    ~ResourceGuard(){
      std::cout << "Release the "<< resource << "." << std::endl;
    }
};

int main(){

  std::cout << std::endl;

  // memoryBlock1 should be guarded by ResourceGuard
  ResourceGuard resGuard1{"memoryBlock1"};

  std::cout << "\nbefore scope" << std::endl;

  // resGuard2 should only be valid in following scope
  {
    // memoryBlock2 should be guarded by ResourceGuard
    ResourceGuard resGuard2{"memoryBlock2"};
  }
  std::cout << "after scope" << std::endl;

  std::cout << std::endl;

}
