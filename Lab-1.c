#include <stdio.h>
int main() {
    float x;
    for (int i = 0; i < 15; i++) {
        printf("x or y:");
        scanf_s("%f", &x);
        printf("result: ");
        if (x >= 8) {
            if (x < 23) {
                x = -5 * x * x * x + 10;
                printf("%f", x);
            }
            else {
                printf("%s", "function does not exist");
            }
        }
        else {
            if (x < -19) {
                x = 2 * x * x * x + 8 * x * x;
                printf("%f", x);
            }
            else if (x <= 0) {
                if (x > -3) {
                    x = 2 * x * x * x + 8 * x * x;
                    printf("%f", x);
                }
                else {
                    printf("%s", "function does not exist");
                }
            }
            else {
                printf("%s", "function does not exist");
            }
        }
        printf("\n");
    }
    return 0;
}
