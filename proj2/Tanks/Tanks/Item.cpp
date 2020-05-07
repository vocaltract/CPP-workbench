#include "Item.h"
#include <cassert>
Item::Item(Block** blocks)
{
	from_block = blocks;
	fuck = true;
}
int Item::check_dir() const
{
	assert(0);
	return 0;
}

bool Item::validity() const
{
	assert(0);
	return false;
}
bool& Item::validity()
{
	assert(0);
	return fuck;
}