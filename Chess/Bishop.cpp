#include "Bishop.h"

Bishop::Bishop(char chr) :
	Piece(chr)
{}

bool Bishop::valid_move(RECEIVE_FULL_COORDS, bool irrelevant = false) {
	int x = srcRow - dstRow;
	int y = srcCol - dstCol;
	if (!x || !y)
		return false;
	return abs((x) / (y)) == 1;
};
