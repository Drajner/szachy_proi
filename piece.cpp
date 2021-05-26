#include "Chessboard.h"
#include "piece.h"

Piece::Piece(Position startPosition, Color color) : position_(startPosition), color_(color) {

}

Color Piece::color() const {
	return color_;
}

Position Piece::position() const {
	return position_;
}

void Piece::move_to(Chessboard& chessboard, Position newPosition) {
	position_ = newPosition;

	std::vector<std::shared_ptr<Piece>> enemyPieces = color() == White ? chessboard.blackPieces() : chessboard.whitePieces();

	for (auto piece = enemyPieces.begin(); piece != enemyPieces.end(); piece++) // TODO: Change to getting the pieces by color
	{
		if ((**piece).position_ == position_)
		{
			//chessboard.removePiece((**piece), ); // How do i get the player exactly?
		}
	}
}

void Piece::try_add_movement_option(Position pos, std::vector<Position>& positions, const Chessboard& chessboard) const {
	if (pos.x() > 0 && pos.x() <= 8 && pos.y() > 0 && pos.y() <= 8) {
		if (!chessboard.pieceExists(pos) || chessboard.getPiece(pos).color() != color()) {
			positions.push_back(pos);
		}
	}
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