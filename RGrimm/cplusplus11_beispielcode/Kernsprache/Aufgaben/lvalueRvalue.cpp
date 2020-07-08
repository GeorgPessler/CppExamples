#include <string>
#include <vector>

int three= 3;
int&  getThree(){return three;}

int main(){
  int n;
  std::vector<char> myVec(10);
  n= 5;
  myVec[0]= 'a';
  int a=1,b=2, c=3;
  a= b + c;
  std::string z= std::string("z");
  int* p = new int;
  getThree()= 10;
  int si= myVec.size();
}

