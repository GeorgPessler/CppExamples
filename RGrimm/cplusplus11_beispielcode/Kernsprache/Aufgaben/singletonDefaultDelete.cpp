class MySingleton{
public:
  static MySingleton& getInstance(){
    static MySingleton singleton;
    return singleton;
  }
private:
  MySingleton();
  ~MySingleton();
  MySingleton(const MySingleton&)= delete;
  MySingleton& operator=(const MySingleton&)= delete;
};

MySingleton::MySingleton()= default;
MySingleton::~MySingleton()= default;

int main(){

  MySingleton::getInstance();

}

