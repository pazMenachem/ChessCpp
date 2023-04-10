cmake_minimum_required(VERSION 3.20)
project(Chess)

set(CMAKE_CXX_STANDARD 14)

include_directories(Chess)

add_executable(Chess
        Chess/Bishop.h
        Chess/Board.cpp
        Chess/Board.h
        Chess/ChessCodes.cpp
        Chess/ChessCodes.h
        Chess/Game.cpp
        Chess/Game.h
        Chess/King.h
        Chess/Knight.h
        Chess/Manager.cpp
        Chess/Manager.h
        Chess/Pawn.h
        Chess/Piece.cpp
        Chess/Piece.h
        Chess/PieceFactory.cpp
        Chess/PieceFactory.h
        Chess/Pipe.h
        Chess/Queen.h
        Chess/Rook.cpp
        Chess/Rook.h
        Chess/Source.cpp
        Chess/stdafx.cpp
        Chess/stdafx.h
        Chess/targetver.h)
