#include "pch.h"
#include "CppUnitTest.h"
#include "../lab07.3.rec/lab07.3.rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int matrix[4][4] = {
				{1, 5, 6, 10},
				{ 4, 12, 18, 9 },
				{ 3, -2, 7, 0 },
				{ -3, 4, 6, 7 }
			};
			int sum;
			int colCount = 0;
			int rowCount = 0;
			int* pa[4] = { matrix[0], matrix[1], matrix[2], matrix[3] };
			int max = FindSumAbsUnderDiagonalRec(pa, colCount, rowCount, 4, 4, sum);
			Assert::AreEqual(max, -858993460);
		}
	};
}
