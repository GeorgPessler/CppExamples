#include <algorithm>
#include <array>
#include <deque>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

bool even_(const int& i){
	return ( i % 2 == 0);
}

int main() {

  std::cout << std::endl;

  std::cout << std::boolalpha;

  // increase each element by 1
  std::vector<int> myVec(20);
  std::iota(myVec.begin(),myVec.end(),1);

  std::cout << "myVec:";
  for (auto i: myVec) std::cout << i << " ";
  std::cout << std::endl << std::endl;

  // test a predicate on a range
  std::cout << "one even in myVec: " << std::any_of(myVec.begin(),myVec.end(),even_) << std::endl;
  std::cout << "all even in myVec: " << std::all_of(myVec.begin(),myVec.end(),even_) << std::endl;
  std::cout << "all even in myVec with lambda: " << std::all_of(myVec.begin(),myVec.end(),[](int i){ return i % 2 == 0; }) << std::endl;
  std::cout << "none even in myVec with lambda: " << std::none_of(myVec.begin(),myVec.end(),[](int i){ return i % 2 == 0; }) << std::endl;

  std::cout << std::endl;

  // copying all odd element to std::cout
  std::cout << "all odd elements: ";
  std::copy_if(myVec.begin(), myVec.end(),std::ostream_iterator<int>(std::cout, " "),[](int a){ return a % 2;} );

  std::cout << std::endl;

  // copying the first 10 element
  std::cout << "The first 10 elements: ";
  std::copy_n(myVec.begin(),10,std::ostream_iterator<int>(std::cout, " "));

  std::cout << std::endl << std::endl;

  std::list<int> allOdd;
  std::deque<int> allEven;

  // odd ints to list allOdd
  // even ints to deque allEven
  std::partition_copy(myVec.begin(),myVec.end(),std::back_inserter(allEven),std::back_inserter(allOdd),even_);

  std::cout << "allOdd: ";
  for (auto o: allOdd) std::cout << o << " ";

  std::cout << std::endl;

  std::cout << "allEven: ";
  for (auto e: allEven) std::cout << e << " ";

  std::cout << std::endl;

  // test, if partitioned
  std::cout << "Partition a < 10: " << std::is_partitioned(myVec.begin(),myVec.end(),[](int a){ return a < 10;}) << std::endl;

  std::cout << std::endl;

  // get the partition point
  std::cout << "Partition Point for a < 10: " << *(std::partition_point(myVec.begin(),myVec.end(),[](int a){ return a < 10;})) << std::endl;

  std::cout << std::endl;

  // test, if sorted
  std::cout << "Is sorted (ascending): " << std::is_sorted(myVec.begin(),myVec.end()) << std::endl;

  std::cout << "Is sorted (descending): " << std::is_sorted(myVec.begin(),myVec.end(),[](int a, int b ){return a > b;}) << std::endl;

  myVec.push_back(-10);
  myVec.push_back(100);
  myVec.push_back(2011);

  std::cout << std::endl;

  std::cout << "myVec:";
  for (auto i: myVec) std::cout << i << " ";
  std::cout << std::endl << std::endl;

  std::cout << "Is sorted until: " << *(std::is_sorted_until(myVec.begin(),myVec.end())) << std::endl;

  std::cout << std::endl;

}
