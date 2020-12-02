#include <stdio.h>
#include <stdbool.h>
const int n = 10;
int A[10][10] = { { 2, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
				{ 0, 3, 0, 0, 0, 0, 0, 0, 0, 0 },
				{ 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 2, 0, 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0, 4, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0, 0, 3, 0, 0, 0 },
				{ 0, 0, 0, 0, 0, 0, 0, 3, 0, 0 },
				{ 0, 0, 0, 0, 0, 0, 0, 0, 2, 0 },
				{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 5 } };

void BiSearch(int answer)
{
	int count = 0;
	bool Flag = false;
	while (count < 10)
	{
		if (answer == A[count][count])
		{
			printf_s("This number located at index:( %d , %d )\n", count, count);
			count += 1;
			Flag = true;
		}
		else if (answer < A[count][count])
			count += 1;
		else if (answer > A[count][count])
			count += 1;

	}
	if (Flag == false) {
		printf("This number doesn't exist\n");
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
	print(A, n, n);
	int answer;
	printf("\nPlease input number\n\n");
	scanf_s("%d", &answer);
	if (answer < 1 || answer > 5)
	{
		printf("Sorry but your number doesnt exist in array\n");
		return 0;
	}
	else
	{
		BiSearch(answer);
		return 1;
	}
}
