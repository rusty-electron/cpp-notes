#include <iostream>
#include <array>

int main() {
    int example[5];
    example[0] = 2;
    example[4] = 68; // mem addr stored in example + sizeof(int) * 4

    int a = example[0];

    // using pointers
    int* ptr = example;
    *(ptr + 4) = 68; // same as `example[4] = 68`
    *(int*)((char*)ptr + 4*4) = 68;

    /* trying to access indexes of arrays that are not in bounds
       lead to Memory Access Violation errors but the compiler 
       tells us this only in debug mode but no error is displayed
       in release mode and therefore, we would be writing data
       to illegal locations and may end up modifying memory 
       belonging to other variables in your program */
    // example[5] = 1;
    // example[-1] = 42;

    std::cout << example[0] << std::endl;
    std::cout << example << std::endl;

    // loops are helpful for modifying variables
    for (int i=0; i<5; i++){ // advised to use "<" operator instead of
    // "<=" as the latter is more expensive in terms of performance
        example[i] = -1;
    }

    // using new keyword to create arrays (on heap)
    int* another = new int[5];
    /* when to use: arrays may be allocated on the heap for extended lifetime
     say you want to return an array created inside a function then you should 
     create an array on the heap */

    /* a disadvantage of doing so is that the array contents are stored in different
    location which may lead to cache misses. For example, if we have a class that has 
    an int array as a member attribute, if it is stack allocated it would be stored at the 
    location of the object but when allocated in heap, the object address location will
    contain a memory address that would point to the array content and it is usually 
    stored at a different location. Hence, the operation of dereference such memory
    pointers leads to performance hits. */

    /* note: there is no way of knowing the size of an array in c++ if the array
    is allocated in heap but this is compiler dependent as in some cases, it is
    stored in the negative index of the array, emphasis on "some" */

    // for arrays allocated on the stack you can use `sizeof(arr) / sizeof(datatype)`
    // don't try this on heap allocated array as it would probably return 1

    // therefore, best advise is to maintain the size of the array in a variable
    // and do:
    const int size = 10;
    int array_new[size];

    delete[] another;

    // C++11
    /* in C++ 11 you can use the standard array but you must include the array library
    in the header */
    std::array<int ,5> another_standard;
    std::cout<<another_standard.size()<<std::endl;

    // this implementation does have overhead as it performs bounds checking but
    // it also allows the size() method (which may be a pro or a con depending on
    // your requirement) 
}