/* use new keyword to allocate memory on the heap specifically
 steps done by the use of new keyword 
 1. based on what datatype we are using, it determines how much space we 
    are going to need to allocate
 2. ask the OS or the C standard library to allocate this space in heap memory 
 3. we are then provided with a pointer that points to a contiguous block of memory 
    that is of the required size 
 4. "free list" */

 #include <iostream>
 #include <string>

 using String = std::string;

 class Entity{
     private:
     String m_Name;

     public:
     Entity() : m_Name("Unknown") {}
     Entity(const String& name) : m_Name(name) {}

     const String& GetName() const { return m_Name; }
 };

 int main(){
     int a = 2;
     int* b = new int; // create an int variable (on the heap) using new keyword
     int* b_aray = new int[50]; // 200 bytes

     Entity* e = new Entity(); // allocate an Entity class object on the heap, 
     // this apart from allocating memory, it also calls the constructor
     
     // We can get almost the same functionality as the above command by using malloc
     // and then casting the returned pointer to Entity* type but the difference will
     // be that the constructor would not be called. NOT RECOMMENDED THOUGH.
     Entity* e_hack = (Entity*)malloc(sizeof(Entity));
    
     Entity* e_array = new Entity[50]; // allocating (contiguously) an array of Entity objects

     // if using new, don't forget to use the delete keyword to free up the space 
     // (add this space to the freelist)
     delete e;

     // if delete array types created using new, use delete[] instead
     delete[] e_array;

     // You can also use new to specifically initialize an object at a specific address
     Entity* e_specific = new(b) Entity(); // this initializes the object at the address
     // stored in the b variable
 }