#include "King.h"

King::King(char chr) :
	Piece(chr)
{}

bool King::valid_move(RECEIVE_FULL_COORDS, bool dstUnderThreat = false) {
	if (dstUnderThreat)
		return false;
	if (abs(srcRow - dstRow) <= 1 &&
		abs(srcCol - dstCol) <= 1)
		return true;
	return false;
}
