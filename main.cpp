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

// !! UWAGA: model zarządzania pamięcią nie jest do końca przemyślany.
// Shared pointer w porównaniu z unique_ptr ma spore narzuty i nie powinien
// być stosowany jeśli nie jest to konieczne.
// W tym wypadku, czas życia pionków jest dyktowany czasem życia gry, więc wystarczy
// że gra ma unique_ptr na pionek, reszta może się do niego odnosić przez surowe
// wskazanie.
