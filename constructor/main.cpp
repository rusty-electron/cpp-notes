#include<iostream>
class Entity{
public:
  float X, Y;
  Entity(){
    X = 0;
    Y = 0;
  }
  Entity(float x, float y){
    X = x;
    Y = y;
  }
  void Print(){
    std::cout << X << ", " << Y << std::endl;
  }
};

class Log{
public:
  Log() = delete;
  static void Write(){
    
  }
};

int main(){
  Entity e(5.0f, 1.2f);
  e.Print();
}
