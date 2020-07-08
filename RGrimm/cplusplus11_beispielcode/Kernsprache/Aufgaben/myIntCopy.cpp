#include <iostream>

struct MyInt{
  int val;
  MyInt(int i):val(i){
    std::cout << i << std::endl;
  }
};

MyInt operator+(const MyInt& left, const MyInt& right) {
  return MyInt(left.val+right.val);
}

MyInt operator+(MyInt&& left,MyInt&& right) {
  left.val += right.val;
  return left;
}

int main(){

  MyInt erg= MyInt(1) + MyInt(2) + MyInt(3) + MyInt(4);

  std::cout << "erg: " << erg.val << std::endl;

}
