#pragma once
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"

/*
	Piece Factory is a Method class designed to create and send back Piece inherited class.
	*/
class PieceFactory
{
public:

	/*
	Creates and send back address of new Piece inherited class.	
	Args:
	chr - decides which class is being created as following:
	b - Bishop
	r - Rook
	q - Queen
	k - King
	p - Pawn
	n - Knight

	NOTE - Capital letters for WHITE pieces,
			lower for BLACK pieces.
	Returns:
	address of new Piece inherited class
	*/
	Piece* createPiece(const char chr) const;
};

