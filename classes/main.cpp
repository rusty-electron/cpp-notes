#include <iostream>

class Player{
    public:
        int x, y;
        int speed;
        
        void move(int x_val, int y_val){
            x += x_val * speed;
            y += y_val * speed;
        }
};

// void move(Player& player, int x_val, int y_val){
//     player.x += x_val * player.speed;
//     player.y += y_val * player.speed;
// }

int main(int, char**) {
    Player player;
    player.move(1, -1);
}
