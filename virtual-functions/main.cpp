#include <iostream>
#include <string>

/* virtual functions are useful for overriding methods in derived class that 
are also present in the parent class */

class Entity {
    public:
    std::string GetName() { return "Entity"; }
    // The fix:
    // virtual std::string GetName() { return "Entity"; }
};

class Player : public Entity {
    private:
    std::string m_Name;
    public:
    Player(const std::string& name) : m_Name(name) {} // constructor

    std::string GetName() { return m_Name; }
    // you can also add the optional override keyword as shown below
    // it is not mandatory but it is advised to add this keyword to
    // improve code readability and error checking
    // std::string GetName() override { return m_Name; }
};

void PrintName(Entity* entity){
    std::cout << entity->GetName() << std::endl;
}

int main(){
    // we instantiate an object of the Entity class and call its GetName method
    Entity* e = new Entity();
    std::cout << e->GetName() << std::endl;

    // then we instantiate an object of the Player class and call its GetName method
    Player* p = new Player("Cherno");
    std::cout << p->GetName() << std::endl;

    // but we get issues when we apply polymorphism and assign a Player object to an
    // Entity pointer
    Entity* entity = p;
    std::cout << entity->GetName() << std::endl; // here we get "Entity" printed

    // we can test the same using
    // PrintName(e);
    // PrintName(p);

    /* This happens because whenever it is time to call a method, the program calls the function
    corresponding to the type and therefore, we get the output of the entity class's GetName 
    method. But the behaviour that we want is that the program should determine the type of the
    object which has been passed and then call its method which is Player class's GetName 
    method in this case. */

    /* enter virtual functions: these functions introduce dynamic dispatch. This is implemented by
    the compiler using v-tables that map every virtual function defined in the base class to the
    overriding functions in the derived classes. */

    /* why not use virtual functions:
    * additional memory needed to store v-table and member pointer in each base class
      to point to the corresponding entry in v-table.
    * also everytime we call a virtual function we have to go through the process of
      looking up the correspoding member function in the v-table */
}