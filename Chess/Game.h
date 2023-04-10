#pragma once

#include "ChessCodes.h"
#include <unordered_map>

#define LETTERS_MAP unordered_map<string,int> 

/*
	Main class which controls the chess Game.
*/
class Game
{
public:
	/*
	Game Constructor.

	Args:
	board - main game board.
	Note - All args are references.
	*/
	Game(Board& board);

	/*
	Main method of the class.
	Analyzes the MESSAGE, sends back Code accordance to specified move (the message).

	Args:
	string - the message which will be analyzed, example : "e4f2".

	Returns:
	String which contains Code, example : "10", "20" etc...
	*/
	string analyze_message(const string&);

	/*
	The function receives string of a specified location within the matrix, example :"e4",
	and translate it into proper integer values.

	Args:
	row - The row of the matrix.
	col - The col of the matrix.
	loc - The location which will be translated.

	Note - The function returns none, but in order to change two values,
	the integer values are passed by references.
	*/
	void get_matrix_index(int& row, int& col, string& loc);

	/*
	Function which helps initiates the class.
	*/
	void init();

	/*
	Changes the players turn.
	*/
	void change_turn();

	/*
	Analyzes the MOVE, sends back Code accordance to specified move (the message).

	Args:
	srcRow, srcCol - Source index of the location which is being checked.
	dstRow, dstCol - Destination index of the location which is being checked.

	Returns:
	String which contains Code, example : "10", "20" etc...
	*/
	string analyzeMove(RECEIVE_FULL_COORDS);

	/*
	Setter for fields.

	Args:
	msg - the string which will be analyzed, example : "e4a2".
	*/
	void set_source_and_destination(const string& msg);

	/*
	With given color the function finds the King piece.

	Args:
	color - color of the king which wanted to be found.
	srcRow,srcCol - index of the location.
	Note - srcRow\Col are given by references in order to change both of them in same function.
	*/
	void find_the_king(int& srcRow, int& srcCol, bool color);

	/*
	Checking for "check" status on the OPPOSITE player.
	*/
	void check_for_check();

private:
	bool _turn;
	string _source;
	string _dest;
	LETTERS_MAP _column_translate;
	Board& _board;
	bool _check;
	ChessCodes _codes;
};
