#pragma once

#include <vector>
#include <string>
#include "position.h"
#include "Chessboard.h"

//#define Chessboard int // Placeholder so there aren't any arrors

// Abstract representation of a chess piece
class Piece {
private:
	// Position on the chessboard
	Position position;
	// Color of the piece. 1 is white, 0 is black
	bool color;

	// Full piece name, to be set in the constructor of an inheriting piece
	std::string fullName;
	// Short, 1 char representation (for display purposes in the << operator), to be set in the constructor of an inheriting piece
	char chessboardRepresentation;
public:
	/**
	 * Creates a new chess piece
	 *
	 * @param startPosition Starting position
	 * @param isWhite Is the piece part of the white team? 
	 */
	Piece(Position startPosition, bool isWhite);

	// Checks if this piece is part of the white team
	bool is_white() const;

	// Checks if this piece is part of the black team
	bool is_black() const;

	// Gets the full name of this piece
	std::string get_full_name() const;

	// Gets the short representation
	char get_char_representation() const;

	/**
	 * Gets the possible moves of this piece on a chessboard
	 *
	 * @param chessboard Chessboard the piece will move on.
	 * @return Vector of possible new positions to take
	 */
	virtual std::vector<Position> possible_moves(const Chessboard& chessboard) const = 0;

	/**
	 * Moves this piece to a new position on the chessboard. If move will cause an enemy piece to be captured, it will be removed from the chessboard
	 *
	 * @param chessboard Chessboard the piece will move on. 
	 * @param newPosition New position for this piece
	 */
	void move_to(const Chessboard& chessboard, Position newPosition);

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