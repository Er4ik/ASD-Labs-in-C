#include <stdio.h>

int main() {
    float x;
    for (int i = 0; i < 15; i++) {
        printf("x:");
        scanf_s("%f", &x);
        printf("result: ");
        if (x >= 8 && x < 23) {
            x = -5 * x * x * x + 10;
            printf("%f", x);
        }
        else if ((x < -19) || (x > -3 && x <= 0)) {
            x = 2 * x * x * x + 8 * x * x;
            printf("%f", x);
        }
        else printf("%s", "function does not exist");

        printf("\n");
    }
    return 0;
}

