#include<iostream>

// visibility is an abstract concept and does not offer any
// performance benefits, it is only good for  writing better code

class Entity{
    // private: // can also be accessed by member functions
    // implied for member attributes in case missing
    int X, Y;
    void Print() {}

    protected: // such members can be accessed by the member functions
    // in the base class and its derivatives
    float PI = 3;
    public:
    Entity() {
        PI = 3.1;
        X = 0;
        Print(); // allowed
    }
};

class Player : public Entity {
    public:
    Player() {
        PI = 3.1412; // allowed
        // X = 0; // not allowed to access
        // Print(); // not allowed
    }
};

struct Entity_struct {
    // public: (implied)
    int X, Y;
};

int main(){
    Entity e;
    // e.PI = 3.1416; // not allowed
    // e.X = 2; // not allowed to access as it is a private member

    // public can be accessed anywhere, not recommended for everything
}