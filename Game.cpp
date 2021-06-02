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
		return;
	}
	if (*currentPlayer_ == *secondPlayer_)
	{
		currentPlayer_ = firstPlayer_.get();
		return;
	}
}

void Game::playPvP()
{
	chessboard_ = Chessboard();
	std::cout << "Please enter the name for player with white pieces. \n";
	std::string white_player_name;
	std::cin >> white_player_name;
	auto white_player = std::make_unique<Human>(Human(White, white_player_name, chessboard_));
	firstPlayer_ = std::move(white_player);
	std::cout << "Please enter the name for player with black pieces. \n";
	std::string black_player_name;
	std::cin >> black_player_name;
	auto black_player = std::make_unique<Human>(Human(Black, black_player_name, chessboard_));
	secondPlayer_ = std::move(black_player);
	firstPlayer_->setEnemy(secondPlayer_.get());
	secondPlayer_->setEnemy(firstPlayer_.get());
	this->rollOrder();
	bool check = false;
	do
	{
		std::cout << chessboard_ << std::endl;
		if (chessboard_.checkIfCheck(*firstPlayer_, Black))
		{
			std::cout << secondPlayer_->getName() << " is under attack! " << std::endl;
		}
		if (chessboard_.checkIfCheck(*secondPlayer_, White))
		{
			std::cout << firstPlayer_->getName() << " is under attack! " << std::endl;
		}
		std::cout << "It's " << currentPlayer_->getName() << " move.";
		currentPlayer_->makeMove(chessboard_);
		if (chessboard_.checkUpgradePossibility(*currentPlayer_))
		{
			std::cout << currentPlayer_->getName() << " has to upgrade pawn." << std::endl;
			std::cout << "Choose your upgrade: 1 - queen, 2 - knight, 3 - bishop, 4 - rook" << std::endl;
			int choice;
			std::cin >> choice;
			chessboard_.upgradePiece(chessboard_.getPieceToUpgrade(*currentPlayer_), choice);
		}
		this->swap();
	} 	while (!chessboard_.checkWin(White) && !chessboard_.checkWin(Black));

}

//bool Game::checkIfCheck(Player& player, Color color)
//{
//	if (color == White)
//	{
//		Position kingPos = Position(0, 0);
//		for (auto e : chessboard_.whitePieces())
//		{
//			if (e->chessboard_representation() == 'k')
//			{
//				kingPos.x(e->position().x());
//				kingPos.y(e->position().y());
//			} 
//		}
//		for (auto e : player.allPossibleMoves(chessboard_))
//		{
//			if (e.second == Position(kingPos))
//			{
//				return true;
//			}
//		}
//	}
//	if (color == Black)
//	{
//		Position kingPos = Position(0, 0);
//		for (auto e : chessboard_.blackPieces())
//		{
//			if (e->chessboard_representation() == 'K')
//			{
//				kingPos.x(e->position().x());
//				kingPos.y(e->position().y());
//			}
//		}
//		for (auto e : player.allPossibleMoves(chessboard_))
//		{
//			if (e.second == Position(kingPos))
//			{
//				return true;
//			}
//		}
//	}
//	return false;
//}