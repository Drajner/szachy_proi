#pragma once
#include "Chessboard.h"
#include "Player.h"


class Game
{
private:
	Chessboard chessboard_;
	Player firstPlayer_;
	Player secondPlayer_;
	Player& currentPlayer_;

	//Starts a player versus player game
	void playPvP();

	//Starts a player versus bot game
	void playPvB();
public:
	//Creates game object with given players and chessboard
	Game(Chessboard chessboard, Player firstPlayer, Player secondPlayer);

	//Chooses who will start the game
	Player& rollOrder();
	
	//Swaps current player
	void swap();

	//Check if there is a win possibility for given player
	bool checkWinPossibility(const Player& player);

	//Starts a game
	void play();

	friend std::ostream& operator<<(std::ostream& os, const Game& game);
};
