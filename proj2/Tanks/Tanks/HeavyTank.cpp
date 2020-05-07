#include "HeavyTank.h"
HeavyTank::HeavyTank(const Vector2D& inloc, Block** blocks)
	:Tank(inloc, blocks, GREEN)
{
	blood = 3;
	speed = 1;
}