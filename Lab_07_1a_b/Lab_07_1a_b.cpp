#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** x, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** x, const int rowCount, const int colCount);
void Sort(int** x, const int rowCount, const int colCount);
void Change(int** x, const int row1, const int row2, const int colCount);
void Sum(int** x, const int rowCount, const int colCount, int& S);
void Count(int** x, const int rowCount, const int colCount, int& k);

int main()
{
	srand((unsigned)time(NULL));

	int Low = -12;
	int High = 23;
	int rowCount = 7;
	int colCount = 6;

	int** x = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		x[i] = new int[colCount];
	
	cout << "Original array" << endl;
	Create(x, rowCount, colCount, Low, High);
	Print(x, rowCount, colCount);

	cout << "Sorted array" << endl;
	Sort(x, rowCount, colCount);
	Print(x, rowCount, colCount);

	int S = 0;
	int k = 0;

	Sum(x, rowCount, colCount, S);
	cout << "S = " << S << endl;
	Count(x, rowCount, colCount, k);
	cout << "k = " << k << endl;
	cout << endl;

	cout << "Changed array" << endl;
	Print(x, rowCount, colCount);

	for (int i = 0; i < rowCount; i++)
		delete[] x[i];
	delete[] x;

	system("pause");
	return 0;
}

void Create(int** x, const int rowCount, const int colCount, const int Low,
	const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			x[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** x, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << x[i][j];
		cout << endl;
	}
	cout << endl;
}

void Sort(int** x, const int rowCount, const int colCount)
{
	for (int i0 = 0; i0 < rowCount - 1; i0++)
		for (int i1 = 0; i1 < rowCount - i0 - 1; i1++)
			if ((x[i1][0] > x[i1 + 1][0])
				||
				(x[i1][0] == x[i1 + 1][0] &&
					x[i1][1] > x[i1 + 1][1])
				||
				(x[i1][0] == x[i1 + 1][0] &&
					x[i1][1] == x[i1 + 1][1] &&
					x[i1][3] < x[i1 + 1][3]))
				Change(x, i1, i1 + 1, colCount);
}

void Change(int** x, const int row1, const int row2, const int colCount)
{
	int tmp;
	for (int j = 0; j < colCount; j++)
	{
		tmp = x[row1][j];
		x[row1][j] = x[row2][j];
		x[row2][j] = tmp;
	}
}

void Sum(int** x, const int rowCount, const int colCount, int& S)
{
	S = 0;
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			if (x[i][j] % 2 != 0 || !(x[i][j] % 7 < 0))
			{
				S += x[i][j];
				x[i][j] = 0;
			}
}

void Count(int** x, const int rowCount, const int colCount, int& k)
{
	k = 0;
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			if (x[i][j] % 2 != 0 || !(x[i][j] % 7 < 0))
			{
				k++;
			}
}

