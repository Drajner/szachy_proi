#include "CppUnitTest.h"
#include "../Chessboard.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ChessTest
{
	TEST_CLASS(ChessboardTest)
	{
	public:
		
		TEST_METHOD(TestGetPiece)
		{
			Chessboard chess = Chessboard();
			Piece& piece = chess.getPiece(Position(1, 1));
			Assert::IsTrue(piece.chessboard_representation() == 'r');
			Assert::IsTrue(piece.color() == White);
		}
		TEST_METHOD(TestPieceExists1)
		{
			Chessboard chess = Chessboard();
			Assert::IsFalse(chess.pieceExists(Position(3, 4)));
		}
		TEST_METHOD(TestPieceExists2)
		{
			Chessboard chess = Chessboard();
			Assert::IsTrue(chess.pieceExists(Position(1, 2)));
		}
		TEST_METHOD(TestRemovePiece)
		{
			Chessboard chess = Chessboard();
			Piece& piece = chess.getPiece(Position(1, 1));
			chess.removePiece(piece, White);
			Assert::IsFalse(chess.pieceExists(Position(1, 1)));
		}
		TEST_METHOD(TestUpgradePiece)
		{
			Chessboard chess = Chessboard();
			Piece& piece = chess.getPiece(Position(1, 2));
			Assert::IsTrue(piece.chessboard_representation() == 'p');
			Assert::IsTrue(piece.color() == White);
			chess.upgradePiece(piece, 1);
			Piece& piece2 = chess.getPiece(Position(1, 2));
			Assert::IsTrue(piece2.chessboard_representation() == 'q');
			Assert::IsTrue(piece2.color() == White);
		}
		TEST_METHOD(TestCheckUpgradePossibility)
		{
			Chessboard chess = Chessboard();
			std::unique_ptr<Player> pl1 = std::unique_ptr<Player>(new Human(White, "pl1", chess));
			Piece& piece = chess.getPiece(Position(1, 2));
			Assert::IsTrue(piece.chessboard_representation() == 'p');
			Assert::IsTrue(piece.color() == White);
			piece.move_to(chess, Position(1, 8));
			Assert::IsTrue(chess.checkUpgradePossibility(*pl1));
		}
		TEST_METHOD(TestGetPieceToUpgrade)
		{
			Chessboard chess = Chessboard();
			std::unique_ptr<Player> pl1 = std::unique_ptr<Player>(new Human(White, "pl1", chess));
			Piece& piece = chess.getPiece(Position(1, 2));
			Assert::IsTrue(piece.chessboard_representation() == 'p');
			Assert::IsTrue(piece.color() == White);
			piece.move_to(chess, Position(1, 8));
			Assert::IsTrue(chess.checkUpgradePossibility(*pl1));
			Piece& piece_to_upgrade = chess.getPieceToUpgrade(*pl1);
			Assert::IsTrue(piece_to_upgrade == piece);
		}
		TEST_METHOD(TestCheckIfCheck)
		{
			Chessboard chess = Chessboard();
			std::unique_ptr<Player> pl1 = std::unique_ptr<Player>(new Human(Black, "pl1", chess));
			Piece& queen = chess.getPiece(Position(4, 8));
			queen.move_to(chess, Position(5, 2));
			Assert::IsTrue(chess.checkIfCheck(*pl1, White));
		}
		TEST_METHOD(TestCheckIfWin)
		{
			Chessboard chess = Chessboard();
			Piece& king = chess.getPiece(Position(5, 1));
			chess.removePiece(king, White);
			Assert::IsTrue(chess.checkWin(Black));
		}
	};
}
