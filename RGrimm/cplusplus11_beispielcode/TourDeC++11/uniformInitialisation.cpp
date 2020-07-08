#include <vector>

struct MyStruct{
  int a;
  double b;
};

class Array{
  public:
    Array(): myData{1,2,3,4,5} {}
  private:
    int myData[5];
};

int main(){

  // valid for C++
  MyStruct myStruct = {4,5.5};

  // valid for C++
  int invArray[]= {1,2,3,4,5};

  // valid for C++11
  std::vector <int> myIntVec{1,2,3,4,5};

  // valid for C++11
  Array myArray;

  // valid for C++11
  const float* pData = new const float[5]{1,2,3,4,5};

}
