#pragma once
#include <string>
#include <vector>
#include <memory>
#include "piece.h"
#include "position.h"

class Piece;

class Chessboard;

class Player
{
private:
	Color color_;
	std::string name_;
	Player* enemy_ = nullptr;

public:
	// Player class constructor
	Player(Color color, std::string playerName, const Chessboard& chessboard);

	// issues a move(will change depending on derivative class)
	virtual void makeMove(Chessboard& chessboard) = 0;

	// issues the upgrade of the pawn if available(will change depending on derivative class)
	virtual void doAvailableUpgrades(Chessboard& chessboard) = 0;

	// sets color
	void setColor(Color color);

	// sets enemy
	void setEnemy(Player* enemy);

	// gets name
	std::string getName();

	// gets enemy
	Player* getEnemy();

	// gets name
	Color getColor();

	// gets all possible movements from individual pieces
	std::vector<std::pair<std::shared_ptr<Piece>, Position>> allPossibleMoves(const Chessboard& chessboard);

	// checks if players are the same
	bool operator==(Player& player);

};

class Human : public Player
{
public:
	// Human class constructor ( the same as Player class constructor)
	Human(Color color, std::string playerName, const Chessboard& chessboard) : Player(color, playerName, chessboard) {};

	// shows possible moves on console and makes user choose one
	void makeMove(Chessboard& chessboard) override;

	// gives user option to choose figure to which pawn will be upgraded
	void doAvailableUpgrades(Chessboard& chessboard) override;

};

class RandIntBot : public Player
{
public:
	// RandIntBot class constructor ( the same as Player class constructor)
	RandIntBot(Color color, std::string playerName, const Chessboard& chessboard) : Player(color, playerName, chessboard) {};

	// issues random move for the bot player
	void makeMove(Chessboard& chessboard) override;

	// upgrades pawn to the queen, because its the most optimal choice
	void doAvailableUpgrades(Chessboard& chessboard) override;

};

