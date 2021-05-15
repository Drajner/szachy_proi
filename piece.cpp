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

	std::vector<std::unique_ptr<Piece>> enemyPieces = chessboard.firstPlayerPieces();

	for (auto piece = enemyPieces.begin(); piece != enemyPieces.end(); piece++) // TODO: Change to getting the pieces by color
	{
		if ((**piece).position_ == position_)
		{
			//chessboard.removePiece((**piece), ); // How do i get the player exactly?
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