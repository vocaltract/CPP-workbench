#include "Bullet.h"
#include "Block.h"
Bullet::Bullet(Block** in_blocks, const Vector2D& in_loc, int di)
	:Item(in_blocks)
{
	loc = in_loc;
	speed = 3;
	valid = true;
	direct = di;
}

Bullet::Bullet()
	:Item(NULL)
{
	speed = 3;
	Vector2D tmp(0, 0);
	loc = tmp;
	valid = false;
	direct = NOP;
}
void Bullet::draw()
{
	(from_block[loc[0]][loc[1]]).set(BULLET, shape_buf[BULLET], (Item*)this, WHITE);
}
int Bullet::_dir() const
{
	return direct;
}


void Bullet::set_loc(int x, int y)
{
	loc[0] = x;
	loc[1] = y;
}

bool& Bullet::validity()
{
	return valid;
}
bool Bullet::validity() const
{
	return valid;
}
void Bullet::set(Block** in_blocks, const Vector2D& in_loc, int di,int sp)
{
	from_block = in_blocks;
	loc = in_loc;
	valid = true;
	direct = di;
	speed = sp;
}
void Bullet::reset()
{
	valid = false;
	direct = NOP;
}


int Bullet::key_input()
{
	assert(0);
	return 0;
}
Vector2D Bullet::_loc() const
{
	return loc;
}
Vector2D& Bullet::_loc()
{
	return loc;
}
void Bullet::set_tank(int key)
{
	assert(0);
}
int Bullet::_sp() const
{
	return speed;
}

int Bullet::_blood()const
{
	assert(0);
	return 0;
}
int& Bullet::_blood()
{
	assert(0);
	return speed;
}