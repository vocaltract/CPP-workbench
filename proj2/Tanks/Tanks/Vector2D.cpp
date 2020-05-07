#include "Vector2D.h"
#include <cassert>
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
	res.x += a.x + x;
	res.y += a.y + y;
	return res;
}

Vector2D Vector2D::operator- (const Vector2D& b) const
{
	Vector2D res;
	res.x += x - b.x;
	res.y += y - b.y;
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
	if (&vector == this) return *this;
	x = vector.x;
	y = vector.y;
	return *this;
}

bool Vector2D::operator == (const Vector2D& vector) const
{
	return x == vector.x && y == vector.y;
}

bool Vector2D::operator != (const Vector2D& vector) const
{
	return !this->operator==(vector);
}
int& Vector2D::operator [](int i)
{
	if (i == 0)		return x;
	else if (i == 1)		return y;
	else assert(0);
	return x;//for eliminating warning
}
int Vector2D::operator [](int i) const
{
	if (i == 0)		return x;
	else if (i == 1)		return y;
	else assert(0);
	return -1;
}
void Vector2D::inc_x()
{
	x++;
}
void Vector2D::dec_x()
{
	x--;
}
void Vector2D::inc_y()
{
	y++;
}
void Vector2D::dec_y()
{
	y--;
}
void Vector2D::set(int in_x, int in_y)
{
	x = in_x;
	y = in_y;
}