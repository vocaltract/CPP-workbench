# include <iostream>
class Vector2D
{
public:
    Vector2D& operator = (const Vector2D& vector);
    Vector2D operator + (const Vector2D& a) const;
    Vector2D operator - (const Vector2D& a) const;
    Vector2D operator - () const;
    Vector2D();
    Vector2D(int x_loc, int y_loc);
    Vector2D(const Vector2D& vector);
    void display() const;
    void set(int x_loc, int y_loc);
private:
    int x;
    int y;
};
