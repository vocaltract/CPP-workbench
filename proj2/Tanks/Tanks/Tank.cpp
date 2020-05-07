#include "Tank.h"
int Tank::key_input()
{
	if (_kbhit()) return map(_getch());
	else return NOP;
}


Tank::Tank(const Vector2D& in_loc, Block** blocks,int tank_color=WHITE)
	:Item(blocks)
{
	loc = in_loc;
	speed = 1;
	blood = 3;
	action = NOP;
	color = tank_color;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if ((i == 0 && j == 0) || (i == 0 && j == 2) || (i == 2 && j == 1))
			{
				from_block[loc[0] + i][loc[1] + j].set(TANK, "  ", (Item*)this, tank_color);
			}
			else
			{
				from_block[loc[0] + i][loc[1] + j].set(TANK, "¨~", (Item*)this, tank_color);
			}
		}
	}
	dir = UP;
}
Vector2D Tank::_loc() const
{
	return loc;
}
Vector2D& Tank::_loc()
{
	return loc;
}
void Tank::set_tank(int key)
{
	dir = key;
	if (key == UP)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if ((i == 0 && j == 0) || (i == 0 && j == 2) || (i == 2 && j == 1))
				{
					from_block[loc[0] + i][loc[1] + j].set(TANK, "  ", (Item*)this, color);
				}
				else
				{
					from_block[loc[0] + i][loc[1] + j].set(TANK, "¨~", (Item*)this, color);
				}
			}
		}
	}
	if (key == DOWN)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if ((i == 0 && j == 1) || (i == 2 && j == 0) || (i == 2 && j == 2))
				{
					from_block[loc[0] + i][loc[1] + j].set(TANK, "  ", (Item*)this, color);
				}
				else
				{
					from_block[loc[0] + i][loc[1] + j].set(TANK, "¨~", (Item*)this, color);
				}
			}
		}
	}
	if (key == LEFT)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if ((i == 0 && j == 0) || (i == 1 && j == 2) || (i == 2 && j == 0))
				{
					from_block[loc[0] + i][loc[1] + j].set(TANK, "  ", (Item*)this, color);
				}
				else
				{
					from_block[loc[0] + i][loc[1] + j].set(TANK, "¨~", (Item*)this, color);
				}
			}
		}
	}
	if (key == RIGHT)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if ((i == 0 && j == 2) || (i == 1 && j == 0) || (i == 2 && j == 2))
				{
					from_block[loc[0] + i][loc[1] + j].set(TANK, "  ", (Item*)this, color);
				}
				else
				{
					from_block[loc[0] + i][loc[1] + j].set(TANK, "¨~", (Item*)this, color);
				}
			}
		}
	}

}
int Tank::_sp() const
{
	return speed;
}

int Tank::check_dir() const
{
	return dir;
}

int Tank::_blood()const
{
	return blood;
}
int& Tank::_blood()
{
	return blood;
}