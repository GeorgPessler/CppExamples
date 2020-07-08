#include <iostream>
#include <string>
#include <tuple>
#include <typeinfo>

class MyInt{
public:
  MyInt(int i): val(i){}
  int getVal() const{
    return val;
  }
private:
  int val;
};

bool operator < (const MyInt& l, const MyInt& r){
  return l.getVal() < r.getVal();
}

std::ostream& operator << (std::ostream& strm, const MyInt& myIn){
  strm << "MyInt(" << myIn.getVal() << ")";
  return strm;
}


int main(){

  std::cout << std::endl;

  std::cout << std::boolalpha;

  // creating tuples
  std::tuple<int,double> tup0;
  std::pair<int,int> pair(2011,2011.5);
  tup0= pair;
  std::tuple<std::string,int,float> tup1("tup1",3,4.17);
  std::tuple<std::string,int,double> tup2("tup2",4,1.1);

  // print the values
  std::cout << "tup1: "  << std::get<0>(tup1) << "," << std::get<1>(tup1) << "," << std::get<2>(tup1) << std::endl;
  std::cout << "tup2: "  << std::get<0>(tup2) << "," << std::get<1>(tup2) << "," << std::get<2>(tup2) << std::endl;

  // compare them
  std::cout << "tup1 < tup2: " << (tup1 < tup2) << std::endl;

  std::cout << std::endl;

  // modify a tuple value
  std::get<0>(tup2)= "Tup2";

  // print the values
  std::cout << "tup1: "  << std::get<0>(tup1) << "," << std::get<1>(tup1) << "," << std::get<2>(tup1) << std::endl;
  std::cout << "tup2: "  << std::get<0>(tup2) << "," << std::get<1>(tup2) << "," << std::get<2>(tup2) << std::endl;

  // compare them
  std::cout << "tup1 < tup2: " << (tup1 < tup2) << std::endl;

  std::cout << std::endl;

  // use MyInt
  std::tuple<MyInt,int> tup3(MyInt(1),2011);
  std::tuple<MyInt,int> tup4(MyInt(0),2011);

  // print the values
  std::cout << "tup3: "  << std::get<0>(tup3) << "," << std::get<1>(tup3) << std::endl;
  std::cout << "tup4: "  << std::get<0>(tup4) << "," << std::get<1>(tup4) << std::endl;

  std::cout << "tup3 < tup4: " << (tup3 < tup4) << std::endl;

  std::cout << std::endl;

  // modify a tuple value
  std::get<0>(tup4)= MyInt(2011);

  // print the values
  std::cout << "tup3: "  << std::get<0>(tup3) << "," << std::get<1>(tup3) << std::endl;
  std::cout << "tup4: "  << std::get<0>(tup4) << "," << std::get<1>(tup4) << std::endl;

  std::cout << "tup3 < tup4: " << (tup3 < tup4) << std::endl;

  std::cout << std::endl;

}
