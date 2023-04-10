#include "Piece.h"

Piece::Piece() :
    _char()
{}

Piece::Piece(char chr) :
	_char(chr)
{}

Piece& Piece::operator=(Piece&& rhs) noexcept
{
    _char = rhs._char;
    return *this;
}

char Piece::get_char()
{
    return _char;
}

bool Piece::get_color()
{
    return !WHICH_COLOR;
}
