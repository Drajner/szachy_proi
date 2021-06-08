#include "Game.h"
#include "Chessboard.h"
#include "color.h"
#include "Player.h"
#include <iostream>
int main()
{
	srand(time(NULL));
	Game game = Game();
	game.play();
	return 0;
}