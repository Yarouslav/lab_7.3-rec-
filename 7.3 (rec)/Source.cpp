#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low,
	const int High, int i, int j);

void Input(int** a, const int rowCount, const int colCount, int i, int j);

void Print(int** a, const int rowCount, const int colCount, int i, int j);

int CountColumnsWithZero(int** a, const int rowCount, const int colCount, int j, int i);

void LongestSeriesRow(int** a, const int rowCount, const int colCount, int i, int j,
	int& maxSeriesLength, int& maxSeriesRow, int currentLength);

int main()
{
	srand(static_cast<unsigned>(time(NULL)));
	int Low = -17;
	int High = 15;
	int rowCount, colCount;
	cout << "rowCount = "; cin >> rowCount;
	cout << "colCount = "; cin >> colCount;
	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];

	Create(a, rowCount, colCount, Low, High, 0, 0);
	Print(a, rowCount, colCount, 0, 0);

	int columnsWithZero = CountColumnsWithZero(a, rowCount, colCount, 0, 0);
	cout << "Number of columns with at least one zero element: " << columnsWithZero << endl;

	int maxSeriesLength = 0;
	int maxSeriesRow = -1;

	LongestSeriesRow(a, rowCount, colCount, 0, 1, maxSeriesLength, maxSeriesRow, 1);

	cout << "Row with the longest series of identical elements: " << maxSeriesRow << endl;

	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;

	return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low,
	const int High, int i, int j)
{
	if (i < rowCount)
	{
		if (j < colCount)
		{
			a[i][j] = Low + rand() % (High - Low + 1);
			Create(a, rowCount, colCount, Low, High, i, j + 1);
		}
		else
			Create(a, rowCount, colCount, Low, High, i + 1, 0);
	}
}

void Input(int** a, const int rowCount, const int colCount, int i, int j)
{
	if (i < rowCount)
	{
		if (j < colCount)
		{
			cout << "a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
			Input(a, rowCount, colCount, i, j + 1);
		}
		else
		{
			cout << endl;
			Input(a, rowCount, colCount, i + 1, 0);
		}
	}
}

void Print(int** a, const int rowCount, const int colCount, int i, int j)
{
	if (i < rowCount)
	{
		if (j < colCount)
		{
			cout << setw(4) << a[i][j];
			Print(a, rowCount, colCount, i, j + 1);
		}
		else
		{
			cout << endl;
			Print(a, rowCount, colCount, i + 1, 0);
		}
	}
	else
		cout << endl;
}

int CountColumnsWithZero(int** a, const int rowCount, const int colCount, int j, int i)
{
	if (j < colCount)
	{
		if (i < rowCount)
		{
			if (a[i][j] == 0)
				return 1 + CountColumnsWithZero(a, rowCount, colCount, j, i + 1);
			else
				return CountColumnsWithZero(a, rowCount, colCount, j, i + 1);
		}
		else
			return CountColumnsWithZero(a, rowCount, colCount, j + 1, 0);
	}
	else
		return 0;
}

void LongestSeriesRow(int** a, const int rowCount, const int colCount, int i, int j,
	int& maxSeriesLength, int& maxSeriesRow, int currentLength)
{
	if (i < rowCount)
	{
		if (j < colCount - 1)
		{
			if (a[i][j] == a[i][j + 1])
				LongestSeriesRow(a, rowCount, colCount, i, j + 1, maxSeriesLength, maxSeriesRow, currentLength + 1);
			else
				LongestSeriesRow(a, rowCount, colCount, i, j + 1, maxSeriesLength, maxSeriesRow, 1);
		}
		else
		{
			if (currentLength > maxSeriesLength)
			{
				maxSeriesLength = currentLength;
				maxSeriesRow = i;
			}

			LongestSeriesRow(a, rowCount, colCount, i + 1, 0, maxSeriesLength, maxSeriesRow, 1);
		}
	}
}
