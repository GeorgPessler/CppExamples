#include <chrono>
#include <iostream>

int main(){

  std::cout << std::fixed<< std::endl;

  auto timeNow= std::chrono::system_clock::now();
  auto duration= timeNow.time_since_epoch();

  std::cout << "time since 1.1.1970:" << std::endl;
  std::cout << std::endl;

  std::cout << duration.count() << " nanoseconds" << std::endl;


  typedef std::chrono::duration<double> MySecondTick;
  MySecondTick mySecond(duration);
  std::cout << mySecond.count() << " seconds" << std::endl;

  const int minute= 60;
  typedef std::chrono::duration<double, std::ratio<minute>> MyMinuteTick;
  MyMinuteTick myMinute(duration);
  std::cout << myMinute.count() << " minutes" << std::endl;

  const int hour= minute * 60;
  typedef std::chrono::duration<double, std::ratio<hour>> MyHourTick;
  MyHourTick myHour(duration);
  std::cout << myHour.count() << " hours" << std::endl;

  const int day= hour * 24;
  typedef std::chrono::duration<double, std::ratio<day>> MyDayTick;
  MyDayTick myDay(duration);
  std::cout << myDay.count() << " days" << std::endl;

  const int month= day * 30;
  typedef std::chrono::duration<double, std::ratio<month>> MyMonthTick;
  MyMonthTick myMonth(duration);
  std::cout << myMonth.count() << " months" << std::endl;

  const int year= month * 12;
  typedef std::chrono::duration<double, std::ratio<year>> MyYearTick;
  MyYearTick myYear(duration);
  std::cout << myYear.count() << " years" << std::endl;


  /*

  typedef std::chrono::duration<double, std::ratio<3600>> MyHourTick;
  MyHourTick myHour(aSecond);
  std::cout << myHour.count() << " hours" << std::endl;

  typedef std::chrono::duration<double, std::ratio<2700>> MyLessonTick;
  MyLessonTick myLesson(aSecond);
  std::cout << myLesson.count() << " lessons" << std::endl;

  typedef std::chrono::duration<long long, std::ratio<1,2>> MyHalfASecondTick;
  MyHalfASecondTick myHalfASecond(aSecond);
  std::cout << myHalfASecond.count() << " HalfASeconds" << std::endl;

  */


  std::cout << std::endl;

}
