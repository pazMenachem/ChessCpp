#pragma once
#include "Piece.h"

/*
	Piece inherited class.
	Pawn Piece, one of the chess pieces.
*/
class Pawn : public Piece {
public:

	/*
	Pawn Class Constructor.
	With given Char.
	*/
	Pawn(char chr);

	/*
	Checking if any move option is valid.

	Args:
	srcRow, srcCol - Source index of the location which is being checked.
	dstRow, dstCol - Destination index of the location which is being checked.

	Returns:
	True if move is valid,
	False otherwise.
	*/
	bool move_options(RECEIVE_FULL_COORDS);

	/*
	Checking if Two steps ahead is valid.
	Relevant only for the if pawn didn't moved.

	Args:
	srcRow, srcCol - Source index of the location which is being checked.
	dstRow, dstCol - Destination index of the location which is being checked.

	Returns:
	True if move is valid,
	False otherwise.
	*/
	bool move_two_steps(RECEIVE_FULL_COORDS);

	/*
	Checking if one step ahead move is valid.

	Args:
	srcRow, srcCol - Source index of the location which is being checked.
	dstRow, dstCol - Destination index of the location which is being checked.

	Returns:
	True if move is valid,
	False otherwise.
	*/
	bool move_one_step(RECEIVE_FULL_COORDS);

	/*
	Checking if Pawn eat move is valid.

	Args:
	srcRow, srcCol - Source index of the location which is being checked.
	dstRow, dstCol - Destination index of the location which is being checked.

	Returns:
	True if move is valid,
	False otherwise.
	*/
	bool pawn_eat_move(RECEIVE_FULL_COORDS);

	/*
	Checking if given color is the same color as the pawn.

	Args:
	color - the color of the given piece.

	Returns:
	True if same,
	False otherwise.
	*/
	bool other_piece_is_different_color(bool color);

	/*
	Checking if eating is valid.

	Args:
	srcRow, srcCol - Source index of the location which is being checked.
	dstRow, dstCol - Destination index of the location which is being checked.
	color - the color of the given piece.

	Returns:
	True if valid,
	False otherwise.
	*/
	bool pawn_eat_check(RECEIVE_FULL_COORDS, bool color)
	{
		return pawn_eat_move(SEND_FULL_COORDS) &&
			other_piece_is_different_color(color);
	}

	/*
	With given Coordinations the function checks whether the move or valid or not,
	depends on the piece.

	Args:
	srcRow, srcCol - Source index of the location which is being checked.
	dstRow, dstCol - Destination index of the location which is being checked.
	color - The color of the piece which may be relevant, pawn will send its own
	color if none piece is relevant to be checked.

	Returns:
	True if valid,
	False otherwise.
	*/
	bool valid_move(RECEIVE_FULL_COORDS, bool color);

private:
	bool _moved;
};