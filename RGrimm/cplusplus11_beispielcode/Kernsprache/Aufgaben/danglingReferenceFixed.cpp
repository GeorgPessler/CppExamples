#include <functional>
#include <iostream>

std::function<std::string()> makeLambda1() {
    const std::string val="very good 1";
    return [val]{ return val;};
}

std::function<std::string()> makeLambda2() {
    return []{ return "very good 2";};
}

const std::string  good3={"very good 3"};

std::function<std::string()> makeLambda3() {
    return []{ return good3;};
}

std::function<std::string()> makeLambda4(const std::string& val) {
    return [val]{ return val;};
}

std::function<std::string(const std::string& )> makeLambda5() {
    return [](const std::string& val){ return val;};
}



int main(){

  std::cout << std::endl;

  auto good1= makeLambda1();
  std::cout << good1() << std::endl;

  auto good2= makeLambda2();
  std::cout << good2() << std::endl;

  auto good3= makeLambda3();
  std::cout << good3() << std::endl;

  auto good4= makeLambda4("very good 4");
  std::cout << good4() << std::endl;

  auto good5= makeLambda5();
  std::cout << good5("very good 5") << std::endl;

  std::cout << std::endl;

}
