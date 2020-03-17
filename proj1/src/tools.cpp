#include <tools.h>
Vector2D::Vector2D()
{
    x = 0;
    y = 0;
}

Vector2D::Vector2D(int x_loc, int y_loc)
{
    x = x_loc;
    y = y_loc;
}
Vector2D::Vector2D(const Vector2D& vector)
{
    x = vector.x;
    y = vector.y;
}

Vector2D Vector2D::operator + (const Vector2D& a) const
{
    Vector2D res;
    res.x += a.x+x;
    res.y += a.y+y;
    return res;
}

Vector2D Vector2D::operator- (const Vector2D& b) const
{
    Vector2D res;
    res.x += x-b.x;
    res.y += y-b.y;
    return res;
}

Vector2D Vector2D::operator - () const
{
    Vector2D res;
    res.x = -x;
    res.y = -y;
    return res;
}

Vector2D& Vector2D::operator = (const Vector2D& vector)
{
    if(&vector == this) return *this;
    x = vector.x;
    y = vector.y;
    return *this;
}


void Vector2D::display() const
{
    std::cout<<'('<<x<<','<<y<<')'<<std::endl;
}

void Vector2D::set(int x_loc, int y_loc)
{
    x = x_loc;
    y = y_loc;
}



