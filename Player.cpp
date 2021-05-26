#include <string>
#include <vector>
#include <memory>
#include "position.h"
#include "piece.h"
#include "Chessboard.h"
#include "Player.h"

Player::Player(Color color, std::string playerName)
{

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

bool Player::operator==(Player& player)
{
	if (this->getColor() == player.getColor() && this->getName() == player.getName()) return true;
	else return false;
}

