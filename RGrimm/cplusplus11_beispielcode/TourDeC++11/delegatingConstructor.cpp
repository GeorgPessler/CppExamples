#include <cmath>
#include <iostream>

class MyHour{
  int myHour_;
  public:

    // constructor validating the data
    MyHour(int hour){
      if (0 <=hour and (hour<=23)) myHour_= hour;
      else myHour_=0;
      std::cout << "hour= " << hour << std::endl;
    }

    // default constructor for setting hour to 0
    MyHour(): MyHour(0){};

    // accept also doubles
    MyHour(double hour):MyHour( static_cast<int>(ceil(hour))) {};

};

int main(){

  std::cout << std::endl;

  // use the validating constructor
  MyHour(10);           // hour= 10

  // use the validating constructor
  MyHour(100);          // hour= 0

  // use the default constructor
  MyHour();             // hour= 0

  // use the constructor accepting doubles
  MyHour(22.45);        // hour= 23

  std::cout << std::endl;

}

