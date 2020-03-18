#include "Snake.h"
#include <cstdlib>
#define LEN 20
#define WIDTH 80
class Screen
{
public:
    Screen();
    void output();
    string get_appearing(const Vector2D& loc) const;
    Block& get_block(const Vector2D& loc);
private:
    Snake snake;
    int width;
    int len;
    char input_buf;
    Block blocks[LEN][WIDTH];
    Vector2D food_loc;
    void randfood();

};
