#pragma once
#include "Chessboard.h"
#include "Player.h"
#include "color.h"
#include "position.h"
#include <memory>

class Game
{
public:
	Chessboard chessboard_;
	std::unique_ptr<Player> firstPlayer_;
	std::unique_ptr<Player> secondPlayer_;
	Player* currentPlayer_ = nullptr;

	//Starts a player versus player game
	void playPvP();

	//Starts a player versus bot game
	void playPvB();
public:
	//Creates game object with given players and chessboard
	//Game(Chessboard chessboard, Player* firstPlayer, Player* secondPlayer);
	Game();

	//Chooses who will start the game
	void rollOrder();

	//Swaps current player
	void swap();

	//Check if there is a win possibility for given player
	//bool checkWin(Player& player);

	//bool checkIfCheck(Player& player, Color color);

	//Starts a game
	void play();
};
