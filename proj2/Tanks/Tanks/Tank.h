#pragma once
#include "Item.h"
#include "Block.h"
#include "Vector2D.h"
#include "common.h"
#include <conio.h>
class Tank :
	public Item
{
public:
	Tank(const Vector2D& in_loc, Block** blocks, int tank_color);
	virtual Vector2D _loc() const;
	virtual Vector2D& _loc();
	virtual int _sp() const;
	virtual int _blood()const;
	virtual int& _blood();
	virtual void set_tank(int key);
	virtual int key_input();
	int check_dir() const;
protected:
	Vector2D loc;
	int blood;
	int speed;
	int action;
	int color;
	int dir;


};

