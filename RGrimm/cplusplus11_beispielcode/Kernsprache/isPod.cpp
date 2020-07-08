#include <iostream>
#include <type_traits>


struct Pod {
    int a;
};

struct NotPod {
  int a;
  NotPod() : a(0) {}
  virtual int getA(){ return a;}
};



int main(){

    std::cout << std::endl;

    // Pod remains POD in C++11
    Pod pod;
    pod.a=10;

    // still not Pod
    NotPod notPod();

    const bool isPodPod= std::is_pod<Pod>::value == true;
    const bool isPodNotPod= std::is_pod<NotPod>::value == true;

    std::cout << std::boolalpha;
    std::cout << "Pod is Pod: " << isPodPod << std::endl;
    std::cout << "NotPod is Pod: " << isPodNotPod << std::endl;

    std::cout << std::endl;

}

