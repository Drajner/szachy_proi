#include "Chessboard.h"
#include "piece_types.h"

std::string Pawn::full_name() const {
	return "Pawn";
}

char Pawn::chessboard_representation() const {
	return 'i';
}

std::vector<Position> Pawn::possible_moves(const Chessboard& chessboard) const {
	std::vector<Position> possible;

	if (color() == White) {
		Position pos = position();
		if (pos.y() < 8) {
			possible.push_back(pos + Position(1, 0));
		}

		if (false) { // Add chessboard turn number?
			possible.push_back(pos + Position(2, 0));
		}

		// TODO: add diagonals
	}
	else {
		// TODO: add inverted moves for black
	}
}