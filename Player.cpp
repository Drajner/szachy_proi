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

Player::Player(Color color, std::string playerName, const Chessboard& chessboard): color_(color), 
	name_(playerName),
	enemy_(nullptr) {}
/*{
	color_ = color;
	name_ = playerName;
	enemy_ = nullptr;
	if (color_ == Black)
	{
		pieces_ = chessboard.blackPieces();
	}
	else
	{
		pieces_ = chessboard.whitePieces();
	}
}*/

std::vector<std::pair<std::shared_ptr<Piece>, Position>> Player::allPossibleMoves(const Chessboard& chessboard)
{
	std::vector<std::pair<std::shared_ptr<Piece>, Position>> moves;
	if(color_ == Black)
	{
		for (auto& piece : chessboard.blackPieces_)
		{
			for (auto& position : piece->possible_moves(chessboard))
			{
				moves.push_back(std::make_pair(piece, position));
			}
		}
		return moves;
	}
	else
	{
		for (auto& piece : chessboard.whitePieces_)
		{
			for (auto& position : piece->possible_moves(chessboard))
			{
				moves.push_back(std::make_pair(piece, position));
			}
		}
		return moves;
	}
}

void Player::setColor(Color color)
{
	color_ = color;
}

void Player::setEnemy(Player* enemy)
{
	enemy_ = enemy;
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
	std::shared_ptr<Piece> previousPiece;
	moveset = this->allPossibleMoves(chessboard);
	int numberOfMoves = moveset.size();
	std::cout << this->getName() << " please choose your next move." << std::endl;
	previousPiece = nullptr;
	for (auto move : moveset)
	{
		if (move.first != previousPiece)
		{
			std::cout << std::endl;
			std::cout << move.first->position() << " " << move.first->full_name() << " to:   ";
			previousPiece = move.first;
		}
		std::cout << iterator << ". " << move.second << "  ";
		iterator++;
	}
	std::cout << std::endl;
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
		if (!chessboard.validateMove(moveset[chosenMove - 1], *this))
		{
			chosenMove = -1;
			std::cout << "You are under attack, you have to defend." << std::endl;
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

void Human::doAvailableUpgrades(Chessboard& chessboard)
{
	int input;
	if (chessboard.checkUpgradePossibility(*this))
	{
		std::cout << this->getName() << " has to upgrade pawn. " << std::endl;
		std::cout << "Choose your upgrade: 1 - queen, 2 - knight, 3 - bishop, 4 - rook" << std::endl;
		std::cin >> input;
		chessboard.upgradePiece(chessboard.getPieceToUpgrade(*this), input);
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
		if (!chessboard.validateMove(moveset[chosenMove - 1], *this))
		{
			chosenMove = -1;
		}
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

void RandIntBot::doAvailableUpgrades(Chessboard& chessboard)
{
	if (chessboard.checkUpgradePossibility(*this))
	{
		std::cout << this->getName() << " will now upgrade pawn. " << std::endl;
		chessboard.upgradePiece(chessboard.getPieceToUpgrade(*this), 1);
	}
}