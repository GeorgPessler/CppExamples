// https://www.youtube.com/watch?v=iChalAKXffs
#include <iostream>
using namespace std;

int main(){
    int SomeArray[10];

    int *pLocation6 = &SomeArray[6];
    int *pLocation0 = &SomeArray[0];

    cout << "pLocation6 = " << (int)pLocation6 << endl;
    cout << "pLocation0 = " << (int)pLocation0 << endl;
    cout << "Difference = " << pLocation6 - pLocation0 << endl;
    

    cout << endl; system("pause"); return 0;
}