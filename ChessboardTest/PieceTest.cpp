#include "CppUnitTest.h"
#include "../piece.h"
#include "../Chessboard.h"
#include <sstream>
#include <algorithm>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ChessTest
{
	TEST_CLASS(PieceTest)
	{
	public:
		TEST_METHOD(TestPawnPossibleMovesBasic)
		{
			auto pawn = std::make_shared<Pawn>(Pawn(Position(1, 1), White));
			Chessboard c = Chessboard(std::vector<std::shared_ptr<Piece>> { pawn }, std::vector<std::shared_ptr<Piece>>());

			auto possible = pawn->possible_moves(c);

			Assert::IsTrue(possible.size() == 2);
			Assert::IsTrue(std::find(possible.begin(), possible.end(), Position(1, 2)) != possible.end());
			Assert::IsTrue(std::find(possible.begin(), possible.end(), Position(1, 3)) != possible.end());

			pawn->move_to(c, Position(1, 2));
			possible = pawn->possible_moves(c);
			Assert::IsTrue(possible.size() == 1);
			Assert::IsTrue(possible[0] == Position(1, 3));
		}

		TEST_METHOD(TestPawnPossibleMovesCapture)
		{
			auto pawn = std::make_shared<Pawn>(Pawn(Position(1, 1), White));
			auto enemyPawn = std::make_shared<Pawn>(Pawn(Position(1, 2), Black));
			Chessboard c = Chessboard(std::vector<std::shared_ptr<Piece>> { pawn }, std::vector<std::shared_ptr<Piece>> { enemyPawn });

			auto possible = pawn->possible_moves(c);

			Assert::IsTrue(possible.size() == 0);

			enemyPawn->move_to(c, Position(2, 2));
			possible = pawn->possible_moves(c);

			Assert::IsTrue(possible.size() == 3);
			Assert::IsTrue(std::find(possible.begin(), possible.end(), Position(1, 2)) != possible.end());
			Assert::IsTrue(std::find(possible.begin(), possible.end(), Position(1, 3)) != possible.end());
			Assert::IsTrue(std::find(possible.begin(), possible.end(), Position(2, 2)) != possible.end());
		}
	};
}
