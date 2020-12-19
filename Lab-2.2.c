#include <stdio.h>
#define K 10

int matrix[K][K] =
{
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 9 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 9, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 8, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 7, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 6, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 5, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 4, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 3, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 2, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

void MatrixSort()
{
	int col = 0, row = K - 1, col_now, row_now, col1 = 0, row1 = K - 1;
	int N = 10;
	for (int j = 0; j < 10; j++)
	{
		int counter = matrix[col1][row1];
		for (int i = 0; i < N; i++)
		{
			if (matrix[col][row] <= counter)
			{
				counter = matrix[col][row];
				col_now = col;
				row_now = row;
			}
			col += 1;
			row -= 1;
		}
		matrix[col_now][row_now] = matrix[col1][row1];
		matrix[col1][row1] = counter;
		N -= 1;
		row1 -= 1;
		col1 += 1;
		row = row1;
		col = col1;
	}
}

void print(int A[][10], int N, int M)
{
	for (int R = 0; R < N; R++) {
		for (int C = 0; C < M; C++)
			printf_s("%d", A[R][C]);
		printf_s("\n");
	}
}

int main()
{
	print(matrix, K, K);
	MatrixSort();
	printf("\n");
	print(matrix, K, K);
	return 1;
}