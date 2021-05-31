#pragma once
#include <iostream>

// Stores a position on the chessboard. Accepts positions outside of chessboard, but will throw exceptions when trying to write them out
struct Position {
private:
	int x_;
	int y_;
public:
	Position();
	Position(int posX, int posY);

	// Sets the horizontal position
	void x(int newX);
	// Sets the vertical position
	void y(int newY);
	// Gets the horizontal position in int form
	int x() const;
	// Gets the vertical position in int form
	int y() const;

	bool on_chessboard() const;

	// Compares two positions by x and y
	bool operator==(const Position& other) const;
	// Compares two positions by x and y
	bool operator!=(const Position& other) const;
	
	Position operator+(const Position& other) const;
	Position& operator+=(const Position& other);
	Position operator-(const Position& other) const;
	Position& operator-=(const Position& other);

	// Representation in form of "yx" where x will be converted to char from range a-h, y stays as a number. If outside of range (1-8), throws exception
	friend std::ostream& operator<<(std::ostream& out, const Position& pos);
	// Accepts two forms of representation, "xy" and "yx". Char part will always be the x
	friend std::istream& operator>>(std::istream& in, Position& pos);
};