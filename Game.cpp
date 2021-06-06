#include "Game.h"
#include <memory>

Game::Game()
{
	
}

void Game::swap()
{
	if (*currentPlayer_ == *firstPlayer_)
	{
		currentPlayer_ = secondPlayer_.get();
		return;
	}
	else if (*currentPlayer_ == *secondPlayer_)
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
	currentPlayer_ = firstPlayer_.get();
	do
	{
		std::cout << "-----------------------------------------------------------" << std::endl;
		std::cout << chessboard_ << std::endl;
		if (chessboard_.checkIfCheck(*firstPlayer_, Black))
		{
			std::cout << secondPlayer_->getName() << " is under attack! " << std::endl;
		}
		if (chessboard_.checkIfCheck(*secondPlayer_, White))
		{
			std::cout << firstPlayer_->getName() << " is under attack! " << std::endl;
		}
		std::cout << "It's " << currentPlayer_->getName() << " move. ";
		currentPlayer_->makeMove(chessboard_);
		currentPlayer_->doAvailableUpgrades(chessboard_);
		this->swap();
	} 	while (!chessboard_.checkWin(*firstPlayer_) && !chessboard_.checkWin(*secondPlayer_));
	if (chessboard_.checkWin(*firstPlayer_))
	{
		std::cout << firstPlayer_->getName() <<  " wins!" << std::endl;
	}
	if (chessboard_.checkWin(*secondPlayer_))
	{
		std::cout << secondPlayer_->getName() << " wins!" << std::endl;
	}
}

void Game::playPvB()
{
	chessboard_ = Chessboard();
	std::cout << "Please enter your name. You will play with white pieces. \n";
	std::string player_name;
	std::cin >> player_name;
	auto player = std::make_unique<Human>(Human(White, player_name, chessboard_));
	firstPlayer_ = std::move(player);
	auto bot = std::make_unique<RandIntBot>(RandIntBot(Black, "Bot", chessboard_));
	secondPlayer_ = std::move(bot);
	firstPlayer_->setEnemy(secondPlayer_.get());
	secondPlayer_->setEnemy(firstPlayer_.get());
	currentPlayer_ = firstPlayer_.get();
	do
	{
		std::cout << "-----------------------------------------------------------" << std::endl;
		std::cout << chessboard_ << std::endl;
		if (chessboard_.checkIfCheck(*firstPlayer_, Black))
		{
			std::cout << secondPlayer_->getName() << " is under attack! " << std::endl;
		}
		if (chessboard_.checkIfCheck(*secondPlayer_, White))
		{
			std::cout << firstPlayer_->getName() << " is under attack! " << std::endl;
		}
		std::cout << "It's " << currentPlayer_->getName() << " move. ";
		currentPlayer_->makeMove(chessboard_);
		currentPlayer_->doAvailableUpgrades(chessboard_);
		this->swap();
	} while (!chessboard_.checkWin(*firstPlayer_) && !chessboard_.checkWin(*secondPlayer_));
	if (chessboard_.checkWin(*firstPlayer_))
	{
		std::cout << firstPlayer_->getName() << " wins!" << std::endl;
	}
	if (chessboard_.checkWin(*secondPlayer_))
	{
		std::cout << secondPlayer_->getName() << " wins!" << std::endl;
	}
}

void Game::play()
{
	int choice;
	std::cout << "Welcome to chess game. Please choose game mode. " << std::endl;
	std::cout << "1. Player versus player mode. \n";
	std::cout << "2. Player versus bot mode. " << std::endl;
	std::cin >> choice;
	if (choice == 1)
		this->playPvP();
	else if (choice == 2)
		this->playPvB();
	else
		system("pause");
}