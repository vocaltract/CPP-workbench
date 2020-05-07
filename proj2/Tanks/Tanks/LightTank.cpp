#include "LightTank.h"
LightTank::LightTank(const Vector2D& inloc,Block** blocks)
	:Tank(inloc,blocks,BLUE)
{
	blood = 1;
	speed = 3;
}