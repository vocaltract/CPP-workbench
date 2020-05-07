#include "Screen.h"
#include "LightTank.h"
#include "MediumTank.h"
#include "HeavyTank.h"
Screen::Screen()
{
	cur_key = NOP;
	blocks = new Block * [LEN];
	for (int i = 0; i < LEN; i++)
	{
		blocks[i] = new Block[WIDTH];
	}
	all_bullets.set_p(blocks);
	for (int i = 0; i < LEN; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			if (i == 0||j==0||i==LEN-1||j==WIDTH-1)
			{
				blocks[i][j].set(i, j, TOUGHWALL);
			}
			else//敌人出生点为(1,1) (1,24) （1,47）
			{
				if ((i<4&&j>=4&&j<=23)||(i<4&&j>=27&&j<WIDTH-4))
				{
					blocks[i][j].set(i, j, LIGHTWALL);
				}
				else if(i>=17&&i<=20&&j>=5&&j<=16)
				{
					blocks[i][j].set(i, j, LIGHTWALL);
				}
				else if ((i==12&&15<=j &&j<=20) || (i==15 && 33 <= j && j <= 38)||(i==16 && 24<=j&&j<=28))
				{
					blocks[i][j].set(i, j, TOUGHWALL);
				}
				else if (i>=LEN-5&& i<LEN-2 && j>=23&&j<=25 )
				{
					blocks[i][j].set(i, j, BASE);
				}
				else if ((i==LEN-2|| i==LEN-6 )&& j >= 22 && j <= 26)
				{
					blocks[i][j].set(i, j, LIGHTWALL);
				}
				else if (i >= LEN - 5 && i < LEN - 2&&(j==22||j==26))
				{
					blocks[i][j].set(i, j, LIGHTWALL);
				}
				else
				{
					blocks[i][j].set(i, j, BLANK);
				}
			}
		}
	}
	Vector2D init_loc(LEN - 5, 22-8);
	mytank = new LightTank(init_loc, blocks);
	mytank->_blood() = 2/1;
	cur_enemy = MAXENEMIES;
	Vector2D loc2(1, 1);
	enemy[0] = new LightTank(loc2, blocks);
	Vector2D loc3(1, 24);
	enemy[1] = new MediumTank(loc3, blocks);
	Vector2D loc4(1, 46);
	enemy[2] = new HeavyTank(loc4, blocks);

}
void Screen::print_graphic()
{
	std::ios::sync_with_stdio(false);
	for (int i = 0; i < LEN; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			//cout << blocks[i][j].get_shape();
			blocks[i][j].print();
		}
		cout << endl;
	}
}

Block& Screen::get_block(const Vector2D& loc)
{
	return blocks[loc[0]][loc[1]];
}
Block& Screen::get_block(int x, int y)
{
	return blocks[x][y];
}

void Screen::get_input()
{
	cur_key = mytank->key_input();
}
void Screen::act_key()
{
	if (cur_key == NOP) return;
	if (cur_key == SHOOT)
	{
		int dir = mytank->check_dir();
		int x = mytank->_loc()[0];
		int y = mytank->_loc()[1];
		switch (dir)
		{
			case UP: {x--; y++; } break;
			case DOWN: {x += 3; y++; } break;
			case LEFT: {x++; y--; } break;
			case RIGHT: {x++; y += 3; }break;
			default:assert(0);
		}
		if (blocks[x][y]._label() == BLANK)
		{
			Vector2D tmp(x, y);
			all_bullets.add(tmp, dir);
		}
		else if (blocks[x][y]._label()==BASE)
		{
			is_gameover = true;
			blocks[x][y].reset();
		}
		else if (blocks[x][y]._label() == TOUGHWALL)
		{

		}
		else if (blocks[x][y]._label() == LIGHTWALL)
		{
			blocks[x][y].reset();
		}
		else if (blocks[x][y]._label() == TANK)
		{
			Item* tank = blocks[x][y].it();
			int cur_blood = tank->_blood();
			tank->_blood() = cur_blood - 1;
		}
		else if (blocks[x][y]._label() == BULLET)
		{
			Item* bu = blocks[x][y].it();
			blocks[x][y].reset();
			bu->validity() = false;
		}
		else
		{
			assert(0);
		}

		return;//TODO!!!!!!!!!!!!!
	}//要return！！！！！
	for (int j = mytank->_sp(); j > 0; j--)
	{
		if (check_walk(cur_key, mytank->_loc()))
		{
			move(cur_key, mytank);
		}
	}
//TODO!!!!!!!!!!!!

}
void Screen::do_enemy()
{
	int act_key = NOP;
	int count_enemy = 0;
	for (int i = 0; i < MAXENEMIES; i++)
	{
		if (enemy[i]->_blood()>0)
		{
			count_enemy++;
			act_key = act_buf[rand() % ACTLEN];
			if (act_key == NOP) continue;
			if (act_key == SHOOT)
			{
				int dir = enemy[i]->check_dir();
				int x = enemy[i]->_loc()[0];
				int y = enemy[i]->_loc()[1];
				switch (dir)
				{
				case UP: {x--; y++; } break;
				case DOWN: {x += 3; y++; } break;
				case LEFT: {x++; y--; } break;
				case RIGHT: {x++; y += 3; }break;
				default:assert(0);
				}
				if (blocks[x][y]._label() == BLANK)
				{
					Vector2D tmp(x, y);
					all_bullets.add(tmp, dir);
				}
				else if (blocks[x][y]._label() == BASE)
				{
					is_gameover = true;
					blocks[x][y].reset();
				}
				else if (blocks[x][y]._label() == TOUGHWALL)
				{

				}
				else if (blocks[x][y]._label() == LIGHTWALL)
				{
					blocks[x][y].reset();
				}
				else if (blocks[x][y]._label() == TANK)
				{
					Item* tank = blocks[x][y].it();
					int cur_blood = tank->_blood();
					tank->_blood() = cur_blood - 1;
				}
				else if (blocks[x][y]._label() == BULLET)
				{
					blocks[x][y].reset();
					Item* bu = blocks[x][y].it();
					bu->validity() = false;
				}
				else
				{
					assert(0);
				}
				continue;
			}
			for (int j = enemy[i]->_sp(); j > 0; j--)
			{
				if (check_walk(act_key, enemy[i]->_loc()))
				{
					move(act_key, enemy[i]);
				}
			}
		}
		else if (enemy[i]->_blood() == 0)
		{
			int x = enemy[i]->_loc()[0];
			int y = enemy[i]->_loc()[1];
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					blocks[x + i][y + j].reset();
				}
			}
		}
	}
	cur_enemy = count_enemy;
}


void Screen::update_draw_bullets()
{
	all_bullets.update();
	all_bullets.draw_all();
}



bool Screen::check_walk(int key, const Vector2D& in_loc)
{
	int x = in_loc[0];
	int y = in_loc[1];
	assert(key != NOP);
	assert(key != SHOOT);
	if (key == UP)
	{
		if (blocks[x - 1][y]._label() != BLANK || blocks[x - 1][y + 1]._label() != BLANK
			|| blocks[x - 1][y + 2]._label() != BLANK) return false;
	}
	if (key == DOWN)
	{
		if (blocks[x + 3][y]._label() != BLANK || blocks[x + 3][y + 1]._label() != BLANK
			|| blocks[x + 3][y + 2]._label() != BLANK) return false;
	}
	if (key == LEFT)
	{
		if (blocks[x][y-1]._label() != BLANK || blocks[x+1][y - 1]._label() != BLANK
			|| blocks[x+2][y-1]._label() != BLANK) return false;
	}
	if (key == RIGHT)
	{
		if (blocks[x][y +3]._label() != BLANK || blocks[x + 1][y +3]._label() != BLANK
			|| blocks[x + 2][y+3]._label() != BLANK) return false;
	}
	return true;
}
void Screen::move(int key, Item* tank)
{
	int x = tank->_loc()[0];
	int y = tank->_loc()[1];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			blocks[x + i][y + j].reset();
		}
	}
	if (key == UP)
	{
		tank->_loc().dec_x();
	}
	if (key == DOWN)
	{
		tank->_loc().inc_x();
	}
	if (key == LEFT)
	{
		tank->_loc().dec_y();
	}
	if (key == RIGHT)
	{
		tank->_loc().inc_y();
	}
	tank->set_tank(key);//dir在这里更新
}


bool Screen::judge_game()
{
	if (is_gameover) return true;
	if (mytank->_blood() <= 0) return true;
	if (cur_enemy==0) return true;
	return false;
}

void Screen::print_text()
{
	cout << endl;
	cout << "MyTankLife:" << mytank->_blood() << endl;
	cout << "EnemyLeft:" << cur_enemy << endl;
	cout << "Score:" << 3 - cur_enemy << endl;
}



Screen::~Screen()
{
	for (int i = 0; i < LEN; i++)
	{
		delete[] blocks[i];
	}
	delete blocks;
}