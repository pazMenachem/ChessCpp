#include "Queen.h"

Queen::Queen(char chr) :
	Piece(chr), Bishop(chr), Rook(chr)
{}
bool Queen::valid_move(RECEIVE_FULL_COORDS, bool irrelevant = false)
{
	return Bishop::valid_move(SEND_FULL_COORDS,irrelevant) ||
		Rook::valid_move(SEND_FULL_COORDS,irrelevant);
};