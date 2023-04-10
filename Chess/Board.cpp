#include "Board.h"

Board::Board() :
    _board(new Piece ** [BOARD_SIZE])
{
    init();
}
Board::~Board()
{
    //releasing the memory

    int index,col,row;

    for (row = 0; row < BOARD_SIZE; row++)
        for (col = 0; col < BOARD_SIZE; col++)
            delete _board[row][col];

    for (index = 0; index < BOARD_SIZE; index++)
        delete[] _board[index];
    delete[] _board;
}
void Board::init()
{   
    PieceFactory factory;
    Piece* piece;
    int index, row;
    
    for (row = 0; row < BOARD_SIZE; row++)
        _board[row] = new Piece*[BOARD_SIZE];

    // Creating the pieces
    for (index = 0; index < 64; index++)
    {
        piece = factory.createPiece(GAME_RESET[index]);

        piece ? _board[index / 8][index % 8] = piece :
                _board[index / 8][index % 8] = nullptr;
    }
}
bool Board::location_empty(int row, int col) const
{
    return !(_board[row][col]);
}
Piece*** Board::get_board() const
{
    return _board;
}
int Board::get_direction(RECEIVE_FULL_COORDS) const
{
    int row = srcRow - dstRow,
        col = srcCol - dstCol;

    if (!row) // Pieces on the same ROW.
        if (srcCol < dstCol) // dst piece is on the RIGHT from src.
            return RIGHT;
        else
            return LEFT; // dst piece is on the LEFT from src.

    if(!col) // Pieces on the same COL.
        if (srcRow < dstRow) // dst piece is BELOW src.
            return DOWN;
        else
            return UP; // dst piece is ABOVE src.

    if (srcRow < dstRow &&
        srcCol < dstCol)
        return DOWN_RIGHT;

    if (srcRow > dstRow &&
        srcCol < dstCol)
        return UP_RIGHT;

    if (srcRow > dstRow &&
        srcCol > dstCol)
        return UP_LEFT;

    if (srcRow < dstRow &&
        srcCol > dstCol)
    return DOWN_LEFT;
}
bool Board::next_to_piece(RECEIVE_FULL_COORDS)  const
{
    if (abs(srcRow - dstRow) == 1 ||
        abs(srcCol - dstCol) == 1)
        return true;
    return false;
}
void Board::update_board(RECEIVE_FULL_COORDS, Piece* p)
{
    delete _board[dstRow][dstCol];
    _board[srcRow][srcCol] = nullptr;
    _board[dstRow][dstCol] = p;
}
void Board::modify_by_direction(int& row, int& col, int direction) {
    switch (direction)
    {
    case DOWN:
        row+=1;
        break;

    case UP:
        row-=1;
        break;

    case LEFT:
        col-=1;
        break;

    case RIGHT:
        col+=1;
        break;

    case UP_LEFT:
        col-=1;
        row-=1;
        break;

    case UP_RIGHT:
        row-=1;
        col+=1;
        break;

    case DOWN_LEFT:
        row+=1;
        col-=1;
        break;

    case DOWN_RIGHT:
        row+=1;
        col+=1;
        break;

    default:
        return;
    }
}
bool Board::clear_line(RECEIVE_FULL_COORDS)
{
    if (next_to_piece(SEND_FULL_COORDS))
        return true;
    
    int direction = get_direction(SEND_FULL_COORDS),
        row = srcRow, col = srcCol;

    modify_by_direction(row, col, direction);
    return clear_line_rec(row, col, dstRow, dstCol, direction);
};
bool Board::clear_line_rec(RECEIVE_FULL_COORDS, int direction){
    if (srcRow == dstRow &&
        srcCol == dstCol)
        return true;

    if (!location_empty(srcRow, srcCol))
        return false;

    modify_by_direction(srcRow, srcCol, direction);
    return clear_line_rec(SEND_FULL_COORDS, direction);
};