#include <iostream>
class Vector2D
{
public:
    Vector2D& operator = (const Vector2D& vector);
    bool operator == (const Vector2D& vector);
    Vector2D operator + (const Vector2D& a) const;
    Vector2D operator - (const Vector2D& a) const;
    Vector2D operator - () const;
    Vector2D();
    Vector2D(int x_loc, int y_loc);
    Vector2D(const Vector2D& vector);
    int get_x() const;
    int get_y() const;
    void display() const;
    void set(int x_loc, int y_loc);
    void inc_x(int delta);
    Vector2D x_inc_vec(int delta) const;
    Vector2D x_dec_vec(int delta) const;
    Vector2D y_inc_vec(int delta) const;
    Vector2D y_dec_vec(int delta) const;
    void dec_x(int delta);
    void inc_y(int delta);
    void dec_y(int delta);
private:
    int x;
    int y;
};
