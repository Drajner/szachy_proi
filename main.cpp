#include "Game.h"
#include "Chessboard.h"
#include "color.h"
#include "Player.h"
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
	//Piece& pawn = chess.getPiece(Position(4, 8));
	//chess.removePiece(pawn, Black);
	//pawn.move_to(chess, Position(5, 2));
	//Piece& piece = chess.getPiece(Position(7, 4));
	//chess.removePiece(piece, White);
	std::unique_ptr<Player> pl1 = std::unique_ptr<Player>(new Human(White, "pl1", chess));
	for (auto& e : pl1->allPossibleMoves(chess))
	{
		std::cout << e.first->full_name() << " [" << *e.first << "] on " << e.first->position() << " can go to " << e.second << std::endl;
		//std::cout << e.second.x() << ", "<< e.second.y() << std::endl;
	}
	//pl1->makeMove(2, chess);
	//(4,8) -> (1,5)
	//Piece& piece1 = chess.getPiece(Position(2, 8));
	//Piece& piece2 = chess.getPiece(Position(3, 8));
	//chess.removePiece(piece1, Black);
	//chess.removePiece(piece2, Black);
	//Piece& piece3 = chess.getPiece(Position(4, 8));
	//chess.removePiece(piece3, Black);
	//Piece& piece4 = chess.getPiece(Position(3, 7));
	//chess.removePiece(piece4, Black);
	//Piece& piece5 = chess.getPiece(Position(4, 1));
	//piece5.move_to(chess, Position(4, 6));
	//std::cout << chess.checkShortCastlePossibility(*pl1, White);
	//chess.doShortCastle(White);
	//std::cout << chess;
	//bool check = chess.checkIfCheck(*pl1, White);
	//std::cout << check << std::endl;
	//std::cout << chess.checkLongCastlePossibility(*pl1, Black);
	//chess.doLongCastle(Black);
	std::cout << chess;
	return 0;
}