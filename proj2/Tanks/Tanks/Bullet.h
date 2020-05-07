#pragma once
#include "common.h"
#include "Item.h"
class Block;
class Vector2D;
class Bullet :
	public Item
{
public:
	Bullet(Block** in_blocks, const Vector2D& loc,int di);
	Bullet();
	virtual int key_input();
	virtual Vector2D _loc() const;
	virtual Vector2D& _loc();
	virtual void set_tank(int key);
	virtual int _sp() const;
	int _dir() const;
	bool& validity();
	bool validity() const;
	void set(Block** in_blocks, const Vector2D& loc, int di,int sp);
	void reset();
	void draw();
	void set_loc(int x, int y);
	virtual int _blood()const;
	virtual int& _blood();
protected:
	int direct;
	bool valid;
	Vector2D loc;
	int speed;

};

