#include "MediumTank.h"
MediumTank::MediumTank(const Vector2D& inloc, Block** blocks)
	:Tank(inloc, blocks, RED)
{
	blood = 2;
	speed = 2;
}