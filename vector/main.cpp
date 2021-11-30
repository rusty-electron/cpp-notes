#include <iostream>
#include <string>
#include <vector>

struct Vertex {
    float x, y, z;
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex){
    stream << vertex.x << ", " << vertex.y << ", " << vertex.z;
    return stream;
}

// when passing vector to function, always use reference
void Function(const std::vector<Vertex>& vertices){ // use const if not modifying
    // this way you can avoid copying this vector inside this scope
}

int main(){
    // declaring an array of vertex struct requires us to provide a predefined size
    // here, size = 5. We can't dynamically modify it.
    Vertex vertices_old[5];

    // although we can do this, but!
    // Vertex vertices[500000000]; // memory begone!

    // unlike java, in C++ we can pass primitive types like int here
    std::vector<Vertex> vertices; // inline allocated, good for iterating (same cacheline)
    std::vector<Vertex*> vertices_heap; // heap allocated, good for resizing

    Function(vertices);
    // use push_back() to add element to a vector
    vertices.push_back({ 1, 2, 3});
    vertices.push_back({ 4, 5, 6});

    for (int i = 0; i < vertices.size(); i++){
        std::cout << vertices[i] << std::endl;
    }

    // remove one element
    vertices.erase(vertices.begin() + 1);

    // range based for loops
    for (Vertex& v: vertices)
        std::cout << v << std::endl;

    // clear the vector
    vertices.clear();
}