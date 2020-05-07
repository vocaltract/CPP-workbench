#pragma once
class Vector2D
{
public:
	Vector2D(int in_x, int in_y);
	Vector2D();
	Vector2D(const Vector2D& vec);
	Vector2D operator - () const;
	Vector2D operator + (const Vector2D& vec) const;
	Vector2D operator - (const Vector2D& vec) const;
	Vector2D& operator = (const Vector2D& vector);
	bool operator == (const Vector2D& vector) const;
	bool operator != (const Vector2D& vector) const;
	int& operator [](int i);
	int operator [](int i) const;
	void inc_x();
	void dec_x();
	void inc_y();
	void dec_y();
	void set(int in_x, int in_y);
protected:
	int x, y;
};

