#pragma once
#include "Piece.h"

/*
	Piece inherited class.
	King Piece, one of the chess pieces.
*/
class King : public Piece {
public:

	/*
	King Class Constructor.
	With given Char.
	*/
	King(char chr);

		/*
	With given Coordinations the function checks whether the move or valid or not,
	depends on the piece.

	Args:
	srcRow, srcCol - Source index of the location which is being checked.
	dstRow, dstCol - Destination index of the location which is being checked.
	dstUnderThreat - determined before, if false, will prevent the move of the king.


	Returns:
	True if valid,
	False otherwise.
	*/
	bool valid_move(RECEIVE_FULL_COORDS, bool dstUnderThreat);
};