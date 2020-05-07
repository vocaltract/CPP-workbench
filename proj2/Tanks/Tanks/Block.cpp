#include "Block.h"
#include "common.h"
Block::Block() :loc(0, 0)
{
	item = NULL;
	label = BLANK;
	sh = " ";
	color = WHITE;
}
Block::Block(int x, int y):loc(x,y)
{
	item = NULL;
	label = BLANK;
	sh = " ";
	color = WHITE;
}
Block::Block(int x, int y, int l):loc(x,y)
{
	item = NULL;
	label = l;
	sh = shape_buf[l];
	color = color_buf[l];
}
void Block::print()
{
	if (color == WHITE)
	{
		cout << sh;
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
		cout << sh;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	}
}
void Block::set(int x, int y,int l=BLANK)
{
	Vector2D a(x, y);
	loc = a;
	item = NULL;
	label = l;
	sh = shape_buf[l];
	color = color_buf[l];
}
void Block::set(int lab, const string& shape, Item* it,int colo)
{
	label = lab;
	item = it;
	sh = shape;
	color = colo;
}

int Block::_label() const
{
	return label;
}


void Block::reset()
{
	item = NULL;
	label = BLANK;
	sh = shape_buf[BLANK];
	color = color_buf[BLANK];
}

string& Block::get_shape()
{
	return sh;
}
Item*& Block::it()
{
	return item;
}
Item* Block::it() const
{
	return item;
}