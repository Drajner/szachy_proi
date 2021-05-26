#include "Chessboard.h"
#include "piece_types.h"

Pawn::Pawn(Position startPosition, Color color) : Piece(startPosition, color), firstMove_(true) {}

std::string Pawn::full_name() const {
	return "Pawn";
}

char Pawn::chessboard_representation() const {
	return 'i';
}

std::vector<Position> Pawn::possible_moves(const Chessboard& chessboard) const {
	std::vector<Position> possible;
	Position pos = position();

	if (color() == White) {
		
		if (pos.y() < 8) {
			possible.push_back(pos + Position(1, 0));
		}

		if (firstMove_ && pos.y() < 7) {
			possible.push_back(pos + Position(2, 0));
		}

		auto tryPos = pos + Position(1, -1);
		if (chessboard.getPiece(tryPos).color() == Black) {
			possible.push_back(tryPos);
		}

		tryPos = pos + Position(1, 1);
		if (chessboard.getPiece(tryPos).color() == Black) {
			possible.push_back(tryPos);
		}
	}
	else {
		Position pos = position();
		if (pos.y() > 1) {
			possible.push_back(pos + Position(-1, 0));
		}

		if (firstMove_ && pos.y() > 2) {
			possible.push_back(pos + Position(-2, 0));
		}

		auto tryPos = pos + Position(-1, -1);

		if (chessboard.getPiece(tryPos).color() == White) {
			possible.push_back(tryPos);
		}

		tryPos = pos + Position(-1, 1);
		if (chessboard.getPiece(tryPos).color() == White) {
			possible.push_back(tryPos);
		}
	}
}

void Pawn::on_moved(Position newPosition) {
	firstMove_ = false;
}