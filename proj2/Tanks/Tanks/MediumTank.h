#pragma once
#include "Tank.h"
class MediumTank :
	public Tank
{
public:
	MediumTank(const Vector2D& inloc, Block** blocks);
};

