#include "Game.h"
#include <memory>

//Game::Game(Chessboard chessboard, Player* firstPlayer, Player* secondPlayer)
//{
//	chessboard_ = chessboard;
//	firstPlayer_ = std::unique_ptr<Player>(firstPlayer);
//	secondPlayer_ = std::unique_ptr<Player>(secondPlayer);
//}
Game::Game()
{

}

void Game::rollOrder()
{
	int result = rand() % 2 + 1;
	if (result == 1)
	{
		currentPlayer_ = firstPlayer_.get();
	}
	if (result == 2)
	{
		currentPlayer_ = secondPlayer_.get();
	}
}

void Game::swap()
{
	if (*currentPlayer_ == *firstPlayer_)
	{
		currentPlayer_ = secondPlayer_.get();
	}
	if (*currentPlayer_ == *secondPlayer_)
	{
		currentPlayer_ = firstPlayer_.get();
	}
}

bool Game::checkIfCheck(Player& player, Color color)
{
	if (color == White)
	{
		Position kingPos = Position(0, 0);
		for (auto e : chessboard_.whitePieces())
		{
			if (e->chessboard_representation() == 'k')
			{
				kingPos.x(e->position().x());
				kingPos.y(e->position().y());
			} 
		}
		for (auto e : player.allPossibleMoves(chessboard_))
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
		for (auto e : chessboard_.blackPieces())
		{
			if (e->chessboard_representation() == 'K')
			{
				kingPos.x(e->position().x());
				kingPos.y(e->position().y());
			}
		}
		for (auto e : player.allPossibleMoves(chessboard_))
		{
			if (e.second == Position(kingPos))
			{
				return true;
			}
		}
	}
	return false;
}