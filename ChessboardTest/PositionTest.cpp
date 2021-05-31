#include "CppUnitTest.h"
#include "../position.h"

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
	};
}
