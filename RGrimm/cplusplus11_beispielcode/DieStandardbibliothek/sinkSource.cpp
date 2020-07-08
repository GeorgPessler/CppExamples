#include <memory>
#include <iostream>

struct BigData{
  BigData(int i):mySize(i),myData(new int[i]){}
  int mySize;
  int* myData;
  ~BigData(){
    std::cout << "deleting BigData of size: " << mySize <<  std::endl;
    delete [] myData;
  }
};

// allocate an array of size BigData
std::unique_ptr<BigData> source(int size)
{
 return std::unique_ptr<BigData>(new BigData(size) );
}

// get an array of BigData
void sink(std::unique_ptr<BigData> bd){
  std::cout << "get an array of size: " << bd->mySize << std::endl;
}

void dontUseBigData(){
  source(1000);
}

int main(){

  std::cout << std::endl;

  source(123456789);

  std::cout << std::endl;

  sink(source(100000000));

  std::cout << std::endl;

  dontUseBigData();

  std::cout << std::endl;

  sink( std::unique_ptr<BigData>( new BigData(2011)));

  std::cout << std::endl;

}
