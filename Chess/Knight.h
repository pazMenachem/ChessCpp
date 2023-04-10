#pragma once
#include "Piece.h"
#include <cmath>

#define KNIGHT_MOVE_DISTANCE sqrt(5)
/*
	Piece inherited class.
	Knight Piece, one of the chess pieces.
*/
class Knight : public Piece {
public:

	/*
	Knight Class Constructor.
	With given Char.
	*/
	Knight(char chr);

	/*
	With given Coordinations the function checks whether the move or valid or not,
	depends on the piece.

	Args:
	srcRow, srcCol - Source index of the location which is being checked.
	dstRow, dstCol - Destination index of the location which is being checked.
	color - relevant for Pawn and King.

	Returns:
	True if valid,
	False otherwise.
	*/
	bool valid_move(RECEIVE_FULL_COORDS, bool irrelevant);
};