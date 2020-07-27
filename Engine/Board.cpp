#include "Board.h"

void Board::draw(const Location& spot, const Color& c) const
{
	(*gfx).DrawRectDim(spot.x, spot.y, dimension, dimension, c);
}
