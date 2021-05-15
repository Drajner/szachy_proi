#pragma once

#include "piece.h"

class Pawn : public Piece {
protected:
	bool firstMove_;
public:
	std::string full_name() const override;

	char chessboard_representation() const override;

	std::vector<Position> possible_moves(const Chessboard& chessboard) const override;
};

class Knight : public Piece {
	std::string full_name() const override;

	char chessboard_representation() const override;

	std::vector<Position> possible_moves(const Chessboard& chessboard) const override;
};

class Bishop : public Piece {
	std::string full_name() const override;

	char chessboard_representation() const override;

	std::vector<Position> possible_moves(const Chessboard& chessboard) const override;
};

class Rook : public Piece {
	std::string full_name() const override;

	char chessboard_representation() const override;

	std::vector<Position> possible_moves(const Chessboard& chessboard) const override;
};

class Queen : public Piece {
	std::string full_name() const override;

	char chessboard_representation() const override;

	std::vector<Position> possible_moves(const Chessboard& chessboard) const override;
};

class King : public Piece {
	std::string full_name() const override;

	char chessboard_representation() const override;

	std::vector<Position> possible_moves(const Chessboard& chessboard) const override;
};

