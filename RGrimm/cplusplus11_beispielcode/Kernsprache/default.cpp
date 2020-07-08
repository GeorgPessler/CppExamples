#include <algorithm>
class MoveOnly {

  int data;
  public:
    MoveOnly()= default;

    MoveOnly(const MoveOnly&) = delete;

    MoveOnly(MoveOnly&& other): data(std::move(other.data)) {}

    MoveOnly& operator=(const MoveOnly&) = delete;

    MoveOnly& operator=(MoveOnly&& other) {
        data=std::move(other.data);
        return *this;
    }
};

int main(){

  // OK  because of move-semantic
  MoveOnly m1;
  MoveOnly m2(std::move(m1));

  // ERROR because of copy-semantic
  MoveOnly m3;
  MoveOnly m4(m3);

}

