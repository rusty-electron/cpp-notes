#include <iostream>
int countchar(char, const char*);

int area(int n){
    return n*n;
}

int main(int, char**) {
    int n = 5;
    char input[30];
    area(5);
    std::cout << "Hello, world!\n";
    std::cin >> input;
    std::cout << countchar('a', input);
}
