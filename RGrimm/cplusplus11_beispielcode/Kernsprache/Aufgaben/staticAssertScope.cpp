static_assert(1 == 0,"1 == 0");

namespace namespaceScope{
  static_assert(1 == 0,"1 == 0");
}

void functionScope(){
  static_assert(1 == 0,"1 == 0");
}

class ClassScope{
  static_assert(1 == 0,"1 == 0");
};

int main(){
  // BlockScope
  {
    static_assert(1 == 0,"1 == 0");
  }
}
