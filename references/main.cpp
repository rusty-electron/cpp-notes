#include <iostream>
/* notes
1. note that reference can't be reassigned to a different variable like pointers
2. reference must be initialized with a variable or else the compiler will complain 
*/

void increment(int* val){
    (*val)++; // brackets are added so that dereferencing is performed at first
}

void increment(int& val){ // function overloading
    val++;
}

void Log(int value){
    std::cout<<value<<std::endl;
}

int main(){
    int a = 4;
    int& ref = a;
    increment(a);
    Log(a);
    ref = 5;
    Log(ref);
}
