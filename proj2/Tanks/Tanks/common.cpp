#include "common.h"
const string shape_buf[] = {"·","  ","▇","〓","▇","▇","▇","★"};
const int color_buf[] = { WHITE,WHITE,WHITE,WHITE,RED,BLUE,GREEN,RED};
int map(char inch)
{
	switch (inch)
	{
		case 'w':return UP; break;
		case 'W':return UP; break;
		case 'A':return LEFT; break;
		case 'a':return LEFT; break;
		case 'D':return RIGHT; break;
		case 'd':return RIGHT; break;
		case 'S':return DOWN; break;
		case 's':return DOWN; break;
		case 'J':return SHOOT; break;
		case 'j':return SHOOT; break;
		default:return NOP;
	}
}
const int act_buf[] = { UP,LEFT,RIGHT,DOWN,SHOOT,NOP };
bool is_gameover = false;
int score = 0;