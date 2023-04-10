#pragma once
#include "Board.h"

#define VALID_MOVE "00"
#define LEGAL_MOVE_CHECK "01"
#define ILLEGAL_MOVE_NO_PLAYER_PIECE "02"
#define ILLEGAL_MOVE_DESTINATION_OCCUIPED "03"
#define ILLEGAL_MOVE_PIECE_PROTECTS_KING "04"
#define ILLEGAL_MOVE_OUT_OF_BOUNDS "05" // Irrelevant
#define ILLEGAL_MOVE_OF_PIECE "06"
#define ILLEGAL_MOVE_SAME_LOCATION "07"
#define LEGAL_MOVE_CHECK_MATE "08"
#define WHITE_TURN 0
#define BLACK_TURN 1
#define PAWN p->get_char() == 'p' || p->get_char() == 'P'
#define KING p->get_char() == 'k' || p->get_char() == 'K'
#define SAME_COLOR p->get_color() == color

/*
Chess Codes class purpose is to check the specific Game codes, in other words, the class checks the 
game rules.
each code is mentioned in each method.
*/
class ChessCodes {
public:

	/*
	Chess Code Constructor.

	Args:
	board - the board game which is currently being played at.
	turn - turn of the player.
	check - whether the status "check" is active or not.

	NOTE - all fields are references.
	*/
	ChessCodes(Board& board, bool& turn, bool& check);

	/*
	Checking whether the move is valid.
	Code 0.

	Args:
	srcRow, srcCol - Source index of the location which is being checked.
	dstRow, dstCol - Destination index of the location which is being checked.

	Returns:
	True if move is valid,
	False otherwise.
	*/
	bool check_valid_move(RECEIVE_FULL_COORDS);

	/*
	Checks whether source location and destination location is the same.
	Code 7.

	Args:
	srcRow, srcCol - Source index of the location which is being checked.
	dstRow, dstCol - Destination index of the location which is being checked.

	Returns:
	True if same location,
	False otherwise.
	*/
	bool same_location(RECEIVE_FULL_COORDS);

	/*
	Checks whether source location is not empty nor piece of the current player.
	Code 2.

	Args:
	srcRow, srcCol - Source index of the location which is being checked.

	Returns:
	True if location is empty or piece of opposite player is in place,
	False otherwise.
	*/
	bool non_legit_source_location(int srcRow, int srcCol);

	/*
	Checks if the destination location contains piece of the same color.
	Code 3.

	Args:
	dstRow, dstCol - Destination index of the location which is being checked.

	Returns:
	True if destination has the same colored piece,
	False otherwise or destination is null.
	*/
	bool same_color_in_dest_loc(int dstRow, int dstCol);

	/*

	Checking the pawn's unique "eating" move.
	Pawn "eating" move is to right and left, where regular moving is only forward

	Args:
	srcRow, srcCol - Source index of the location which is being checked.
	dstRow, dstCol - Destination index of the location which is being checked.
	p - piece to the right or left of the pawn, if none exists it will send the checked pawn.

	Returns:
	True if valid move,
	False otherwise.
	*/
	bool pawn_unique_valid_move_check(RECEIVE_FULL_COORDS, Piece* p);

	/*
	Checking whether the specified point is under threat by the
	opposite player.

	Args:
	dstRow, dstCol - index of the location which is being checked
	color - the color of the CURRENT team

	Returns:
	True if some piece is able to reach the location,
	False otherwise.
	*/
	bool location_is_under_threat(int dstRow, int dstCol, bool color);

	/*
	Checks whether "check" will occur BEFORE the board is updated.
	Code 4.

	Args:
	srcRow, srcCol - Source index of the location which is being checked.
	dstRow, dstCol - Destination index of the location which is being checked.
	KingCol\Row - the current position of the king which being checked.

	Returns:
	True if "check" will occur,
	False otherwise.
	*/
	bool check_will_occur(RECEIVE_FULL_COORDS, int kingRow, int kingCol);

private:
	Board& _board;
	bool& _turn;
	bool& _check;

#define BOARD _board.get_board()
};