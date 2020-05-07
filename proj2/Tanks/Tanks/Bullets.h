#pragma once
#include "Bullet.h"
class Bullets
{
public:
	Bullets(Block** in_blocks);
	Bullets();
	void add(const Vector2D& in_loc, int di);
	void update();
	void draw_all();
	void set_p(Block** in_blocks);

private:
	Bullet all_bullets[MAXBULLETS];
	Block** all_blocks;
	int all_speed;
};

