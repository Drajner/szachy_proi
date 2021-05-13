#pragma once

#include <vector>
#include <memory>
#include <iostream>
#include "piece.h"
#include "Player.h"


// TODO: change first and second to colors
class Chessboard
{
private:
	std::vector<std::unique_ptr<Piece>> firstPlayerPieces_;
	std::vector<std::unique_ptr<Piece>> secondPlayerPieces_;
public:

	//Creates a new chessboard with default Pieces setup
	Chessboard();

	//Creates a new chessboard with custom Pieces setup
	Chessboard(std::vector<std::unique_ptr<Piece>> firstPlayerPieces, std::vector<std::unique_ptr<Piece>> secondPlayerPieces);

	//Getter to first player pieces vector
	std::vector<std::unique_ptr<Piece>> firstPlayerPieces();

	//Getter to first player pieces vector
	std::vector<std::unique_ptr<Piece>> secondPlayerPieces();

	//Removes given piece from chessboard
	void removePiece(Piece& piece, Player& player);

	friend std::ostream& operator<<(std::ostream& os, const Chessboard& chessboard);

	~Chessboard();
};
