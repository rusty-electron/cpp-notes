#include <iostream>
#include "countchar.h"
int main(int, char**) {
    char input[30];
    std::cout << "Hello, world!\n";
    std::cin >> input;
    std::cout << countchar('a', input);
}
