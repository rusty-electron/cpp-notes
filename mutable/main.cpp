#include <iostream>
#include <string>

// note: in order to get more out of this "tutorial", read the main.cpp about
// the const keyword
class Entity {
    private:
    std::string m_Name;
    mutable int m_DebutCount = 0; // created with the intention
    // to keep track of the number of times the GetName function
    // was called

    public:
    const std::string& GetName() const {
        m_DebutCount++;
        return m_Name;
    }
};

int main() {
    // we are using const keyword in the GetName() in order to be
    // able to create a const Entity object and call the GetName()
    // method
    const Entity e;
    e.GetName();

    int x = 41;
    // quick intro to lambda fns (where the mutable keyword has a use)
    auto f = [=]() mutable { // [=] signifies passing all variables to this fn by value
    // use & for passing by keyword
    // here the mutable keyword allows modifying values inside this function
        x++;
        std::cout << x << std::endl;
    };
    f();
    // x is still equal to 41 here
}