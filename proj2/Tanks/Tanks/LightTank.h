#pragma once
#include "Tank.h"
class LightTank :
	public Tank
{
public:
	LightTank(const Vector2D& inloc, Block** blocks);
};

