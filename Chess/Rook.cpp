#include "Rook.h"

Rook::Rook(char chr) :
	Piece(chr)
{}

bool Rook::valid_move(RECEIVE_FULL_COORDS, bool irrelevant = false)
{
		if (srcRow == dstRow ||
			srcCol == dstCol)
			return true;
		return false;
};

