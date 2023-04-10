#pragma once
#include "Piece.h"
/*
	Piece inherited class.
	Rook Piece, one of the chess pieces.
*/
class Rook :virtual public Piece {
public:
	/*
	Rook Class Constructor.
	With given Char.
	*/
	Rook(char chr);

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


