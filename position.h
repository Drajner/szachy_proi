#pragma once
#include <iostream>

// Stores a position on the chessboard. Will limit positions to the range of 1-8, a-h
struct Position {
private:
	int x_;
	int y_;
public:
	Position(int posX, int posY);

	// Sets the horizontal position. Will clamp it in the 1-8 range
	void x(int newX);
	// Sets the vertical position. Will clamp it in the 1-8 range
	void y(int newY);
	// Gets the horizontal position in int form
	int x() const;
	// Gets the vertical position in int form
	int y() const;

	// Compares two positions by x and y
	bool operator==(const Position& other) const;
	// Compares two positions by x and y
	bool operator!=(const Position& other) const;

	// Representation in form of "yx" where y will be converted to char from range a-h, x stays as a number
	friend std::ostream& operator<<(std::ostream& out, const Position& pos);
	// Accepts two forms of representation, "xy" and "yx". Char part will always be the y
	friend std::istream& operator>>(std::istream& in, Position& pos);
};