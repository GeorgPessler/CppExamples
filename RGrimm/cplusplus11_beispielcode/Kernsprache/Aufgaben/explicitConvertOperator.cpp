struct MyBool{
  explicit operator bool(){return true;}
};

int main(){
  MyBool myB;

  if (myB){};
  int a= (myB)? 3: 4;
  int b= static_cast<int>(myB) + a;

}
