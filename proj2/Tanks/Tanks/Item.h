#pragma once
#include "Vector2D.h"
class Block;
class Item
{
public:
	Item(Block** blocks);
	virtual int key_input()=0;
	virtual Vector2D _loc() const=0;
	virtual Vector2D& _loc()=0;
	virtual void set_tank(int key)=0;
	virtual int _sp() const = 0;
	virtual int check_dir() const;
	virtual int _blood()const=0;
	virtual int& _blood() = 0;
	virtual bool validity() const;
	virtual bool& validity();
protected:
	Block** from_block;
	bool fuck;
};

