#include "Chessboard.h"

#define BLACK_SQ 0xFF
#define WHITE_SQ 0xDB


Chessboard::Chessboard()
{
	auto rook1b = std::make_shared<Rook>(Rook(Position(1, 1), White));
	auto knight1b = std::make_shared<Knight>(Knight(Position(2, 1), White));
	auto bishop1b = std::make_shared<Bishop>(Bishop(Position(3, 1), White));
	auto queen1b = std::make_shared<Queen>(Queen(Position(5, 1), White));
	auto king1b = std::make_shared<King>(King(Position(4, 1), White));
	auto bishop2b = std::make_shared<Bishop>(Bishop(Position(6, 1), White));
	auto knight2b = std::make_shared<Knight>(Knight(Position(7, 1), White));
	auto rook2b = std::make_shared<Rook>(Rook(Position(8, 1), White));

	whitePieces_.push_back(std::move(rook1b));
	whitePieces_.push_back(std::move(knight1b));
	whitePieces_.push_back(std::move(bishop1b));
	whitePieces_.push_back(std::move(queen1b));
	whitePieces_.push_back(std::move(king1b));
	whitePieces_.push_back(std::move(bishop2b));
	whitePieces_.push_back(std::move(knight2b));
	whitePieces_.push_back(std::move(rook2b));

	for (int i = 1; i <= 8; ++i)
	{
		auto pawn = std::make_shared<Pawn>(Pawn(Position(i, 2), White));
		whitePieces_.push_back(std::move(pawn));
	}

	auto rook1w = std::make_shared<Rook>(Rook(Position(1, 8), Black));
	auto knight1w = std::make_shared<Knight>(Knight(Position(2, 8), Black));
	auto bishop1w = std::make_shared<Bishop>(Bishop(Position(3, 8), Black));
	auto queen1w = std::make_shared<Queen>(Queen(Position(5, 8), Black));
	auto king1w = std::make_shared<King>(King(Position(4, 8), Black));
	auto bishop2w = std::make_shared<Bishop>(Bishop(Position(6, 8), Black));
	auto knight2w = std::make_shared<Knight>(Knight(Position(7, 8), Black));
	auto rook2w = std::make_shared<Rook>(Rook(Position(8, 8), Black));

	blackPieces_.push_back(std::move(rook1w));
	blackPieces_.push_back(std::move(knight1w));
	blackPieces_.push_back(std::move(bishop1w));
	blackPieces_.push_back(std::move(queen1w));
	blackPieces_.push_back(std::move(king1w));
	blackPieces_.push_back(std::move(bishop2w));
	blackPieces_.push_back(std::move(knight2w));
	blackPieces_.push_back(std::move(rook2w));

	for (int i = 1; i <= 8; ++i)
	{
		auto pawn = std::make_shared<Pawn>(Pawn(Position(i, 7), Black));
		blackPieces_.push_back(std::move(pawn));
	}

}

Chessboard::Chessboard(std::vector<std::shared_ptr<Piece>> whitePieces, std::vector<std::shared_ptr<Piece>> blackPieces)
{
	whitePieces_ = std::move(whitePieces);
	blackPieces_ = std::move(blackPieces);
}


std::vector<std::shared_ptr<Piece>> const& Chessboard::whitePieces() const
{
	return whitePieces_;
}

std::vector<std::shared_ptr<Piece>> const& Chessboard::blackPieces() const
{
	return blackPieces_;
}

Piece& Chessboard::getPiece(const Position& position) const
{
	for (auto& e : whitePieces_)
	{
		if (e->position() == position)
		{
			return *e;
		}
	}
	for (auto& e : blackPieces_)
	{
		if (e->position() == position)
		{
			return *e;
		}
	}
	throw CannotFindPiece();
}

bool Chessboard::pieceExists(const Position& position) const
{
	for (auto& e : whitePieces_)
	{
		if (e->position() == position)
		{
			return true;
		}
	}
	for (auto& e : blackPieces_)
	{
		if (e->position() == position)
		{
			return true;
		}
	}
	return false;
}

void Chessboard::upgradePiece(Piece& piece_to_upgrade, int choice)
{
	// 1 - queen
	// 2 - knight
	// 3 - bishop
	// 4 - rook
	Position upgradePos = piece_to_upgrade.position();
	Color upgradeColor = piece_to_upgrade.color();
	this->removePiece(piece_to_upgrade, piece_to_upgrade.color());
	if (choice == 1)
	{
		auto queen = std::make_shared<Queen>(Queen(upgradePos, upgradeColor));
		if (upgradeColor == White)
		{
			whitePieces_.push_back(std::move(queen));
		}
		else
		{
			blackPieces_.push_back(std::move(queen));
		}
	}
	if (choice == 2)
	{
		auto knight = std::make_shared<Knight>(Knight(upgradePos, upgradeColor));
		if (upgradeColor == White)
		{
			whitePieces_.push_back(std::move(knight));
		}
		else
		{
			blackPieces_.push_back(std::move(knight));
		}
	}
	if (choice == 3)
	{
		auto bishop = std::make_shared<Bishop>(Bishop(upgradePos, upgradeColor));
		if (upgradeColor == White)
		{
			whitePieces_.push_back(std::move(bishop));
		}
		else
		{
			blackPieces_.push_back(std::move(bishop));
		}
	}
	if (choice == 4)
	{
		auto rook = std::make_shared<Rook>(Rook(upgradePos, upgradeColor));
		if (upgradeColor == White)
		{
			whitePieces_.push_back(std::move(rook));
		}
		else
		{
			blackPieces_.push_back(std::move(rook));
		}
	}
}

bool Chessboard::checkUpgradePossibility(Player& player) const
{
	if (player.getColor() == White)
	{
		for (auto e : whitePieces_)
		{
			if (e->chessboard_representation() == 'p' && e->position().y() == 8)
			{
				return true;
			}
		}
	}
	if (player.getColor() == Black)
	{
		for (auto e : blackPieces_)
		{
			if (e->chessboard_representation() == 'P' && e->position().y() == 1)
			{
				return true;
			}
		}
	}
	return false;
}

Piece& Chessboard::getPieceToUpgrade(Player& player) const
{
	if (player.getColor() == White)
	{
		for (auto& e : whitePieces_)
		{
			if (e->chessboard_representation() == 'p' && e->position().y() == 8)
			{
				return *e;
			}
		}
	}
	if (player.getColor() == Black)
	{
		for (auto& e : blackPieces_)
		{
			if (e->chessboard_representation() == 'P' && e->position().y() == 1)
			{
				return *e;
			}
		}
	}
	throw CannotFindPiece();
}

void Chessboard::removePiece(Piece& piece, Color color)
{
	if (color == White)
	{
		int i = 0;
		for (auto& e : whitePieces_)
		{
			if (*e.get() == piece)
			{
				whitePieces_.erase(whitePieces_.begin()+i);
				return;
			}
			i++;
		}
	}
	if (color == Black)
	{
		int i = 0;
		for (auto& e : blackPieces_)
		{
			if (*e.get() == piece)
			{
				blackPieces_.erase(blackPieces_.begin() + i);
				return;
			}
			i++;
		}
	}
}


void Chessboard::printLine(int lineNumber, int firstColor, int secondColor, std::ostream& os) const
{
	int squareWidth = 6;
	int letters[8] = { 1,2,3,4,5,6,7,8 };
	for (int i = 0; i < squareWidth / 2; i++)
	{
		for (int j = 1; j < 9; j++)
		{
			for (int k = 0; k < squareWidth; k++)
			{
				if (i == 1 && k == 2)
				{
					if (pieceExists(Position(j, lineNumber)))
					{
						os << getPiece(Position(j, lineNumber));
					}
					else
					{
						if (j % 2 == 0)
						{
							os << char(secondColor);
						}
						else
						{
							os << char(firstColor);
						}
					}
				}
				else
				{
					if (j % 2 == 0)
					{
						os << char(secondColor);
					}
					else
					{
						os << char(firstColor);
					}
				}
			}
		}
		if (i == 1)
		{
			os << "    " << letters[lineNumber - 1];
		}
		os << "\n";
	}
}

std::ostream& operator<<(std::ostream& os, const Chessboard& chessboard)
{
	os << "   A     B     C     D     E     F     G     H\n";
	for (int i = 1; i <= 8; i++)
	{
		if (i % 2 == 0)
		{
			chessboard.printLine(i, BLACK_SQ, WHITE_SQ, os);
		}
		else
		{
			chessboard.printLine(i, WHITE_SQ, BLACK_SQ, os);
		}
	}
	return os;
}

bool Chessboard::checkIfCheck(Player& player, Color color) const
{
	if (color == White)
	{
		Position kingPos = Position(0, 0);
		for (auto e : this->whitePieces())
		{
			if (e->chessboard_representation() == 'k')
			{
				kingPos.x(e->position().x());
				kingPos.y(e->position().y());
			}
		}
		for (auto e : player.allPossibleMoves(*this))
		{
			if (e.second == Position(kingPos))
			{
				return true;
			}
		}
	}
	if (color == Black)
	{
		Position kingPos = Position(0, 0);
		for (auto e : this->blackPieces())
		{
			if (e->chessboard_representation() == 'K')
			{
				kingPos.x(e->position().x());
				kingPos.y(e->position().y());
			}
		}
		for (auto e : player.allPossibleMoves(*this))
		{
			if (e.second == Position(kingPos))
			{
				return true;
			}
		}
	}
	return false;
}

bool Chessboard::checkShortCastlePossibility(Player& player, Color color) const
{
	if (color == White)
	{
		if (!this->pieceExists(Position(4, 1)) || !this->pieceExists(Position(1, 1)))
		{
			return false;
		}
		Piece& king = this->getPiece(Position(4, 1));
		Piece& rook = this->getPiece(Position(1, 1));
		return king.chessboard_representation() == 'k' && rook.chessboard_representation() == 'r' && !king.moved() && !rook.moved() 
				&& !this->checkIfCheck(player, color) && !this->pieceExists(Position(2, 1)) && !this->pieceExists(Position(3, 1)) 
				&& !this->checkAttackPossibility(player, Position(2, 1)) && !this->checkAttackPossibility(player, Position(3, 1));
	}
	else
	{
		if (!this->pieceExists(Position(4, 8)) || !this->pieceExists(Position(1, 8)))
		{
			return false;
		}
		Piece& king = this->getPiece(Position(4, 8));
		Piece& rook = this->getPiece(Position(1, 8));
		return king.chessboard_representation() == 'K' && rook.chessboard_representation() == 'R' && !king.moved() && !rook.moved() 
				&& !this->checkIfCheck(player, color) && !this->pieceExists(Position(2, 8)) && !this->pieceExists(Position(3, 8)) 
				&& !this->checkAttackPossibility(player, Position(2, 8)) && !this->checkAttackPossibility(player, Position(3, 8));
	}
}

bool Chessboard::checkLongCastlePossibility(Player& player, Color color) const
{
	if (color == White)
	{
		if (!this->pieceExists(Position(4, 1)) || !this->pieceExists(Position(8, 1)))
		{
			return false;
		}
		Piece& king = this->getPiece(Position(4, 1));
		Piece& rook = this->getPiece(Position(8, 1));
		return king.chessboard_representation() == 'k' && rook.chessboard_representation() == 'r' && !king.moved() && !rook.moved() && !this->checkIfCheck(player, color)
				&& !this->pieceExists(Position(5, 1)) && !this->pieceExists(Position(6, 1)) && !this->pieceExists(Position(7, 1)) 
				&& !this->checkAttackPossibility(player, Position(5, 1)) && !this->checkAttackPossibility(player, Position(6, 1));
	}
	else
	{
		if (!this->pieceExists(Position(4, 8)) || !this->pieceExists(Position(8, 8)))
		{
			return false;
		}
		Piece& king = this->getPiece(Position(4, 8));
		Piece& rook = this->getPiece(Position(8, 8));
		return king.chessboard_representation() == 'K' && rook.chessboard_representation() == 'R' && !king.moved() && !rook.moved() 
				&& !this->checkIfCheck(player, color) && !this->pieceExists(Position(5, 8)) && !this->pieceExists(Position(6, 8)) 
				&& !this->pieceExists(Position(7, 8)) && !this->checkAttackPossibility(player, Position(5, 8)) && !this->checkAttackPossibility(player, Position(6, 8));
		return false;
	}
}

void Chessboard::doShortCastle(Color color)
{
	if (color == White)
	{
		Piece& king = this->getPiece(Position(4, 1));
		king.move_to(*this, Position(2, 1));
		Piece& rook = this->getPiece(Position(1, 1));
		rook.move_to(*this, Position(3, 1));
	}
	else
	{
		Piece& king = this->getPiece(Position(4, 8));
		king.move_to(*this, Position(2, 8));
		Piece& rook = this->getPiece(Position(1, 8));
		rook.move_to(*this, Position(3, 8));
	}
}

void Chessboard::doLongCastle(Color color)
{
	if (color == White)
	{
		Piece& king = this->getPiece(Position(4, 1));
		king.move_to(*this, Position(6, 1));
		Piece& rook = this->getPiece(Position(8, 1));
		rook.move_to(*this, Position(5, 1));
	}
	else
	{
		Piece& king = this->getPiece(Position(4, 8));
		king.move_to(*this, Position(6, 8));
		Piece& rook = this->getPiece(Position(8, 8));
		rook.move_to(*this, Position(5, 8));
	}
}

bool Chessboard::checkAttackPossibility(Player& player, const Position& position) const
{
	for (auto e : player.allPossibleMoves(*this))
	{
		if (e.second == position)
		{
			return true;
		}
	}
	return false;
}

bool Chessboard::checkWin(Color color) const
{
	if (color == Black)
	{
		for (auto e : this->whitePieces())
		{
			if (e->chessboard_representation() == 'k')
			{
				return false;
			}
		}
		return true;
	}
	if (color == White)
	{
		for (auto e : this->blackPieces())
		{
			if (e->chessboard_representation() == 'K')
			{
				return false;
			}
		}
		return true;
	}
}