#pragma once
#include "Tank.h"
class HeavyTank :
	public Tank
{
public:
	HeavyTank(const Vector2D& inloc, Block** blocks);
};

