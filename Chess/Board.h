#pragma once
#include "PieceFactory.h"
#define BOARD_SIZE 8
#define TEST

#ifdef TEST
#define GAME_RESET "rnbkqbnr#####n#################n########################RNBKQBNR0"
#else
#define GAME_RESET "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR0"
#endif;
#define WHITE 0
#define BLACK 1
enum Directions{DOWN = 2,DOWN_LEFT,LEFT,UP_LEFT,UP,UP_RIGHT,RIGHT,DOWN_RIGHT };

/*
	Board Class is inCharge for all that happens on the board itself.
	*/
class Board
{
public:

	/*
	Board Constructor.
	*/
	Board();

	/*
	Board Destructor.
	*/
	~Board();

	/*
	Checking if specified location is empty.

	Args:
	row/col - Index of the specified location.

	Returns:
	True if location empty,
	False otherwise.
	*/
	bool location_empty(int row, int col) const;

	/*
	Getter for Board field.

	Returns:
	The Piece Matrix.
	*/
	Piece*** get_board() const;

	/*
	Updates the Board.

	Args:
	srcRow, srcCol - Source index.
	dstRow, dstCol - Destination index.
	p - The piece which will be update on the board.
	*/
	void update_board(RECEIVE_FULL_COORDS, Piece* p);

	/*
	Checking if are there pieces from point A to point B on the board.

	Args:
	srcRow, srcCol - Source index.
	dstRow, dstCol - Destination index.

	Returns:
	True if none pieces were found,
	False otherwise.
	*/
	bool clear_line(RECEIVE_FULL_COORDS);

private:
	Piece*** _board;
	/*
	Initiates the class.
	*/
	void init();

	/*
	Clear line recursive method.
	Note - see Clear line description.
	*/
	bool clear_line_rec(RECEIVE_FULL_COORDS, int direction);

	/*
	Helping Method.
	Before sending the coordinations to the function "clear line", the coordinations need to be modified.

	Args:
	Row, Col - Coordinates which will be modified according to the direction.
	direction - According to the given value the row and col will be modified.

	Note - reference values.
	*/
	void modify_by_direction(int& row, int& col, int direction);

	/*
	Helping Method.
	With given Point A and Point B the function returns which direction from A to B.
	See enum "Directions".


	Args:
	srcRow, srcCol - Source index.
	dstRow, dstCol - Destination index.

	Returns:
	The direction from Source to Destination.
	*/
	int get_direction(RECEIVE_FULL_COORDS) const;

	/*
	Helping Method.
	Checking if piece is next to the specified destination coordinates.


	Args:
	srcRow, srcCol - Source index.
	dstRow, dstCol - Destination index.

	Returns:
	True if piece is next to specified coordinates.
	False otherwise.
	*/
	bool next_to_piece(RECEIVE_FULL_COORDS) const;


};


