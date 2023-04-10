#pragma once
#include "Pipe.h"
#include "Game.h"


#define QUIT "quit"
#define MSG_TO_GRAPHIC const_cast<char*>(_messageToGraph.c_str())

/*
	Manager class purpose is to initiate the game graphic connection and active the game itself.
*/
class Manager{
public:
	/*
	Manager Constructor.
	*/
	Manager();
	/*
	Main function, initiates the chess game.
	*/
	void play_game();

private:
	Board _board;
	string _messageToGraph;
	Pipe _pipe;
	string _messageFromGraphics;

	/*
	initiates the class.
	*/
	void init();

	/*
	Send message to the graphics through the pipe.
	*/
	void send_message_to_graphics();

	/*
	Receive message from graphics through the pipe.
	*/
	void get_message_from_graphics();

	/*
	Sets message.

	Args:
	msg - four letters string from graphic or two letter string ("Code") to graphic.
	*/
	void set_message(string msg);
};

