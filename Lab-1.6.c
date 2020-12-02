#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdbool.h>

int main() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Pos;
    Pos.X = 40;
    Pos.Y = 1;
    bool Flag = true;
    SetConsoleCursorPosition(consoleHandle, Pos);
    printf("0");
    Pos.X = 81 - Pos.X;
    SetConsoleCursorPosition(consoleHandle, Pos);
    printf("0");
    Sleep(2);
    Pos.X = 81 - Pos.X;
    Pos.Y++;
    while (Pos.X != 0 && Pos.Y != 0) {
        SetConsoleCursorPosition(consoleHandle, Pos);
        if (Pos.Y == 1) {
            printf("0");
            Pos.X = 81 - Pos.X;
            SetConsoleCursorPosition(consoleHandle, Pos);
            printf("0");
            Sleep(2);
            Pos.X = 81 - Pos.X;
            if (Pos.X == 1) {
                break;
            }
            Pos.X--;
            SetConsoleCursorPosition(consoleHandle, Pos);
            printf("0");
            Pos.X = 81 - Pos.X;
            SetConsoleCursorPosition(consoleHandle, Pos);
            printf("0");
            Sleep(2);
            Pos.X = 81 - Pos.X;
            Pos.Y++;
            Flag = !Flag;
        }
        else if (Pos.Y == 23) {
            printf("0");
            Pos.X = 81 - Pos.X;
            SetConsoleCursorPosition(consoleHandle, Pos);
            printf("0");
            Sleep(2);
            Pos.X = 81 - Pos.X;
            Pos.X--;
            SetConsoleCursorPosition(consoleHandle, Pos);
            printf("0");
            Pos.X = 81 - Pos.X;
            SetConsoleCursorPosition(consoleHandle, Pos);
            printf("0");
            Sleep(2);
            Pos.X = 81 - Pos.X;
            Pos.Y--;
            Flag = !Flag;
        }
        else {
            printf("0");
            Pos.X = 81 - Pos.X;
            SetConsoleCursorPosition(consoleHandle, Pos);
            printf("0");
            Sleep(2);
            Pos.X = 81 - Pos.X;
            if (Flag == true) {
                Pos.Y++;
            }
            else {
                Pos.Y--;
            }
        }
    }
    Pos.X = 0;
    Pos.Y = 24;
    SetConsoleCursorPosition(consoleHandle, Pos);
    return 0;
}
