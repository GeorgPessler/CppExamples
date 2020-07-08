#include <iostream>
#include <memory>

int main(){

  std::cout << std::endl;

  std::shared_ptr<int> sharedPtr(new int(5));

  std::cout << "sharedPtr.use_count(): " << sharedPtr.use_count() << std::endl;

  // block scope
  {
    std::shared_ptr<int> localSharedPtr(sharedPtr);

    std::cout << "localSharedPtr.use_count(): " << localSharedPtr.use_count() << std::endl;

  }
  std::cout << "sharedPtr.use_count(): "<<  sharedPtr.use_count() << std::endl;

  std::weak_ptr<int> weakPtr(sharedPtr);
  std::cout << "sharedPtr.use_count(): " << sharedPtr.use_count() << std::endl;

  // if block scope
  if(std::shared_ptr<int> localSharedPtr = weakPtr.lock()){

    std::cout << "localSharedPtr.use_count(): " << localSharedPtr.use_count() << std::endl;
  }

  std::cout << "sharedPtr.use_count(): "<<  sharedPtr.use_count() << std::endl;

  std::cout << std::endl;

};
