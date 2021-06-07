#include "CppUnitTest.h"
#include "../Chessboard.h"
#include "../piece.h"
#include "../Player.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ChessTest
{
	TEST_CLASS(PlayerTest)
	{
	public:
		TEST_METHOD(TestCreateHuman)
		{
			Chessboard chess = Chessboard();
			Human player1 = Human(White, "Adam", chess);
			Assert::IsTrue(player1.getName() == "Adam");
			Assert::IsTrue(player1.getColor() == White);
			Assert::IsTrue(player1.getEnemy() == nullptr);
		}
		TEST_METHOD(TestCreateRandIntBot)
		{
			Chessboard chess = Chessboard();
			RandIntBot player1 = RandIntBot(White, "Adam", chess);
			Assert::IsTrue(player1.getName() == "Adam");
			Assert::IsTrue(player1.getColor() == White);
			Assert::IsTrue(player1.getEnemy() == nullptr);
		}
		TEST_METHOD(TestAddingEnemy)
		{
			Chessboard chess = Chessboard();
			Human player1 = Human(White, "Adam", chess);
			Human player2 = Human(Black, "Ewa", chess);
			Human* the_player2 = &player2;
			player1.setEnemy(the_player2);
			Assert::IsTrue(player1.getEnemy() == the_player2);
		}
		TEST_METHOD(TestPlayerComparisonTrue)
		{
			Chessboard chess = Chessboard();
			Human player1 = Human(White, "Adam", chess);
			Assert::IsTrue(player1 == player1);
		}
		TEST_METHOD(TestPlayerComparisonFalse)
		{
			Chessboard chess = Chessboard();
			Human player1 = Human(White, "Adam", chess);
			Human player2 = Human(Black, "Ewa", chess);
			Assert::IsFalse(player1 == player2);
		}
		TEST_METHOD(TestSetColor)
		{
			Chessboard chess = Chessboard();
			Human player1 = Human(White, "Adam", chess);
			player1.setColor(Black);
			Assert::IsTrue(player1.getColor() == Black);
		}
	};
}