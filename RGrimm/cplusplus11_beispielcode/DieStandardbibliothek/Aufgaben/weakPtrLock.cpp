#include <iostream>
#include <memory>

int main(){

  std::shared_ptr<int> myShared(new int);

  std::weak_ptr<int> weakPtr=myShared;

  std::shared_ptr<int> sharedPtr1;
  if(sharedPtr1 = weakPtr.lock()) {
    std::cout << "Get it: " << weakPtr.use_count() << std::endl;
  }
  else{
    std::cout << "Don't get it: " << weakPtr.use_count() << std::endl;
  }

  weakPtr.reset();

  if(std::shared_ptr<int> sharedPtr1 = weakPtr.lock()) {
    std::cout << "Get it: " << weakPtr.use_count() << std::endl;
   }
   else{
     std::cout << "Don't get it: " << weakPtr.use_count() << std::endl;
   }

}

