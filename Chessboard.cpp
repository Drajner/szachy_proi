#include "Chessboard.h"

Chessboard::Chessboard()
{
	std::unique_ptr<Piece> rook1b = std::unique_ptr<Piece>(new Rook(Position(1, 1), Black));
	std::unique_ptr<Piece> knight1b = std::unique_ptr<Piece>(new Knight(Position(1, 2), Black));
	std::unique_ptr<Piece> bishop1b = std::unique_ptr<Piece>(new Bishop(Position(1, 3), Black));
	std::unique_ptr<Piece> queen1b = std::unique_ptr<Piece>(new Queen(Position(1, 4), Black));
	std::unique_ptr<Piece> king1b = std::unique_ptr<Piece>(new King(Position(1, 5), Black));
	std::unique_ptr<Piece> bishop2b = std::unique_ptr<Piece>(new Bishop(Position(1, 6), Black));
	std::unique_ptr<Piece> knight2b = std::unique_ptr<Piece>(new Knight(Position(1, 7), Black));
	std::unique_ptr<Piece> rook2b = std::unique_ptr<Piece>(new Rook(Position(1, 8), Black));
	std::unique_ptr<Piece> pawn1b = std::unique_ptr<Piece>(new Pawn(Position(2, 1), Black));
	std::unique_ptr<Piece> pawn2b = std::unique_ptr<Piece>(new Pawn(Position(2, 2), Black));
	std::unique_ptr<Piece> pawn3b = std::unique_ptr<Piece>(new Pawn(Position(2, 3), Black));
	std::unique_ptr<Piece> pawn4b = std::unique_ptr<Piece>(new Pawn(Position(2, 4), Black));
	std::unique_ptr<Piece> pawn5b = std::unique_ptr<Piece>(new Pawn(Position(2, 5), Black));
	std::unique_ptr<Piece> pawn6b = std::unique_ptr<Piece>(new Pawn(Position(2, 6), Black));
	std::unique_ptr<Piece> pawn7b = std::unique_ptr<Piece>(new Pawn(Position(2, 7), Black));
	std::unique_ptr<Piece> pawn8b = std::unique_ptr<Piece>(new Pawn(Position(2, 8), Black));

	blackPieces_.push_back(rook1b);
	blackPieces_.push_back(knight1b);
	blackPieces_.push_back(bishop1b);
	blackPieces_.push_back(queen1b);
	blackPieces_.push_back(king1b);
	blackPieces_.push_back(bishop2b);
	blackPieces_.push_back(knight2b);
	blackPieces_.push_back(rook2b);
	blackPieces_.push_back(pawn1b);
	blackPieces_.push_back(pawn2b);
	blackPieces_.push_back(pawn3b);
	blackPieces_.push_back(pawn4b);
	blackPieces_.push_back(pawn5b);
	blackPieces_.push_back(pawn6b);
	blackPieces_.push_back(pawn7b);
	blackPieces_.push_back(pawn8b);

	std::unique_ptr<Piece> rook1w = std::unique_ptr<Piece>(new Rook(Position(8, 1), White));
	std::unique_ptr<Piece> knight1w = std::unique_ptr<Piece>(new Knight(Position(8, 2), White));
	std::unique_ptr<Piece> bishop1w = std::unique_ptr<Piece>(new Bishop(Position(8, 3), White));
	std::unique_ptr<Piece> queen1w = std::unique_ptr<Piece>(new Queen(Position(8, 4), White));
	std::unique_ptr<Piece> king1w = std::unique_ptr<Piece>(new King(Position(8, 5), White));
	std::unique_ptr<Piece> bishop2w = std::unique_ptr<Piece>(new Bishop(Position(8, 6), White));
	std::unique_ptr<Piece> knight2w = std::unique_ptr<Piece>(new Knight(Position(8, 7), White));
	std::unique_ptr<Piece> rook2w = std::unique_ptr<Piece>(new Rook(Position(8, 8), White));
	std::unique_ptr<Piece> pawn1w = std::unique_ptr<Piece>(new Pawn(Position(7, 1), White));
	std::unique_ptr<Piece> pawn2w = std::unique_ptr<Piece>(new Pawn(Position(7, 2), White));
	std::unique_ptr<Piece> pawn3w = std::unique_ptr<Piece>(new Pawn(Position(7, 3), White));
	std::unique_ptr<Piece> pawn4w = std::unique_ptr<Piece>(new Pawn(Position(7, 4), White));
	std::unique_ptr<Piece> pawn5w = std::unique_ptr<Piece>(new Pawn(Position(7, 5), White));
	std::unique_ptr<Piece> pawn6w = std::unique_ptr<Piece>(new Pawn(Position(7, 6), White));
	std::unique_ptr<Piece> pawn7w = std::unique_ptr<Piece>(new Pawn(Position(7, 7), White));
	std::unique_ptr<Piece> pawn8w = std::unique_ptr<Piece>(new Pawn(Position(7, 8), White));

	whitePieces_.push_back(rook1w);
	whitePieces_.push_back(knight1w);
	whitePieces_.push_back(bishop1w);
	whitePieces_.push_back(queen1w);
	whitePieces_.push_back(king1w);
	whitePieces_.push_back(bishop2w);
	whitePieces_.push_back(knight2w);
	whitePieces_.push_back(rook2w);
	whitePieces_.push_back(pawn1w);
	whitePieces_.push_back(pawn2w);
	whitePieces_.push_back(pawn3w);
	whitePieces_.push_back(pawn4w);
	whitePieces_.push_back(pawn5w);
	whitePieces_.push_back(pawn6w);
	whitePieces_.push_back(pawn7w);
	whitePieces_.push_back(pawn8w);
}

Chessboard::Chessboard(std::vector<std::unique_ptr<Piece>> whitePieces, std::vector<std::unique_ptr<Piece>> blackPieces)
{
	whitePieces_ = whitePieces;
	blackPieces_ = blackPieces;
}

std::vector<std::unique_ptr<Piece>> Chessboard::whitePieces() const
{
	return whitePieces_;
}

std::vector<std::unique_ptr<Piece>> Chessboard::blackPieces() const
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

void Chessboard::removePiece(Piece& piece, Color& color)
{
	if (color == White)
	{
		auto it = std::find(whitePieces_.begin(), whitePieces_.end(), piece);
		whitePieces_.erase(it);
		return;
	}
	if (color == Black)
	{
		auto it = std::find(blackPieces_.begin(), blackPieces_.end(), piece);
		blackPieces_.erase(it);
		return;
	}
}