#include "Chessboard.h"

Chessboard::Chessboard()
{
	
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