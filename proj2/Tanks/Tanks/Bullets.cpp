#include "Bullets.h"
#include "Block.h"

Bullets::Bullets(Block** in_blocks)
{
	all_blocks = in_blocks;
	all_speed = 2;

}
Bullets::Bullets()
{
	all_blocks = NULL;
	all_speed = 2;
}

void Bullets::set_p(Block** in_blocks)
{
	all_blocks = in_blocks;
}

void Bullets::add(const Vector2D& in_loc, int di)
{
	for (int i = 0; i < MAXBULLETS; i++)
	{
		if (!all_bullets[i].validity())
		{
			all_bullets[i].validity() = true;
			all_bullets[i].set(all_blocks, in_loc, di, all_speed);
			break;
		}
	}
}
void Bullets::update()
{
	for (int i = 0; i < MAXBULLETS; i++)
	{
		for (int k = 0; k < all_speed; k++)
		{
			if (all_bullets[i].validity())
			{
				int x = all_bullets[i]._loc()[0];
				int y = all_bullets[i]._loc()[1];
				all_blocks[x][y].reset();
				if (all_bullets[i]._dir() == UP)
				{
					x--;
				}
				else if (all_bullets[i]._dir() == DOWN)
				{
					x++;
				}
				else if (all_bullets[i]._dir() == LEFT)
				{
					y--;
				}
				else if (all_bullets[i]._dir() == RIGHT)
				{
					y++;
				}
				else
				{
					assert(0);
				}
				if (all_blocks[x][y]._label() == TOUGHWALL)
				{
					all_bullets[i].validity() = false;
				}
				else if (all_blocks[x][y]._label() == LIGHTWALL)
				{
					all_blocks[x][y].reset();
					all_bullets[i].validity() = false;
				}
				else if (all_blocks[x][y]._label() == TANK)
				{
					Item* tank = all_blocks[x][y].it();
					int cur_blood = tank->_blood();
					tank->_blood() =cur_blood-1;
					all_bullets[i].validity() = false;
				}
				else if (all_blocks[x][y]._label() == BULLET)
				{
					Item* bu = all_blocks[x][y].it();
					bu->validity() = false;
					all_blocks[x][y].reset();
					all_bullets[i].validity() = false;
				}
				else if (all_blocks[x][y]._label() == BLANK)
				{
					all_bullets[i].set_loc(x, y);
				}
				else if(all_blocks[x][y]._label() == BASE)
				{
					is_gameover = true;
					all_blocks[x][y].reset();
					all_bullets[i].validity() = false;
				}
				else
				{
					assert(0);
				}

			}
		}
	}
}

void Bullets::draw_all()
{
	for (int i = 0; i < MAXBULLETS; i++)
	{
		if (all_bullets[i].validity())
		{
			all_bullets[i].draw();
		}
	}
}