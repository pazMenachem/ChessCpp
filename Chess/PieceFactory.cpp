#include "PieceFactory.h"

Piece* PieceFactory::createPiece(const char chr) const {
	switch (chr)
	{
	case 'b': // black Bishop
		return new Bishop(chr);
	case 'B': // white Bishop
		return new Bishop(chr);
	case 'r':// black Rook
		return new Rook(chr);
	case 'R':// white Rook
		return new Rook(chr);
	case 'q':// black Queen
		return new Queen(chr);
	case 'Q':// white Queen
		return new Queen(chr);
	case 'k':// black King
		return new King(chr);
	case 'K':// white King
		return new King(chr);
	case 'p':// black Pawn
		return new Pawn(chr);
	case 'P':// white Pawn
		return new Pawn(chr);
	case 'n':// black Knight
		return new Knight(chr);
	case 'N':// white Knight
		return new Knight(chr);
	default:
		return nullptr;
	}
}
