#include <stdio.h>
#include <math.h>
int main()
{
    int n;
    int counter1 = 0;
    int counter = 0;
    double P = 1;
    printf("Write n:");
    scanf_s("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            counter += (2 * j + 1);
        }
        P *= counter / ((2 * i) * (log(i + 3)));
        counter = 0;
        counter1 += 3 * i + 6;
    }
    printf("%d", counter1);
    printf("\n");
    printf("%lf", P);
    return 0;
}
