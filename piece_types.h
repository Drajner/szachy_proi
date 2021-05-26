//#pragma once
//
//#include "piece.h"
//
//class Pawn : public Piece {
//protected:
//	bool firstMove_;
//public:
//	Pawn(Position startPosition, Color color);
//	std::string full_name() const override;
//
//	char chessboard_representation() const override;
//
//	void on_moved(Position newPosition) override;
//
//	std::vector<Position> possible_moves(const Chessboard& chessboard) const override;
//};
//
//class Knight : public Piece {
//public:
//	Knight(Position startPosition, Color color) : Piece(startPosition, color) {}
//
//	std::string full_name() const override;
//
//	char chessboard_representation() const override;
//
//	std::vector<Position> possible_moves(const Chessboard& chessboard) const override;
//};
//
//class Bishop : public Piece {
//public:
//	Bishop(Position startPosition, Color color) : Piece(startPosition, color) {}
//
//	std::string full_name() const override;
//
//	char chessboard_representation() const override;
//
//	std::vector<Position> possible_moves(const Chessboard& chessboard) const override;
//};
//
//class Rook : public Piece {
//public:
//	Rook(Position startPosition, Color color) : Piece(startPosition, color) {}
//
//	std::string full_name() const override;
//
//	char chessboard_representation() const override;
//
//	std::vector<Position> possible_moves(const Chessboard& chessboard) const override;
//};
//
//class Queen : public Piece {
//public:
//	Queen(Position startPosition, Color color) : Piece(startPosition, color) {}
//
//	std::string full_name() const override;
//
//	char chessboard_representation() const override;
//
//	std::vector<Position> possible_moves(const Chessboard& chessboard) const override;
//};
//
//class King : public Piece {
//public:
//	King(Position startPosition, Color color) : Piece(startPosition, color) {}
//
//	std::string full_name() const override;
//
//	char chessboard_representation() const override;
//
//	std::vector<Position> possible_moves(const Chessboard& chessboard) const override;
//};
//
