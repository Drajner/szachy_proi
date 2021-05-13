#pragma once
#include <string>
#include <vector>
#include <memory>
#include "piece.h"
#include "position.h"
class Player
{
private:
	bool color; // 0 for black, 1 for white
	std::string name;

	// TODO: Change to game/chessboard reference?
	std::vector<std::unique_ptr<Piece>> pieces;
public:
	// Player class constructor
	Player(bool isWhite, bool isComputer, std::string playerName);

	// issues a move(will change depending on derivative class)
	virtual void makeMove() =0;

	// sets color
	void setColor(bool isWhite); 

	// gets all possible movements from individual pieces
	std::vector<Position> allPossibleMoves();
	

};

