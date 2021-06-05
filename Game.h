#pragma once
#include "Chessboard.h"
#include "Player.h"
#include "color.h"
#include "position.h"
#include <memory>

class Game
{
private:
	Chessboard chessboard_;
	std::unique_ptr<Player> firstPlayer_;
	std::unique_ptr<Player> secondPlayer_;
	Player* currentPlayer_ = nullptr;

	//Starts a player versus player game
	void playPvP();

	//Starts a player versus bot game
	void playPvB();
public:
	Game();

	//Swaps current player
	void swap();

	//Starts a game
	void play();
};
