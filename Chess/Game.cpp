#include "Game.h"

Game::Game(Board& board) :
    _turn(WHITE_TURN), _source(), _dest(),
    _column_translate(), _board(board), _check(false),
    _codes(_board, _turn, _check)
{init();};

string Game::analyze_message(const string& msg)
{
    int srcRow, srcCol, dstRow, dstCol;
    string code;

    set_source_and_destination(msg);

    get_matrix_index(srcRow, srcCol, _source);
    get_matrix_index(dstRow, dstCol, _dest);   

    code = analyzeMove(SEND_FULL_COORDS);

    return code;
}

void Game::get_matrix_index(int& row, int& col, string& loc)
{
    row = 8 - stoi(loc.substr(1, 2));
    col = _column_translate.at(loc.substr(0, 1));
}

void Game::init()
{
    _column_translate["a"] = 0;
    _column_translate["b"] = 1;
    _column_translate["c"] = 2;
    _column_translate["d"] = 3;
    _column_translate["e"] = 4;
    _column_translate["f"] = 5;
    _column_translate["g"] = 6;
    _column_translate["h"] = 7;
}

void Game::change_turn()
{
    _turn = !_turn;
}

string Game::analyzeMove(RECEIVE_FULL_COORDS)
{   
    int kingRow, kingCol;

    if (_codes.non_legit_source_location(srcRow, srcCol)) // not your turn
        return ILLEGAL_MOVE_NO_PLAYER_PIECE;

    if (_codes.same_location(SEND_FULL_COORDS)) // irrelevant
        return ILLEGAL_MOVE_SAME_LOCATION;

    if (_codes.same_color_in_dest_loc(dstRow, dstCol))
        return ILLEGAL_MOVE_DESTINATION_OCCUIPED;

    if (!_codes.check_valid_move(SEND_FULL_COORDS))
        return ILLEGAL_MOVE_OF_PIECE;
    
    find_the_king(kingRow, kingCol, _turn);

    if (_codes.check_will_occur(SEND_FULL_COORDS, kingRow, kingCol))
        return ILLEGAL_MOVE_PIECE_PROTECTS_KING;

    // Move is valid from here

    _board.update_board(SEND_FULL_COORDS,
                        BOARD[srcRow][srcCol]);
    check_for_check();

    change_turn();

    if (_check)
        return LEGAL_MOVE_CHECK;

    return VALID_MOVE;
}

void Game::set_source_and_destination(const string& msg)
{
    _source = msg.substr(0, 2);
    _dest = msg.substr(2, 4);
}

void Game::find_the_king(int& row, int& col, bool color) {
    Piece* p;
    for (row = 0; row < BOARD_SIZE; row++)
        for (col = 0; col < BOARD_SIZE; col++)
        {
            p = BOARD[row][col];
            if (!p)
                continue;
            if ((KING) && SAME_COLOR)
                return;
        }
    }

void Game::check_for_check()
{
    int kingRow, kingCol;
    bool oppositeColor = !_turn;

    find_the_king(kingRow, kingCol, oppositeColor);

    if (_codes.location_is_under_threat(kingRow, kingCol, oppositeColor))
        _check = true;
    else
        _check = false;
}
