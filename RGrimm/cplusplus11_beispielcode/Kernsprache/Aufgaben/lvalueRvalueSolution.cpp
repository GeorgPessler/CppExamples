#include <string>
#include <vector>

int three= 3;
int&  getThree(){ return three; }

int main(){
  int n;
  std::vector<char> myVec(10);
  // 5 is rvalue
  n= 5;
  // lvalue= rvalue
  myVec[0]= 'a';
  int a=1, b=2, c=3;
  // b + is rvalue
  a= b + c;
  // std::string("z") is rvalue
  std::string z= std::string("z");
  // new int is rvalue
  int* p= new int;
  // getThree() is lvalue; 10 is rvalue
  getThree()= 10;
  // myVec.size() is lvalue
  int si= myVec.size();
}

