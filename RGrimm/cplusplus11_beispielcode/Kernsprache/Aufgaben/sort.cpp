#include <iostream>

class Sort{
public:
  virtual void processData() final {
    readData();
    sortData();
    writeData();
  }
private:
  virtual void readData(){}
  virtual void sortData()= 0;
  virtual void writeData(){}
};


class QuickSort: public Sort{
private:
  void readData() override {
    std::cout << "readData" << std::endl;
  }
  void sortData() override {
    std::cout <<  "sortData" << std::endl;
  }
  void writeData() override {
    std::cout << "writeData" << std::endl;
  }
};


int main(){

  QuickSort* quickSort= new QuickSort;
  quickSort->processData();

}

