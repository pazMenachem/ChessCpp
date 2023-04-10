#include "Knight.h"

Knight::Knight(char chr) :
	Piece(chr)
{}

bool Knight::valid_move(RECEIVE_FULL_COORDS, bool irrelevant = false) {
	return sqrt(pow(srcRow - dstRow, 2) +
		pow(srcCol - dstCol, 2)) ==
		KNIGHT_MOVE_DISTANCE;
};
