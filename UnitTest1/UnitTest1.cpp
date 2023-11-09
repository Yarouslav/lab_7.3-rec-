#include "CppUnitTest.h"
#include "pch.h"
#include "../7.3 (rec)/Source.cpp"

TEST_CLASS(ArrayTest)
{
public:

    TEST_METHOD(TestLongestSeriesRow)
    {
		const int rowCount = 3;
		const int colCount = 3;
		const int Low = 2;
		const int High = 10;
		int** a = new int* [rowCount];
		for (int i = 0; i < rowCount; i++)
			a[i] = new int[colCount];

		Create(a, rowCount, colCount, Low, High, 0, 0);

		// Add assertions to check if the matrix has been created within the specified range

		for (int i = 0; i < rowCount; i++)
			delete[] a[i];
		delete[] a;
	}
    
};