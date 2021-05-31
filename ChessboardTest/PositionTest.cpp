#include "CppUnitTest.h"
#include "../position.h"
#include "../Exceptions.h"
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ChessTest
{
	TEST_CLASS(PositionTest)
	{
	public:
		TEST_METHOD(TestGetSet)
		{
			Position pos = Position(2, 4);

			Assert::IsTrue(pos.x() == 2);
			Assert::IsTrue(pos.y() == 4);

			pos.x(5);
			pos.y(3);

			Assert::IsTrue(pos.x() == 5);
			Assert::IsTrue(pos.y() == 3);
		}

		TEST_METHOD(TestCompare)
		{
			Position pos = Position(2, 4);
			Position pos2 = Position(2, 4);

			Assert::IsTrue(pos == pos2);

			pos.x(5);
			pos.y(3);

			Assert::IsTrue(pos != pos2);
		}

		TEST_METHOD(TestAddSub)
		{
			Position pos = Position(2, 4);

			Assert::IsTrue(pos + Position(1, -1) == Position(3, 3));
			pos += Position(1, -1);
			Assert::IsTrue(pos == Position(3, 3));
			
			Assert::IsTrue(pos - Position(-2, 1) == Position(5, 2));
			pos -= Position(-2, 1);
			Assert::IsTrue(pos == Position(5, 2));
		}

		TEST_METHOD(TestIStream)
		{
			Position pos1, pos2, pos3, pos4;

			std::stringstream ss{ "a7 4h B2 6C" };

			ss >> pos1 >> pos2 >> pos3 >> pos4;

			Assert::IsTrue(pos1 == Position(1, 7));
			Assert::IsTrue(pos2 == Position(8, 4));
			Assert::IsTrue(pos3 == Position(2, 2));
			Assert::IsTrue(pos4 == Position(3, 6));

			Assert::ExpectException<OutsideBoardLoadException>([]() { 
				Position p;

				std::stringstream ss{ "x9" };

				ss >> p;
			});
		}

		TEST_METHOD(TestOStream)
		{
			Position pos = Position(2, 5);

			std::stringstream ss;

			ss << pos;

			Assert::IsTrue(ss.str() == "b5");

			Assert::ExpectException<OutsideBoardWriteException>([]() {
				Position p = Position(-1, 0);

				std::stringstream ss;

				ss << p;
			});
		}
	};
}
