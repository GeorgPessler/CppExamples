class TypeOnHeap{
  public:
    ~TypeOnHeap()= delete;
};

struct OnlyInt{
  OnlyInt(int){}

  template<typename T>
  OnlyInt(T) = delete;

};

int main(){

  TypeOnHeap* toH= new TypeOnHeap;
  OnlyInt onlyInt(5);

  TypeOnHeap();
  static TypeOnHeap th;

  OnlyInt(5L);
  OnlyInt(5LL);
  OnlyInt(5UL);
  OnlyInt(5.5);
}
