#include <iostream>
#include <vector>

void ForEach(const std::vector<int>& values, void(*func)(const int)){
    for(int value : values){
        func(value);
    }
}

int main(){
    std::vector<int> values = {1,5,3,6,2,4};
    ForEach(values, [](int value){std::cout << "Value: " << value << std::endl;});
    std::cin.get();
}