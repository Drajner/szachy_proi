#include "position.h"

Position::Position(int posX, int posY) : x_(posX), y_(posY) {}

void Position::x(int newX) { x_ = newX; }
void Position::y(int newY) { y_ = newY; }
int Position::x() const { return x_; }
int Position::y() const { return y_; }

bool Position::on_chessboard() const {
	return x_ > 0 && x_ <= 8 && y_ > 0 && y_ <= 8;
}

bool Position::operator==(const Position& other) const {
	return x_ == other.x_ && y_ == other.y_;
}
bool Position::operator!=(const Position& other) const {
	return !(*this == other);
}

Position Position::operator+(const Position& other) const {
	return Position(x_ + other.x_, y_ + other.y_);
}
Position& Position::operator+=(const Position& other) {
	x_ += other.x_;
	y_ += other.y_;

	return *this;
}
Position Position::operator-(const Position& other) const {
	return Position(x_ - other.x_, y_ - other.y_);
}
Position& Position::operator-=(const Position& other) {
	x_ -= other.x_;
	y_ -= other.y_;

	return *this;
}

std::ostream& operator<<(std::ostream& out, const Position& pos) {
	if (pos.on_chessboard()) {
		out << (char)('a' + pos.x_ - 1) << pos.y_;
		return out;
	}
	else {
		// throw exception
	}
	return out;
}
std::istream& operator>>(std::istream& in, Position& pos) {
	char a, b;
	in >> a >> b;

	if (isdigit(a)) {
		char t = a;
		a = b;
		b = t;
	}

	if (isdigit(b) && b <= '8') {
		if (a >= 'a' && a <= 'h') {
			pos.y_ = b - '0';
			pos.x_ = a - 'a';
		}
		else if (a >= 'A' && a <= 'H') {
			pos.y_ = b - '0';
			pos.x_ = a - 'A';
		}
		else {
			// throw exception
		}
	}

	return in;
}