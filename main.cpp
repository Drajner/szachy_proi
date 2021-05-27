#include "Game.h"
#include "Chessboard.h"
#include "color.h"
#include <iostream>
void printLine(std::ostream& os)
{
	for (int i = 1; i <= 8; i++)
	{
		if (i % 2 != 0)
		{
			os << char(0xFF) << char(0xFF) << char(0xFF);
		}
		else
		{
			os << char(0xDB) << char(0xDB) << char(0xDB);
		}
	}
}
int main()
{
	//printLine(std::cout);
	Chessboard chess = Chessboard();
	Piece& pawn = chess.getPiece(Position(2, 1));
	//chess.removePiece(pawn, Black);
	pawn.move_to(chess, Position(4, 7));
	//Piece& piece = chess.getPiece(Position(7, 4));
	//chess.removePiece(piece, White);
	std::cout << chess;
	return 0;
}