#pragma once

#include <vector>
#include <memory>
#include <iostream>
#include "piece.h"
#include "Player.h"
#include "piece_types.h"
#include "color.h"

// TODO: change first and second to colors
class Chessboard
{
private:
	std::vector<std::shared_ptr<Piece>> whitePieces_;
	std::vector<std::shared_ptr<Piece>> blackPieces_;
	int round_;
public:

	//Creates a new chessboard with default Pieces setup
	Chessboard();

	//Creates a new chessboard with custom Pieces setup
	Chessboard(std::vector<std::shared_ptr<Piece>> firstPlayerPieces, std::vector<std::shared_ptr<Piece>> secondPlayerPieces);

	//Getter to first player pieces vector
	std::vector<std::shared_ptr<Piece>> const& whitePieces() const;

	//Getter to first player pieces vector
	std::vector<std::shared_ptr<Piece>> const& blackPieces() const;

	//Removes given piece from chessboard
	void removePiece(Piece& piece, Color& color);

	Piece& getPiece(const Position& position) const;

	bool pieceExists(const Position& position) const;

	int round();

	void incRound();

	void printLine(int lineNumber, int firstColor, int secondColor, std::ostream& os) const; 

	friend std::ostream& operator<<(std::ostream& os, const Chessboard& chessboard);
};
