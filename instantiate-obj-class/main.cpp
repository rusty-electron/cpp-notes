// note: even if a class has no attributes and functions, it will occupy atleast 1 byte in
// memory

#include <iostream>
#include <string>

using String = std::string;

class Entity {
    private:
    String m_Name;
    public:
    Entity() : m_Name("Unknown") {}
    Entity(const String& name) : m_Name(name) {}

    const String& GetName() const { return m_Name; }
};

void Function(){
    // scope is limited to just this function
    Entity entity = Entity("Stack allocated object");
    /* this stack-allocated object is destroyed when this scope (in this
    case the function scope) ends */
}

int main(){
    Entity entity; // calls default constructor
    std::cout << entity.GetName() << std::endl;

    // we can also initialize by calling the second constructor as
    Entity entity_one("Cherno");
    Entity entity_two = Entity("Cherno"); // this is same as the above line

    std::cout << entity_one.GetName() << std::endl;
    std::cout << entity_two.GetName() << std::endl;

    // we create a pointer of type Entity object
    Entity* e;
    {
        // we now create an Entity object that exists only in
        // this scope
        Entity entity_tmp("My life is short :(");
        e = &entity_tmp; // e pointer now points to the entity_tmp object address
    }
    // here, e points to an object that doesn't exist

    /* if we are going to create a large class or a lot of smaller classes that would eventually
    exceed the stacksize of 1MiB/2MiB then we have to allocate them to the heap. */
    {
        Entity* entity_heap = new Entity("Heap-allocated object");
        std::cout << (*entity_heap).GetName() << std::endl;
        std::cout << entity_heap->GetName() << std::endl;
        delete entity_heap; // free memory
    }

    /* allocate object in heap if:
    1. your object is too big for stack
    2. you want manually control over its lifetime
    else - USE STACK ALLOCATION! */

    // read on: Smart pointers - automatic memory deletion
}