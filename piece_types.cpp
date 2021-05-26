#include "Chessboard.h"
#include "piece_types.h"

Pawn::Pawn(Position startPosition, Color color) : Piece(startPosition, color), firstMove_(true) {}

std::string Pawn::full_name() const {
	return "Pawn";
}

char Pawn::chessboard_representation() const {
	return color() == White ? 'p' : 'P';
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
		if (chessboard.pieceExists(tryPos)) {
			try_add_movement_option(tryPos, possible, chessboard);
		}

		tryPos = pos + Position(1, 1);
		if (chessboard.pieceExists(tryPos)) {
			try_add_movement_option(tryPos, possible, chessboard);
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

		if (chessboard.pieceExists(tryPos)) {
			try_add_movement_option(tryPos, possible, chessboard);
		}

		tryPos = pos + Position(-1, 1);
		if (chessboard.pieceExists(tryPos)) {
			try_add_movement_option(tryPos, possible, chessboard);
		}
	}

	return possible;
}

void Pawn::on_moved(Position newPosition) {
	firstMove_ = false;
}

std::string Knight::full_name() const {
	return "Knight";
}

char Knight::chessboard_representation() const {
	return color() == White ? 'n' : 'N';
}

std::vector<Position> Knight::possible_moves(const Chessboard& chessboard) const {
	std::vector<Position> possible;
	for (int x = -1; x < 1; x += 1) {
		for (int y = -2; y < 2; y += 4) {
			try_add_movement_option(position() + Position(x, y), possible, chessboard);
			try_add_movement_option(position() + Position(y, x), possible, chessboard);
		}
	}

	return possible;
}

std::string Bishop::full_name() const {
	return "Bishop";
}

char Bishop::chessboard_representation() const {
	return color() == White ? 'b' : 'B';
}

std::vector<Position> Bishop::possible_moves(const Chessboard& chessboard) const {
	std::vector<Position> possible;

	// TODO: add movement

	return possible;
}

std::string Rook::full_name() const {
	return "Rook";
}

char Rook::chessboard_representation() const {
	return color() == White ? 'r' : 'R';
}

std::vector<Position> Rook::possible_moves(const Chessboard& chessboard) const {
	std::vector<Position> possible;

	// TODO: add movement

	return possible;
}

std::string Queen::full_name() const {
	return "Queen";
}

char Queen::chessboard_representation() const {
	return color() == White ? 'q' : 'Q';
}

std::vector<Position> Queen::possible_moves(const Chessboard& chessboard) const {
	std::vector<Position> possible;

	// TODO: add movement

	return possible;
}

std::string King::full_name() const {
	return "King";
}

char King::chessboard_representation() const {
	return color() == White ? 'k' : 'K';
}

std::vector<Position> King::possible_moves(const Chessboard& chessboard) const {
	std::vector<Position> possible;

	// TODO: add movement

	return possible;
}