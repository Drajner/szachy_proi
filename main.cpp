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
	Piece& pawn = chess.getPiece(Position(4, 8));
	//chess.removePiece(pawn, Black);
	pawn.move_to(chess, Position(5, 2));
	//Piece& piece = chess.getPiece(Position(7, 4));
	//chess.removePiece(piece, White);
	std::unique_ptr<Player> pl1 = std::unique_ptr<Player>(new Human(Black, "pl1", chess));
	for (auto& e : pl1->allPossibleMoves(chess))
	{
		std::cout << *e.first << "(" << e.first->position().x() << ", "<< e.first->position().y() << ")" << std::endl;
		std::cout << e.second.x() << ", "<< e.second.y() << std::endl;
	}
	//pl1->makeMove(2, chess);
	//(4,8) -> (1,5)
	std::cout << chess;
	Game game = Game();
	game.chessboard_ = chess;
	bool check = game.checkIfCheck(*pl1, White);
	std::cout << check;
	return 0;
}