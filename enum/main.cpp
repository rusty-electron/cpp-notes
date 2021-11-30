#include<iostream>
enum Example: unsigned char{
  A = 5, B, C
};
int main(){
  Example value = B;
  if (value == 5){
    std::cout<<"pass";
  }else{
    std::cout<<"fail";
  }
}
