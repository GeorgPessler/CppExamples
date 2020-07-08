#include <iostream>
#include <ostream>

namespace Distance{
  class MyDistance{
    private:
      double cm;
    public:
      MyDistance(double i):cm(i){}

      friend MyDistance operator +(const MyDistance& a, const MyDistance& b){
        return MyDistance(a.cm + b.cm);
      }
      friend MyDistance operator -(const MyDistance& a,const MyDistance& b){
        return MyDistance(a.cm - b.cm);
      }

      friend std::ostream& operator<< (std::ostream &out, const MyDistance& myDist){
        out << myDist.cm << " cm";
         return out;
      }
  };

  namespace Unit{
    MyDistance operator "" _km(long double d){
      return MyDistance(100000*d);
    }
    MyDistance operator "" _m(long double m){
      return MyDistance(100*m);
    }
    MyDistance operator "" _dm(long double d){
      return MyDistance(10*d);
    }
    MyDistance operator "" _cm(long double c){
      return MyDistance(c);
    }
  }
}

using namespace Distance::Unit;

int main(){

  std:: cout << std::endl;

  std::cout << "1.0_km: " << 1.0_km << std::endl;
  std::cout << "1.0_m: " << 1.0_m << std::endl;
  std::cout << "1.0_dm: " << 1.0_dm << std::endl;
  std::cout << "1.0_cm: " << 1.0_cm << std::endl;

  std::cout << std::endl;
  std::cout << "1.0_km + 2.0_dm +  3.0_dm + 4.0_cm: " << 1.0_km + 2.0_dm +  3.0_dm + 4.0_cm << std::endl;
  std::cout << std::endl;

  Distance::MyDistance myDistance= 10345.5_dm + 123.45_km - 1200.0_m + 150000.0_cm;

  std::cout << "0345.5_dm + 123.45_km - 1200.0_m + 150000.0_cm: " << myDistance;

  std::cout << "\n\n";

}
