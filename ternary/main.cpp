#include <iostream>

static int s_Level = 1;
static int s_Speed = 2;

int main() {
    // without ternary operator
    if (s_Level > 5){
        s_Speed = 10;
    } else {
        s_Speed = 5;
    }

    // with ternary operator
    s_Speed = s_Level > 5 ? 10:5;

    // when implementing the code for this logic
    std::string Rank = s_Level > 10 ? "Master" : "Beginner";

    std::string otherRank;
    if (s_Level > 10) {
        otherRank = "Master";
    } else {
        otherRank = "Beginner";
    }
    // using the ternary operator method will actually be faster than the
    // latter method as we don't need to create a temporary string that is
    // destroyed soon after - "return value optimization"

    // crazy stuff: nested ternary operators
    int s_Speed = s_Level > 5 ? s_Level > 10 ? 15 : 10 : 5;
    // easy to read form?
    /* s_speed = s_level > 10 ?  15 :
                 s_level >  5 ?  10 :
                                  5; */
}