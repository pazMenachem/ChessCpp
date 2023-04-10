#include "Manager.h"

Manager::Manager() :
	_board(), _messageToGraph(GAME_RESET), _pipe(), _messageFromGraphics()
{
	init();
}

void Manager::init()
{
	srand(time_t(NULL));

	//open graphics
	std::system("explorer chessGraphics.exe ");
	Sleep(2000);//wait

	bool isConnect = _pipe.connect();

	string ans;
	while (!isConnect)
	{
		cout << "cant connect to graphics" << endl;
		cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
		std::cin >> ans;

		if (ans == "0")
		{
			cout << "trying connect again.." << endl;
			Sleep(5000);
			isConnect = _pipe.connect();
		}
		else
		{
			_pipe.close();
			return;
		}
	}
}

void Manager::send_message_to_graphics()
{
	_pipe.sendMessageToGraphics(MSG_TO_GRAPHIC);
}

void Manager::get_message_from_graphics()
{
	_messageFromGraphics = _pipe.getMessageFromGraphics();
}

void Manager::set_message(string msg)
{
	_messageToGraph = msg;
}

void Manager::play_game()
{
	Game game(_board);
	do {
		send_message_to_graphics();
		get_message_from_graphics();

		set_message(game.analyze_message(_messageFromGraphics));

	} while (_messageFromGraphics != QUIT);

	_pipe.close();
}
