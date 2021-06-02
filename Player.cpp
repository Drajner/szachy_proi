#include <string>
#include <vector>
#include <memory>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "position.h"
#include "piece.h"
#include "Chessboard.h"
#include "Player.h"

Player::Player(Color color, std::string playerName, const Chessboard& chessboard, Player* enemy)
{
	color_ = color;
	name_ = playerName;
	enemy_ = enemy;
	if (color_ == Black)
	{
		pieces_ = chessboard.blackPieces();
	}
	else
	{
		pieces_ = chessboard.whitePieces();
	}
}

std::vector<std::pair<std::shared_ptr<Piece>, Position>> Player::allPossibleMoves(const Chessboard& chessboard)
{
	std::vector<std::pair<std::shared_ptr<Piece>, Position>> moves;
	for (auto& piece : pieces_)
	{
		for (auto& position : piece->possible_moves(chessboard))
		{
			moves.push_back(std::make_pair(piece, position));
		}
	}
	return moves;
}

void Player::setColor(Color color)
{
	color_ = color;
}

std::string Player::getName()
{
	return name_;
}

Color Player::getColor()
{
	return color_;
}

Player* Player::getEnemy()
{
	return enemy_;
}

bool Player::operator==(Player& player)
{
	if (this->getColor() == player.getColor() && this->getName() == player.getName()) return true;
	else return false;
}

void Human::makeMove(Chessboard& chessboard)
{
	std::vector<std::pair<std::shared_ptr<Piece>, Position>> moveset;
	std::string input;
	int chosenMove = -1, iterator = 1, shortCastleNum = -1, longCastleNum = -2;
	moveset = this->allPossibleMoves(chessboard);
	int numberOfMoves = moveset.size();
	std::cout << this->getName() << " please choose your next move." << std::endl;
	for (auto move : moveset)
	{
		std::cout << iterator << ". " << move.first->position() << " " <<  move.first->full_name() << " to " << move.second << std::endl;
		iterator++;
	}
	if (chessboard.checkShortCastlePossibility(*this->getEnemy(), this->getColor()))
	{
		std::cout << iterator << ". Short Castle" << std::endl;
		shortCastleNum = iterator;
		iterator++;
		numberOfMoves++;
	}
	if (chessboard.checkLongCastlePossibility(*this->getEnemy(), this->getColor()))
	{
		std::cout << iterator << ". Long Castle" << std::endl;
		longCastleNum = iterator;
		iterator++;
		numberOfMoves++;
	}
	std::cout << "Please enter the number of desired move." << std::endl;
	while (chosenMove < 1 || chosenMove > numberOfMoves)
	{
		std::cin >> input;
		chosenMove = stoi(input);
		if (chosenMove < 1 || chosenMove > numberOfMoves)
		{
			std::cout << "Wrong input!" << std::endl;
		}
	}
	if (chosenMove == shortCastleNum)
	{
		chessboard.doShortCastle(this->getColor());
		return;
	}
	if (chosenMove == longCastleNum)
	{
		chessboard.doLongCastle(this->getColor());
		return;
	}
	iterator = 1;
	for (auto move : moveset)
	{
		if (iterator == chosenMove)
		{
			move.first->move_to(chessboard, move.second);
			break;
		}
		iterator++;
	}

}

void RandIntBot::makeMove(Chessboard& chessboard)
{
	srand(time(0));
	std::vector<std::pair<std::shared_ptr<Piece>, Position>> moveset;
	int chosenMove = -1, iterator = 1, shortCastleNum = -1, longCastleNum = -2;
	moveset = this->allPossibleMoves(chessboard);
	int numberOfMoves = moveset.size();
	std::cout << this->getName() << " will now move." << std::endl;
	for (auto move : moveset)
	{
		iterator++;
	}
	if (chessboard.checkShortCastlePossibility(*this->getEnemy(), this->getColor()))
	{
		shortCastleNum = iterator;
		iterator++;
		numberOfMoves++;
	}
	if (chessboard.checkLongCastlePossibility(*this->getEnemy(), this->getColor()))
	{
		longCastleNum = iterator;
		iterator++;
		numberOfMoves++;
	}
	while (chosenMove < 1 || chosenMove > numberOfMoves)
	{
		chosenMove = (rand() % numberOfMoves) + 1;
	}
	if (chosenMove == shortCastleNum)
	{
		chessboard.doShortCastle(this->getColor());
		std::cout << this->getName() << " did Short Castle." << std::endl;
		return;
	}
	if (chosenMove == longCastleNum)
	{
		chessboard.doLongCastle(this->getColor());
		std::cout << this->getName() << " did Long Castle." << std::endl;
		return;
	}
	iterator = 1;
	for (auto move : moveset)
	{
		if (iterator == chosenMove)
		{
			std::cout << this->getName() << " moved " << move.first->position() << " " << move.first->full_name() << " to " << move.second << std::endl;
			move.first->move_to(chessboard, move.second);
			break;
		}
		iterator++;
	}
}

