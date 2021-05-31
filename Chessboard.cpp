#include "Chessboard.h"

#define BLACK_SQ 0xFF
#define WHITE_SQ 0xDB


Chessboard::Chessboard()
{
	std::shared_ptr<Piece> rook1b = std::shared_ptr<Piece>(new Rook(Position(1, 1), White));
	std::shared_ptr<Piece> knight1b = std::shared_ptr<Piece>(new Knight(Position(2, 1), White));
	std::shared_ptr<Piece> bishop1b = std::shared_ptr<Piece>(new Bishop(Position(3, 1), White));
	std::shared_ptr<Piece> queen1b = std::shared_ptr<Piece>(new Queen(Position(4, 1), White));
	std::shared_ptr<Piece> king1b = std::shared_ptr<Piece>(new King(Position(5, 1), White));
	std::shared_ptr<Piece> bishop2b = std::shared_ptr<Piece>(new Bishop(Position(6, 1), White));
	std::shared_ptr<Piece> knight2b = std::shared_ptr<Piece>(new Knight(Position(7, 1), White));
	std::shared_ptr<Piece> rook2b = std::shared_ptr<Piece>(new Rook(Position(8, 1), White));
	std::shared_ptr<Piece> pawn1b = std::shared_ptr<Piece>(new Pawn(Position(1, 2), White));
	std::shared_ptr<Piece> pawn2b = std::shared_ptr<Piece>(new Pawn(Position(2, 2), White));
	std::shared_ptr<Piece> pawn3b = std::shared_ptr<Piece>(new Pawn(Position(3, 2), White));
	std::shared_ptr<Piece> pawn4b = std::shared_ptr<Piece>(new Pawn(Position(4, 2), White));
	std::shared_ptr<Piece> pawn5b = std::shared_ptr<Piece>(new Pawn(Position(5, 2), White));
	std::shared_ptr<Piece> pawn6b = std::shared_ptr<Piece>(new Pawn(Position(6, 2), White));
	std::shared_ptr<Piece> pawn7b = std::shared_ptr<Piece>(new Pawn(Position(7, 2), White));
	std::shared_ptr<Piece> pawn8b = std::shared_ptr<Piece>(new Pawn(Position(8, 2), White));

	whitePieces_.push_back(std::move(rook1b));
	whitePieces_.push_back(std::move(knight1b));
	whitePieces_.push_back(std::move(bishop1b));
	whitePieces_.push_back(std::move(queen1b));
	whitePieces_.push_back(std::move(king1b));
	whitePieces_.push_back(std::move(bishop2b));
	whitePieces_.push_back(std::move(knight2b));
	whitePieces_.push_back(std::move(rook2b));
	whitePieces_.push_back(std::move(pawn1b));
	whitePieces_.push_back(std::move(pawn2b));
	whitePieces_.push_back(std::move(pawn3b));
	whitePieces_.push_back(std::move(pawn4b));
	whitePieces_.push_back(std::move(pawn5b));
	whitePieces_.push_back(std::move(pawn6b));
	whitePieces_.push_back(std::move(pawn7b));
	whitePieces_.push_back(std::move(pawn8b));

	std::shared_ptr<Piece> rook1w = std::shared_ptr<Piece>(new Rook(Position(1, 8), Black));
	std::shared_ptr<Piece> knight1w = std::shared_ptr<Piece>(new Knight(Position(2, 8), Black));
	std::shared_ptr<Piece> bishop1w = std::shared_ptr<Piece>(new Bishop(Position(3, 8), Black));
	std::shared_ptr<Piece> queen1w = std::shared_ptr<Piece>(new Queen(Position(4, 8), Black));
	std::shared_ptr<Piece> king1w = std::shared_ptr<Piece>(new King(Position(5, 8), Black));
	std::shared_ptr<Piece> bishop2w = std::shared_ptr<Piece>(new Bishop(Position(6, 8), Black));
	std::shared_ptr<Piece> knight2w = std::shared_ptr<Piece>(new Knight(Position(7, 8), Black));
	std::shared_ptr<Piece> rook2w = std::shared_ptr<Piece>(new Rook(Position(8, 8), Black));
	std::shared_ptr<Piece> pawn1w = std::shared_ptr<Piece>(new Pawn(Position(1, 7), Black));
	std::shared_ptr<Piece> pawn2w = std::shared_ptr<Piece>(new Pawn(Position(2, 7), Black));
	std::shared_ptr<Piece> pawn3w = std::shared_ptr<Piece>(new Pawn(Position(3, 7), Black));
	std::shared_ptr<Piece> pawn4w = std::shared_ptr<Piece>(new Pawn(Position(4, 7), Black));
	std::shared_ptr<Piece> pawn5w = std::shared_ptr<Piece>(new Pawn(Position(5, 7), Black));
	std::shared_ptr<Piece> pawn6w = std::shared_ptr<Piece>(new Pawn(Position(6, 7), Black));
	std::shared_ptr<Piece> pawn7w = std::shared_ptr<Piece>(new Pawn(Position(7, 7), Black));
	std::shared_ptr<Piece> pawn8w = std::shared_ptr<Piece>(new Pawn(Position(8, 7), Black));

	blackPieces_.push_back(std::move(rook1w));
	blackPieces_.push_back(std::move(knight1w));
	blackPieces_.push_back(std::move(bishop1w));
	blackPieces_.push_back(std::move(queen1w));
	blackPieces_.push_back(std::move(king1w));
	blackPieces_.push_back(std::move(bishop2w));
	blackPieces_.push_back(std::move(knight2w));
	blackPieces_.push_back(std::move(rook2w));
	blackPieces_.push_back(std::move(pawn1w));
	blackPieces_.push_back(std::move(pawn2w));
	blackPieces_.push_back(std::move(pawn3w));
	blackPieces_.push_back(std::move(pawn4w));
	blackPieces_.push_back(std::move(pawn5w));
	blackPieces_.push_back(std::move(pawn6w));
	blackPieces_.push_back(std::move(pawn7w));
	blackPieces_.push_back(std::move(pawn8w));

	round_ = 0;
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
		std::shared_ptr<Piece> queen = std::shared_ptr<Piece>(new Queen(upgradePos, upgradeColor));
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
		std::shared_ptr<Piece> knight = std::shared_ptr<Piece>(new Knight(upgradePos, upgradeColor));
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
		std::shared_ptr<Piece> bishop = std::shared_ptr<Piece>(new Bishop(upgradePos, upgradeColor));
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
		std::shared_ptr<Piece> rook = std::shared_ptr<Piece>(new Rook(upgradePos, upgradeColor));
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

bool Chessboard::checkUpgradePossibility(Player& player)
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

Piece& Chessboard::getPieceToUpgrade(Player& player)
{
	if (player.getColor() == White)
	{
		for (auto e : whitePieces_)
		{
			if (e->chessboard_representation() == 'p' && e->position().y() == 8)
			{
				return *e.get();
			}
		}
	}
	if (player.getColor() == Black)
	{
		for (auto e : blackPieces_)
		{
			if (e->chessboard_representation() == 'P' && e->position().y() == 1)
			{
				return *e.get();
			}
		}
	}
}

int Chessboard::round()
{
	return round_;
}

void Chessboard::incRound()
{
	round_++;
}

void Chessboard::removePiece(Piece& piece, Color color)
{
	if (color == White)
	{
		//auto it = std::find(whitePieces_.begin(), whitePieces_.end(), piece);
		//whitePieces_.erase(it);
		//return;
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
		//auto it = std::find(blackPieces_.begin(), blackPieces_.end(), piece);
		//blackPieces_.erase(it);
		//return;
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

bool Chessboard::checkIfCheck(Player& player, Color color)
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

bool Chessboard::checkShortCastlePossibility(Player& player, Color color)
{
	if (color == White)
	{
		Piece& king = this->getPiece(Position(5, 1));
		Piece& rook = this->getPiece(Position(8, 1));
		if (king.chessboard_representation() == 'k' && rook.chessboard_representation() == 'r')
		{
			if (king.moved() == false && rook.moved() == false)
			{
				if (this->checkIfCheck(player, color) == false)
				{
					if (this->pieceExists(Position(6, 1)) == false && this->pieceExists(Position(7, 1)) == false)
					{
						if(!this->checkAttackPossibility(player, Position(6,1)) && !this->checkAttackPossibility(player, Position(7, 1)))
							return true;
					}
				}
			}
		}
		return false;
	}
	if (color == Black)
	{
		Piece& king = this->getPiece(Position(5, 8));
		Piece& rook = this->getPiece(Position(8, 8));
		if (king.chessboard_representation() == 'K' && rook.chessboard_representation() == 'R')
		{
			if (king.moved() == false && rook.moved() == false)
			{
				if (this->checkIfCheck(player, color) == false)
				{
					if (this->pieceExists(Position(6, 8)) == false && this->pieceExists(Position(7, 8)) == false)
					{
						if (!this->checkAttackPossibility(player, Position(6, 8)) && !this->checkAttackPossibility(player, Position(7, 8)))
							return true;
					}
				}
			}
		}
		return false;
	}
}

bool Chessboard::checkAttackPossibility(Player& player, const Position& position)
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

bool Chessboard::checkWin(Color color)
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