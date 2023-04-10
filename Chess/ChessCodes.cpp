#include "ChessCodes.h"

ChessCodes::ChessCodes(Board& board, bool& turn, bool& check) :
	_board(board), _turn(turn), _check(check) {};
bool ChessCodes::check_valid_move(RECEIVE_FULL_COORDS)
{
	// CODE 6
	Piece* p = BOARD[srcRow][srcCol];

	if (KING)
		return p->valid_move(SEND_FULL_COORDS,
			location_is_under_threat(dstRow, dstCol, _turn));

	if (PAWN)
		return pawn_unique_valid_move_check(SEND_FULL_COORDS, p);

	if (!(p->valid_move(SEND_FULL_COORDS) &&
		_board.clear_line(SEND_FULL_COORDS)))
		return false;

	return true;
}
bool ChessCodes::same_location(RECEIVE_FULL_COORDS)
{
	//CODE 7
	return (srcRow == dstRow &&
		srcCol == dstCol);
}
bool ChessCodes::non_legit_source_location(int srcRow, int srcCol)
{
	//CODE 2
	return _board.location_empty(srcRow, srcCol) ||
		_turn != BOARD[srcRow][srcCol]->get_color();
}
bool ChessCodes::same_color_in_dest_loc(int dstRow, int dstCol)
{
	//CODE 3
	if (!BOARD[dstRow][dstCol])
		return false;
	return BOARD[dstRow][dstCol]->get_color() == _turn;
}
bool ChessCodes::location_is_under_threat(int dstRow, int dstCol, bool color)
{
	int srcRow, srcCol;
	Piece* p;

	for (srcRow = 0; srcRow < BOARD_SIZE; srcRow++)
		for (srcCol = 0; srcCol < BOARD_SIZE; srcCol++)
		{
			p = BOARD[srcRow][srcCol];

			if (!p)
				continue;

			// same team
			if (p->get_color() == color)
				continue;

			// Pawn check
			if (PAWN)
				if (dynamic_cast<Pawn*>(p)->pawn_eat_check(SEND_FULL_COORDS, color))
					return true;
				

			// other pieces check
			if (p->valid_move(SEND_FULL_COORDS) &&
				_board.clear_line(SEND_FULL_COORDS))
				return true;
			
		}
	return false;
}
bool ChessCodes::pawn_unique_valid_move_check(RECEIVE_FULL_COORDS, Piece* p) {
	Piece* dstPiece = BOARD[dstRow][dstCol];

	if (dstPiece)
		return p->valid_move(SEND_FULL_COORDS, dstPiece->get_color());
	else
		return p->valid_move(SEND_FULL_COORDS, p->get_color());
}
bool ChessCodes::check_will_occur(RECEIVE_FULL_COORDS, int kingRow, int kingCol) {
	// Code 4
	bool check;
	Piece* p;

	p = BOARD[srcRow][srcCol];

	if (KING)
		return location_is_under_threat(dstRow, dstCol, p->get_color());

	if (_check)
	{
		BOARD[dstRow][dstCol] = p;

		check = location_is_under_threat(kingRow, kingCol, p->get_color());

		BOARD[dstRow][dstCol] = nullptr;
	}
	else
	{
		BOARD[srcRow][srcCol] = nullptr;

		check = location_is_under_threat(kingRow, kingCol, p->get_color());

		BOARD[srcRow][srcCol] = p;
	}


	return check;
};
