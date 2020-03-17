#include <tools.h>
int main()
{
    Vector2D a(1,2), b(3,5);
    Vector2D c = b;
    Vector2D d;
    d = a - b;
    d.display();
    c.display();
}