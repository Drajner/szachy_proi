#pragma once

#include <vector>
#include <memory>
#include <iostream>

#include "Player.h"
#include "piece_types.h"
#include "color.h"
#include "piece.h"
#include "position.h"
#include "Exceptions.h"
class Chessboard
{
private:
	std::vector<std::shared_ptr<Piece>> whitePieces_;
	std::vector<std::shared_ptr<Piece>> blackPieces_;
	void printLine(int lineNumber, int firstColor, int secondColor, std::ostream& os) const;
public:

	/*
	 * Creates a new chessboard with default Pieces setup
	 */
	Chessboard();

	/*
	 * Creates a new chessboard with custom Pieces setup
	 */
	Chessboard(std::vector<std::shared_ptr<Piece>> firstPlayerPieces, std::vector<std::shared_ptr<Piece>> secondPlayerPieces);
	
	/*
	 * Getter to white pieces vector
	 */
	std::vector<std::shared_ptr<Piece>> const& whitePieces() const;

	/*
	 * Getter to black pieces vector
	 */
	std::vector<std::shared_ptr<Piece>> const& blackPieces() const;

	/*
	 * Removes given piece of given color from chessboard
	 * @param piece Piece to remove
	 * @param color color of given piece
	 */
	void removePiece(Piece& piece, Color color);

	/*
	 * Returns piece of given position
	 * @param position Position of piece
	 */
	Piece& getPiece(const Position& position) const;

	/*
	 * Checks if piece of given position exists
	 * @param position Position of piece
	 */
	bool pieceExists(const Position& position) const;

	/*
	 * Upgrades given piece to other piece
	 * @param piece_to_upgrade Piece to upgrade
	 * @param choice 1 - queen, 2 - knight, 3 - bishop, 4 - rook
	 */
	void upgradePiece(Piece& piece_to_upgrade, int choice);

	/*
	 * Checks if given player has upgrade possibility
	 * @param player Player
	 */
	bool checkUpgradePossibility(Player& player) const;

	/*
	 * Returns piece which player should upgrade
	 * @param player Player
	 */
	Piece& getPieceToUpgrade(Player& player) const;


	/*
	 * Checks if there is check
	 * @param player Player whos enemy's king may be under attack
	 * @param color Color of player's enemy pieces
	 */
	bool checkIfCheck(Player& player, Color color) const;

	/*
	 * Checks if there is short castle possibility
	 * @param player Player whos enemy may do short castle
	 * @param color Color of pieces which may do short castle
	 */
	bool checkShortCastlePossibility(Player& player, Color color) const;

	/*
	 * Checks if there is long castle possibility
	 * @param player Player whos enemy may do long castle
	 * @param color Color of pieces which may do long castle
	 */
	bool checkLongCastlePossibility(Player& player, Color color) const;

	/*
	 * Returns a move where king moves 2 field (doing short castle)
	 * for Player class purposes
	 * @param color Color of pieces which does short castle
	 */
	std::pair<std::shared_ptr<Piece>, Position> getShortCastle(Color color) const;

	/*
	 *Returns a move where king moves 2 field (doing long castle)
	 * for Player class purposes
	 * @param color Color of pieces which may do long castle
	 */
	std::pair<std::shared_ptr<Piece>, Position> getLongCastle(Color color) const;

	/*
	 * Does a short castle
	 * @param color Color of pieces doing castle
	 */
	void doShortCastle(Color color);

	/*
	 * Does a long castle
	 * @param color Color of pieces doing castle
	 */
	void doLongCastle(Color color);

	/*
	 * Checks if there is an attack possibility from given player to given position
	 * @param player Player who we want to check
	 * @param position Position we want to check
	 */
	bool checkAttackPossibility(Player& player, const Position& position) const;

	/*
	 * Checks if there is a win
	 * @param color Color of potential winner
	 */
	bool checkWin(Color color) const;

	friend std::ostream& operator<<(std::ostream& os, const Chessboard& chessboard);

	friend Player;

	friend Human;

	friend RandIntBot;
};
