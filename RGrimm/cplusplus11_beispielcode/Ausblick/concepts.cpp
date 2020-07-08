template<typename T>
const T& getMinimum(const T& l, const T& r){
  return (l<r) ? l : r;
}

class MyInt{
public:
  MyInt(int i):val(i){}
  int getVal() const {
    return val;
  }
private:
  int val;
};

int main(){

  int a=0;
  int b=1;

  int min1= getMinimum(a,b);

  MyInt c(min1);
  MyInt d(0);

  getMinimum(c,d);

}
