#include <iostream>

class Entity{
    public:
    float X, Y;

    void Move(float xa, float ya){
        X += xa;
        X += ya;
    }
};

class Player : public Entity{
    public:
    const char* Name;

    void PrintName(){
        std::cout << Name << std::endl;
    }
};

int main(){
    std::cout << "Size occupied by Entity object: " << sizeof(Entity) << std::endl; 
    std::cout << "Size occupied by Player object: " << sizeof(Player) << std::endl; 
    return 0;
}