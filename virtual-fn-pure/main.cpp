// interface is a class that consists only of unimplemented functions
// these function can then be implemented in the subclasses
// note: interfaces can't be instantiated

#include <iostream>
#include <string>

class Printable {
    public:
    virtual std::string GetClassName() = 0;
};

// derive Entity from printable but we don't implement the GetClassName method here
class Entity : public Printable {
    public:
    virtual std::string GetName() = 0; // pure virtual function, this makes it so that it 
    // has to be implemented in a sub class
    std::string GetClassName() override { return "Entity"; }
};

// we implement the GetClassName method here
class Player : public Entity{
    private:
    std::string m_Name;
    public:
    Player(const std::string& name) : m_Name(name) {}

    std::string GetName() override { return m_Name; }
    std::string GetClassName() override { return "Player"; }
};

// we create a function that always return the name of the class
// of the object passed but in order to implement such a function
// we must make sure that we can pass a certain type to this function
// that always has a method or attribute that returns the class name
void Print(Printable* obj){ // cannot use Entity class here for obvious reasons

    // this function will always work because in order for this function to 
    // return a string, it is necessary for the argument to be of type
    // printable that have the GetClassName method
    std::cout << obj->GetClassName() << std::endl; 
}

int main(){
    // not allowed as the GetName method of Entity class is a pure virtual function
    // Entity* e = new Entity();

    Player* p = new Player("Cherno"); 
    // allowed as the Player class has an implemented GetName function
    // it is allowed if Player is a derived class of another class that has 
    // implemented the GetName method
    Print(p);

    // Print(e);
}