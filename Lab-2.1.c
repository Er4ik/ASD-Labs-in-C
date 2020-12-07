#include <stdio.h>

#define K 10
int A[K][K] = {
	{ 5, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 5, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 4, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 4, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 3, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 3, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 2, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 2, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };

void BiSearch()
{
	int low = 0;
	int high = K;
	int coords;
	int count = 0;
	while (low < high)
	{
		int mid = (high + low) / 2;
		coords = mid;
		if (A[mid][mid] >= 0 && A[mid][mid] <= 5)
		{
			high = mid;
			count += 1;
		}
		else if (5 < A[mid][mid])
			low = mid + 1;
		else if (0 > A[mid][mid])
			high = mid - 1;
	}
	if (count != 0) {
		printf_s("\nThis number located at index:( %d , %d )\n", high, high);
	}
	else {
		printf_s("This number doesnt exist in matrix");
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
	print(A, K, K);
	BiSearch();
	return 1;
}
