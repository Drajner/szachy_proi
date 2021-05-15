#include "Chessboard.h"

Chessboard::Chessboard()
{
	//inheriting classes needed
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

Piece& Chessboard::getPiece(const Position& position)
{

}