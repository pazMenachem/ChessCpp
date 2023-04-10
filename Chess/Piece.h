#pragma once

#include <iostream>
#include <string>

using namespace std;

#define WHITE 0
#define BLACK 1
#define RECEIVE_FULL_COORDS int srcRow, int srcCol, int dstRow, int dstCol
#define SEND_FULL_COORDS srcRow, srcCol, dstRow, dstCol
#define WHICH_COLOR isupper(get_char())

/*
	Piece Class is an abstract class.
	Base class for chess pieces.
*/
class Piece {
public:
	/*
	Piece Class Default Constructor.
	*/
	Piece();

	/*
	Piece Class Constructor.
	With given Char.
	*/
	Piece(char chr);

	/*
	Copy Constructor (default).
	*/
	Piece(const Piece& rhs) = default;

	/*
	= Move Operator (default).
	*/
	Piece& operator=(Piece&& rhs) noexcept;

	/*
	= Move Operator (default).
	*/
	Piece& operator=(Piece& rhs) = default;

	/*
	Piece Destructor (default).
	*/
	virtual ~Piece() = default;

	/*
	Abstract Method.
	With given Coordinations the function checks whether the move or valid or not, depends on the piece.

	Args:
	srcRow, srcCol - Source index of the location which is being checked.
	dstRow, dstCol - Destination index of the location which is being checked.
	color - relevant for Pawn and King.

	Returns:
	True if valid,
	False otherwise.
	*/
	virtual bool valid_move(RECEIVE_FULL_COORDS, bool color = false) = 0;

	/*
	Getter for the piece letter.

	Returns:
	The char of the letter.
	*/
	virtual char get_char();

	/*
	Getter for the piece color.

	Returns:
	The color of the piece.
	1 - for BLACK.
	0 - for WHITE.
	*/
	bool get_color();

private:
	char _char;	

};
