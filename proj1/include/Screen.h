#include "Snake.h"
#include <cstdlib>
#include <ctime>
#define LEN 20
#define WIDTH 80
class Screen
{
public:
    Screen();
    bool output();
    string get_appearing(const Vector2D& loc) const;
    Block& get_block(const Vector2D& loc);
    void input();
    bool update();
    void screen_clear();
    void update_with_snake(const Snake& snake);
    bool produce_timefood();
    bool delete_timefood();
private:
    Snake snake;
    int width;
    int len;
    char input_ch;
    bool gameover;
    int score;
    Block blocks[LEN][WIDTH];
    Vector2D food_loc;
    void randfood();
    clock_t last_time;
    Vector2D timefood_loc;
    bool has_timefood;
    bool timefood_eaten;
};
