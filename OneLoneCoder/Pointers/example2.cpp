// https://www.youtube.com/watch?v=iChalAKXffs

#include <iostream>
using namespace std;

int main(void){
    int SomeArray[10]  = {3,6,9,12,15,18,21,24,27,30};

    int *pLocation0 = SomeArray;
    bool outputInHex = false;

    if(outputInHex){
        cout << "Start address of array in memory: " << SomeArray << endl;
        cout << "Number: Memory Address = Value" << endl;

        for (int i = 0; i < 10; i++){
            cout << i << ": " << SomeArray + i << " = " << *(SomeArray + i) << endl;
        }

        cout << "Access via pointer:" << endl;
        cout << "Number: Memory Address = Value" << endl;
    
        for(int i = 0; i < 10; i++){
            cout << i << ": " << pLocation0 << " = " << *pLocation0 << endl;
            pLocation0++;
        }
    }else{
        cout << "Start address of array in memory: " << (int)SomeArray << endl;
        cout << "Number: Memory Address = Value" << endl;

        for (int i = 0; i < 10; i++){
            cout << i << ": " << (int)SomeArray + i << " = " << SomeArray[i] << endl;
        }

        cout << "Access via pointer:" << endl;
        cout << "Number: Memory Address = Value" << endl;
    
        for(int i = 0; i < 10; i++){
            cout << i << ": " << (int)pLocation0 << " = " << *pLocation0 << endl;
            pLocation0++;
        }
    }



    cout << endl; system("pause"); return 0;
}