#include <string>
#include "Vector2D.h"
using std::string;
class Block
{
public:
    Block();
    Block(int x_loc, int y_loc, string another=" ");
    Vector2D& get_vector();
    void up();
    void down();
    void left();
    void right();
    void set(int x_loc, int y_loc);
    void set_appearing(string fig);
    string get_appearing() const;
    void output();
private:
    Vector2D loc;
    string appearing;
};