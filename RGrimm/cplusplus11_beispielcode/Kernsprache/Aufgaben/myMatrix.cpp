#include <string>

template < typename T, int Line, int Column >
struct Matrix{
   static_assert (Line >= 0, "Line number must be postive.");
   static_assert (Column >= 0, "Column number must be positive.");
   static_assert ( Line + Column > 0, "Line or Column must be greater than 0.");
};

int main() {
  Matrix<int,10,5> intArray;
  Matrix<std::string,3,4> strArray;
  Matrix<double,0,1> doubleArray;
  Matrix<long long,1,0> longArray;
  Matrix<char,0,0> charArray;
}
