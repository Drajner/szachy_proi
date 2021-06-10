#include "Chessboard.h"
#include "piece.h"

Piece::Piece(Position startPosition, Color color) : position_(startPosition), color_(color), moved_(false) {

}

Color Piece::color() const {
	return color_;
}

Position Piece::position() const {
	return position_;
}

bool Piece::moved() const {
	return moved_;
}

void Piece::move_to(Chessboard& chessboard, Position newPosition) {
	if (chessboard.pieceExists(newPosition) && chessboard.getPiece(newPosition).color() != color_) {
		chessboard.removePiece(chessboard.getPiece(newPosition), color_ == White ? Black : White);
	}

	position_ = newPosition;

	moved_ = true;
}

bool Piece::try_add_movement_option(Position pos, std::vector<Position>& positions, const Chessboard& chessboard) const {
	if (pos.on_chessboard() && pos != position_) {
		if (chessboard.pieceExists(pos))
		{
			if (chessboard.getPiece(pos).color() != color())
			{
				positions.push_back(pos);
			}
			return false;
		}
		else
		{
			positions.push_back(pos);
			return true;
		}
	}

	return false;
}

bool Piece::operator==(const Piece& other) const {
	return full_name() == other.full_name() && position_ == other.position_ && color_ == other.color_;
}

bool Piece::operator!=(const Piece& other) const {
	return !(*this == other);
}

std::ostream& operator<<(std::ostream& out, const Piece& piece) {
	out << piece.chessboard_representation();
	return out;
}

Pawn::Pawn(Position startPosition, Color color) : Piece(startPosition, color, "Pawn") {}

std::string Pawn::full_name() const {
	return "Pawn";
}

char Pawn::chessboard_representation() const {
	return color() == White ? 'p' : 'P';
}

std::vector<Position> Pawn::possible_moves(const Chessboard& chessboard) const {
	std::vector<Position> possible;
	Position pos = position();

	int forwardDirection = color() == White ? 1 : -1;

	Position forwardPos = pos + Position(0, forwardDirection);
	if (!chessboard.pieceExists(forwardPos) && forwardPos.on_chessboard())
	{
		try_add_movement_option(forwardPos, possible, chessboard);

		forwardPos += Position(0, forwardDirection);
		if (!moved_ && !chessboard.pieceExists(forwardPos) && forwardPos.on_chessboard()) {
			try_add_movement_option(forwardPos, possible, chessboard);
		}
	}

	auto tryPos = pos + Position(-1, forwardDirection);
	if (chessboard.pieceExists(tryPos)) {
		try_add_movement_option(tryPos, possible, chessboard);
	}

	tryPos = pos + Position(1, forwardDirection);
	if (chessboard.pieceExists(tryPos)) {
		try_add_movement_option(tryPos, possible, chessboard);
	}

	return possible;
}

std::string Knight::full_name() const {
	return "Knight";
}

char Knight::chessboard_representation() const {
	return color() == White ? 'n' : 'N';
}

std::vector<Position> Knight::possible_moves(const Chessboard& chessboard) const {
	std::vector<Position> possible;
	for (int x = -1; x <= 1; x += 2) {
		for (int y = -2; y <= 2; y += 4) {
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

	for (int x = -1; x <= 1; x += 2) {
		for (int y = -1; y <= 1; y += 2) {
			Position pos = position();

			while (try_add_movement_option(pos += Position(x, y), possible, chessboard)) {}
		}
	}

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
	Position pos = position();
	Position newPos = pos;
	Position deltas[4] = { Position(1, 0), Position(0, 1), Position(-1, 0), Position(0, -1) };

	for (auto delta : deltas) {
		while (try_add_movement_option(newPos += delta, possible, chessboard)) {}
		newPos = pos;
	}

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

	for (int x = -1; x <= 1; x++) {
		for (int y = -1; y <= 1; y++) {
			if (!(x == 0 && y == 0)) {
				Position pos = position();

				while (try_add_movement_option(pos += Position(x, y), possible, chessboard)) {}
			}
		}
	}

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

	for (int x = -1; x <= 1; x++) {
		for (int y = -1; y <= 1; y++) {
			Position pos(position_.x() + x, position_.y() + y);
			try_add_movement_option(pos, possible, chessboard);
		}
	}

	return possible;
}