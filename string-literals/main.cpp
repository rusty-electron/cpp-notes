#include <iostream>

int main(){
    using namespace std::string_literals; // needed for s operator

    "Cherno"; // const char array of length 7, extra +1 for null character
    // "Cher\0no" // hehe

    // char* name[14] = "rustyelectron"; // always use const to avoid mistakes
    // name[1] = 'o'; 
    /* even if the array is not declared as const
     modifying individual positions in the array is considered
     undefined behavior according to C++ standards, this is 
     because string literals are stored in read only portions of memory,
     CONST SEGMENT */

    // but instead you can do
    char name_[] = "rusty"; // array not pointer
    name_[1] = 'o';    
    
    const char* name = u8"Cherno";
    const wchar_t* name2 = L"Cherno"; // 2 or 4 bytes

    const char16_t* name3 = u"Cherno";
    const char32_t* name4 = U"Cherno";

    std::string name0 = "Cherno"s + " says Hello"; 
    // the s operation converts the string literal to std::string

    const char* example = R"(this
        is
        useful
        for
        multi-line
        strings)"; // newline is preserved, R for raw (also not that escape sequences are ignored)
}