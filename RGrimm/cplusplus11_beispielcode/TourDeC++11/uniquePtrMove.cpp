#include <memory>

int main(){

  std::unique_ptr<int> unique1(new int(5));

  // explicit transfer of ownership
  std::unique_ptr<int> unique2(std::move(unique1));

}
