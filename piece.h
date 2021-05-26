#pragma once

#include <vector>
#include <string>
#include "position.h"
#include "color.h"
#include "Chessboard.h"

class Chessboard;

// Abstract representation of a chess piece
class Piece {
protected:
	// Position on the chessboard
	Position position_;
	// Color of the piece
	Color color_;
public:
	/**
	 * Creates a new chess piece
	 *
	 * @param startPosition Starting position
	 * @param isWhite Is the piece part of the white team? 
	 */
	Piece(Position startPosition, Color color);

	// Checks if this piece is part of the white team
	Color color() const;

	Position position() const;

	// Full piece name, to be set in the constructor of an inheriting piece
	virtual std::string full_name() const = 0;

	// Short, 1 char representation (for display purposes in the << operator), to be set in the constructor of an inheriting piece
	virtual char chessboard_representation() const = 0;

	/**
	 * Gets the possible moves of this piece on a chessboard
	 *
	 * @param chessboard Chessboard the piece will move on.
	 * @return Vector of possible new positions to take
	 */
	virtual std::vector<Position> possible_moves(const Chessboard& chessboard) const = 0;

	/**
	 * Executed when the piece moves
	 *
	 * @param newPosition The new piece position
	 */
	virtual void on_moved(Position newPosition) {}

	/**
	 * Moves this piece to a new position on the chessboard. If move will cause an enemy piece to be captured, it will be removed from the chessboard
	 *
	 * @param chessboard Chessboard the piece will move on. 
	 * @param newPosition New position for this piece
	 */
	void move_to(Chessboard& chessboard, Position newPosition);

	/**
	 * Compares two chess pieces by name, color and position
	 *
	 * @param other Piece to compare to
	 */
	bool operator==(const Piece& other) const;

	/**
	 * Compares two chess pieces by name, color and position
	 *
	 * @param other Piece to compare to
	 */
	bool operator!=(const Piece& other) const;

	// Appends the short char representation to the stream
	friend std::ostream& operator<<(std::ostream& out, const Piece& piece);
};