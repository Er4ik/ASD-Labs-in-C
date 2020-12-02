#include <stdio.h>
#include <math.h>
int main()
{
    int n;
    printf("Write n:");
    scanf_s("%d", &n);
    double  P = 1;
    double counter1 = 0;
    double counter;
    int counter2 = 0;
    for (int i = 1; i <= n; i++) {
        counter = ((2 * i) * (log(i + 3)));
        counter1 += (2 * i + 1);
        P *= counter1 / counter;
        counter2 += 9;
    }
    printf("%d", counter2);
    printf("\n");
    printf("%lf", P);
    return 0;
}
