#include<iostream>
#include<string>

// makes a copy of the string, expensive
void string_function(std::string input){
    std::cout << input;
}

// no copy created here
void string_function(const std::string& input){
    std::cout << input;
}

int main(){
    // using const char* prevents you from making changes to it. You
    // should be making a copy of it to make changes.
    const char* name = "Cherno"; 

    // char* name_can_change = "CherNO"; // this can be modified? WRONG, see below

    // UPDATE: as of C++11, the above statement is false

    /* That is undefined behavior as leaving a pointer to a string literal 
    which is non-const is deprecated since C++11. You must not change any value of 
    the C string-Literal! */
    char name_can_change[] = "CherNO"; // this is a char array, not a string literal
    name_can_change[5] = '0'; // can't do this to const char*
    std::cout << name_can_change << std::endl;

    char no_null[7] = {'n', 'o', '_', 'n', 'u', 'l', 'l'};
    // fix this as
    // char no_null[8] = {'n', 'o', '_', 'n', 'u', 'l', 'l', 0 };
    std::cout << no_null << std::endl; // no null termination, lolz!

    std::string name_string = "Chernobyl"; // string datatype has a constructor that takes const char*
    std::cout << name_string << std::endl; // need to include string.h to print string datatype
    // the overloaded cout operation is present in string.h

    // appending strings
    // std::string appended = "Hello, " + "World!"; // cannot add two const char arrays

    // either split
    std::string appended_hack = "Hello, ";
    appended_hack += "World!";

    // or call the string constructor explicitly
    std::string appended = std::string("Hello, ") + "World!";

    bool contains = appended.find("Hell") != std::string::npos;
    std::cout << contains << std::endl;

    // read more: https://www.cplusplus.com/reference/string/string/
}