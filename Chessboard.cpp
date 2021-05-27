#include "Chessboard.h"

#define BLACK_SQ 0xFF
#define WHITE_SQ 0xDB


Chessboard::Chessboard()
{
	std::shared_ptr<Piece> rook1b = std::shared_ptr<Piece>(new Rook(Position(1, 1), Black));
	std::shared_ptr<Piece> knight1b = std::shared_ptr<Piece>(new Knight(Position(1, 2), Black));
	std::shared_ptr<Piece> bishop1b = std::shared_ptr<Piece>(new Bishop(Position(1, 3), Black));
	std::shared_ptr<Piece> queen1b = std::shared_ptr<Piece>(new Queen(Position(1, 4), Black));
	std::shared_ptr<Piece> king1b = std::shared_ptr<Piece>(new King(Position(1, 5), Black));
	std::shared_ptr<Piece> bishop2b = std::shared_ptr<Piece>(new Bishop(Position(1, 6), Black));
	std::shared_ptr<Piece> knight2b = std::shared_ptr<Piece>(new Knight(Position(1, 7), Black));
	std::shared_ptr<Piece> rook2b = std::shared_ptr<Piece>(new Rook(Position(1, 8), Black));
	std::shared_ptr<Piece> pawn1b = std::shared_ptr<Piece>(new Pawn(Position(2, 1), Black));
	std::shared_ptr<Piece> pawn2b = std::shared_ptr<Piece>(new Pawn(Position(2, 2), Black));
	std::shared_ptr<Piece> pawn3b = std::shared_ptr<Piece>(new Pawn(Position(2, 3), Black));
	std::shared_ptr<Piece> pawn4b = std::shared_ptr<Piece>(new Pawn(Position(2, 4), Black));
	std::shared_ptr<Piece> pawn5b = std::shared_ptr<Piece>(new Pawn(Position(2, 5), Black));
	std::shared_ptr<Piece> pawn6b = std::shared_ptr<Piece>(new Pawn(Position(2, 6), Black));
	std::shared_ptr<Piece> pawn7b = std::shared_ptr<Piece>(new Pawn(Position(2, 7), Black));
	std::shared_ptr<Piece> pawn8b = std::shared_ptr<Piece>(new Pawn(Position(2, 8), Black));

	blackPieces_.push_back(std::move(rook1b));
	blackPieces_.push_back(std::move(knight1b));
	blackPieces_.push_back(std::move(bishop1b));
	blackPieces_.push_back(std::move(queen1b));
	blackPieces_.push_back(std::move(king1b));
	blackPieces_.push_back(std::move(bishop2b));
	blackPieces_.push_back(std::move(knight2b));
	blackPieces_.push_back(std::move(rook2b));
	blackPieces_.push_back(std::move(pawn1b));
	blackPieces_.push_back(std::move(pawn2b));
	blackPieces_.push_back(std::move(pawn3b));
	blackPieces_.push_back(std::move(pawn4b));
	blackPieces_.push_back(std::move(pawn5b));
	blackPieces_.push_back(std::move(pawn6b));
	blackPieces_.push_back(std::move(pawn7b));
	blackPieces_.push_back(std::move(pawn8b));

	std::shared_ptr<Piece> rook1w = std::shared_ptr<Piece>(new Rook(Position(8, 1), White));
	std::shared_ptr<Piece> knight1w = std::shared_ptr<Piece>(new Knight(Position(8, 2), White));
	std::shared_ptr<Piece> bishop1w = std::shared_ptr<Piece>(new Bishop(Position(8, 3), White));
	std::shared_ptr<Piece> queen1w = std::shared_ptr<Piece>(new Queen(Position(8, 4), White));
	std::shared_ptr<Piece> king1w = std::shared_ptr<Piece>(new King(Position(8, 5), White));
	std::shared_ptr<Piece> bishop2w = std::shared_ptr<Piece>(new Bishop(Position(8, 6), White));
	std::shared_ptr<Piece> knight2w = std::shared_ptr<Piece>(new Knight(Position(8, 7), White));
	std::shared_ptr<Piece> rook2w = std::shared_ptr<Piece>(new Rook(Position(8, 8), White));
	std::shared_ptr<Piece> pawn1w = std::shared_ptr<Piece>(new Pawn(Position(7, 1), White));
	std::shared_ptr<Piece> pawn2w = std::shared_ptr<Piece>(new Pawn(Position(7, 2), White));
	std::shared_ptr<Piece> pawn3w = std::shared_ptr<Piece>(new Pawn(Position(7, 3), White));
	std::shared_ptr<Piece> pawn4w = std::shared_ptr<Piece>(new Pawn(Position(7, 4), White));
	std::shared_ptr<Piece> pawn5w = std::shared_ptr<Piece>(new Pawn(Position(7, 5), White));
	std::shared_ptr<Piece> pawn6w = std::shared_ptr<Piece>(new Pawn(Position(7, 6), White));
	std::shared_ptr<Piece> pawn7w = std::shared_ptr<Piece>(new Pawn(Position(7, 7), White));
	std::shared_ptr<Piece> pawn8w = std::shared_ptr<Piece>(new Pawn(Position(7, 8), White));

	whitePieces_.push_back(std::move(rook1w));
	whitePieces_.push_back(std::move(knight1w));
	whitePieces_.push_back(std::move(bishop1w));
	whitePieces_.push_back(std::move(queen1w));
	whitePieces_.push_back(std::move(king1w));
	whitePieces_.push_back(std::move(bishop2w));
	whitePieces_.push_back(std::move(knight2w));
	whitePieces_.push_back(std::move(rook2w));
	whitePieces_.push_back(std::move(pawn1w));
	whitePieces_.push_back(std::move(pawn2w));
	whitePieces_.push_back(std::move(pawn3w));
	whitePieces_.push_back(std::move(pawn4w));
	whitePieces_.push_back(std::move(pawn5w));
	whitePieces_.push_back(std::move(pawn6w));
	whitePieces_.push_back(std::move(pawn7w));
	whitePieces_.push_back(std::move(pawn8w));

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
		for (int j = 1; j < 5; j++)
		{
			for (int k = 0; k < squareWidth; k++)
			{
				if (i == 1 && k == 2)
				{
					if (pieceExists(Position(lineNumber, j * 2-1)))
					{
						os << getPiece(Position(lineNumber, j * 2-1));
					}
					else
					{
						os << char(firstColor);
					}
				}
				else
				{
					os << char(firstColor);
				}
			}
			for (int k = 0; k < squareWidth; k++)
			{
				if (i == 1 && k == 2)
				{
					if (pieceExists(Position(lineNumber, j * 2)))
					{
						os << getPiece(Position(lineNumber, j * 2));
					}
					else
					{
						os << char(secondColor);
					}
				}
				else
				{
					os << char(secondColor);
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