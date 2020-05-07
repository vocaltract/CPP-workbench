#pragma once
#include "Vector2D.h"
#include "Item.h"
#include "common.h"
class Block
{
public:
	Block();
	Block(int x, int y);
	void set(int x, int y, int l);
	void set(int lab, const string& shape,Item* it,int a_color);
	Item*& it();
	Item* it() const;
	Block(int x, int y, int l);
	int _label() const;
	string& get_shape();
	void print();
	void reset();
private:
	Vector2D loc;
	string sh;
	Item* item;
	int label;
	int color;
};

