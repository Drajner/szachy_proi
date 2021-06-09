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
		TEST_METHOD(TestNamesReperesentations)
		{
			Pawn whitePawn(Position(1, 1), White), blackPawn(Position(1, 1), Black);
			Knight whiteKnight(Position(1, 1), White), blackKnight(Position(1, 1), Black);
			Rook whiteRook(Position(1, 1), White), blackRook(Position(1, 1), Black);
			Bishop whiteBishop(Position(1, 1), White), blackBishop(Position(1, 1), Black);
			King whiteKing(Position(1, 1), White), blackKing(Position(1, 1), Black);
			Queen whiteQueen(Position(1, 1), White), blackQueen(Position(1, 1), Black);

			std::stringstream ss;

			ss << whitePawn << blackPawn <<
				whiteKnight << blackKnight << 
				whiteRook << blackRook <<
				whiteBishop << blackBishop << 
				whiteKing << blackKing << 
				whiteQueen << blackQueen;

			Assert::IsTrue(ss.str() == "pPnNrRbBkKqQ");

			ss = std::stringstream();

			ss << whitePawn.full_name() << ' ' << blackPawn.full_name() << ' ' <<
				whiteKnight.full_name() << ' ' << blackKnight.full_name() << ' ' <<
				whiteRook.full_name() << ' ' << blackRook.full_name() << ' ' <<
				whiteBishop.full_name() << ' ' << blackBishop.full_name() << ' ' <<
				whiteKing.full_name() << ' ' << blackKing.full_name() << ' ' <<
				whiteQueen.full_name() << ' ' << blackQueen.full_name();

			Assert::IsTrue(ss.str() == "Pawn Pawn Knight Knight Rook Rook Bishop Bishop King King Queen Queen");
		}

		TEST_METHOD(TestPieceMove)
		{
			auto pawn = std::make_shared<Pawn>(Pawn(Position(1, 1), White));
			auto enemyPawn = std::make_shared<Pawn>(Pawn(Position(3, 5), Black));
			
			Chessboard c = Chessboard(std::vector<std::shared_ptr<Piece>> { pawn }, std::vector<std::shared_ptr<Piece>> { enemyPawn });


			Assert::IsTrue(!pawn->moved());

			pawn->move_to(c, Position(2, 2));

			Assert::IsTrue(pawn->moved());
			Assert::IsTrue(c.blackPieces().size() == 1);

			pawn->move_to(c, Position(3, 5));

			Assert::IsTrue(c.blackPieces().empty());
		}

		TEST_METHOD(TestTryAddMove)
		{
			auto pawn = std::make_shared<Pawn>(Pawn(Position(1, 1), White));
			auto friendly = std::make_shared<Pawn>(Pawn(Position(2, 1), White));
			auto enemyPawn = std::make_shared<Pawn>(Pawn(Position(3, 5), Black));

			Chessboard c = Chessboard(std::vector<std::shared_ptr<Piece>> { pawn, friendly }, std::vector<std::shared_ptr<Piece>> { enemyPawn });

			std::vector<Position> possible;

			Assert::IsTrue(!pawn->try_add_movement_option(Position(0, 0), possible, c));
			Assert::IsTrue(!pawn->try_add_movement_option(Position(1, 1), possible, c));
			Assert::IsTrue(!pawn->try_add_movement_option(Position(2, 1), possible, c));
			Assert::IsTrue(pawn->try_add_movement_option(Position(2, 2), possible, c));
			Assert::IsTrue(!pawn->try_add_movement_option(Position(3, 5), possible, c)); // false because placing shouldn't continue, but adds because it should either way
			Assert::IsTrue(possible.size() == 2);
		}

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
