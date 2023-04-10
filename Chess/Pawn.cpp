#include "Pawn.h"

Pawn::Pawn(char chr) :
	Piece(chr), _moved(false)
{}
bool Pawn::move_options(RECEIVE_FULL_COORDS) {
	if (move_two_steps(SEND_FULL_COORDS) ||
		move_one_step(SEND_FULL_COORDS))
		return true;
	return false;

}
bool Pawn::move_two_steps(RECEIVE_FULL_COORDS)
{
	if (_moved)
		return false;

	if (WHICH_COLOR)
		return srcRow - 2 == dstRow && srcCol == dstCol;
	else
		return srcRow + 2 == dstRow && srcCol == dstCol;
}
bool Pawn::move_one_step(RECEIVE_FULL_COORDS)
{
	if (WHICH_COLOR)
		return srcRow - 1 == dstRow && srcCol == dstCol;
	else
		return srcRow + 1 == dstRow && srcCol == dstCol;
}
bool Pawn::pawn_eat_move(RECEIVE_FULL_COORDS)
{
	if (WHICH_COLOR)
		// WHITE
		return (srcRow - 1 == dstRow &&
			srcCol - 1 == dstCol) ||
		(srcRow - 1 == dstRow &&
			srcCol + 1 == dstCol);
	else // BLACK
		return (srcRow + 1 == dstRow &&
			srcCol + 1 == dstCol) ||
		(srcRow + 1 == dstRow &&
			srcCol - 1 == dstCol);

}
bool Pawn::other_piece_is_different_color(bool color)
{
	return this->get_color() != color;
}
bool Pawn::valid_move(RECEIVE_FULL_COORDS, bool color = false) {
	if (pawn_eat_check(SEND_FULL_COORDS, color) ||
		move_options(SEND_FULL_COORDS))
	{
		_moved = true;
		return true;
	}
	return false;
}
