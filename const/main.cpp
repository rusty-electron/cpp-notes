#include <iostream>

class Entity {
    private:
    int m_X, m_Y;
    // IMP: int* m_X, m_Y; here m_X is a ptr but m_Y is just an int. The correct
    // way is to do: int* m_X, *m_Y;

    public:
    int GetX() const { // a promise that this method is not going to modify any variables
                       // of this class 
        // m_X = 2; // not allowed due to the const keyword
        return m_X;
    }

    // it is common to have two versions of getters to prevent the problem as 
    // seen when using const references as function arguments
    int GetX() {
        m_X = 2;
        return m_X;
    }

    int SetX(int val) { // you would not use const keyword with a setter, duh!
        m_X = val;    
    }

    const int* const not_modifying() const {
        // this function accept a pointer that cannot be reassigned and
        // contents cannot be modified
        // also this function cannot modify any variable in Entity class
        int a = 2;
    }
};

void PrintEntity(const Entity& e){ // here we pass as argument, the reference to the Entity
    // object. Therefore, we are not allowed to make any changes to it. 
    // (See https://www.youtube.com/watch?v=4fJBrditnJU) timestamp: 10:20, also revisit 
    // C++ references topic, so if we can only call the function with the const keyword as it 
    // guarantees that no changes will be made to the class variables

    std::cout << e.GetX() << std::endl; // removing the const keyword from the GetX function
    // will result in error
}

int main() {
    const int MAX = 255; // we make a promise to not change this
    int MIN = -1; // no promise here

    // we declare a const int on the heap
    const int* a = new int;
    // int const* a = new int; // same as previous line
    *a = 2; // changing the content of the const ptr is not allowed
    a = (int*)&MAX; // reassigning is allowed though

    std::cout << *a << std::endl; // prints 255 (value of MAX)

    // now we use the const keyword in a different way
    int* const b = new int;
    *b = 4; // now changing the content is allowed
    b = (int*)&MAX; // but reassigning the location is not!

    // now disable both using
    const int* const c = new int;
}

/* Commment by Jean-Nay Mar 

For people having trouble remembering the order in which const keyword is to be used, here's a quick tip.
You have to read it backward, like the compiler does. For instance : 

-const int * A; ==> "A is a pointer to an int that is constant."
(or, depending on how you prefer to write it)
int const* A; ==> "A is a pointer to a const int"
but both are the same as explained in the video.

-int * const A; ==> "A is a const pointer to an int."
-const int* const A; ==> "A is a const pointer to an int that is constant".

EDIT : 
As mentionned by simo simo in the comments bellow, const int * A does not mean that A actually points to a const variable. It just means that the compiler will not allow you to modify the pointed value through A.

for instance : 
int val = 10;
int const * a = &val;
*a = 30; //this will NOT compile, you're not allowed to modify "val" through "a".
val = 30; //this will compile. 

Same with : 

int val = 10;
int val2 = 30;
const int * const A = &val; 

A = &val2; //will NOT compile : you can't modify what A points to.
*A = 30; //will NOT compile : you can't modify val through A

val = 30; //this will compile, val is not constant
*/