#include<windows.h>
#include<math.h>
#include <stdlib.h>
#include <stdio.h>
#define N 12
#define PI 3.14159265

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

wchar_t  ProgName[] = L"Лабораторна робота 3";
int A[N][N] = {
        {0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1},
        {0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0},
        {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0},
        {0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0},
        {1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0},
        {1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1},
        {0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1},
};

int B[N][N] = {
        {0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1},
        {1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0},
        {1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0},
        {0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1},
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0},
        {1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1},
        {1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1},
        {1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 0, 1},
};


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
{
    HWND hWnd;
    MSG lpMsg;
    WNDCLASS w;

    w.lpszClassName = ProgName;
    w.hInstance = hInstance;
    w.lpfnWndProc = WndProc;
    w.hCursor = LoadCursor(NULL, IDC_ARROW);
    w.hIcon = 0;
    w.lpszMenuName = 0;
    w.hbrBackground = LTGRAY_BRUSH;
    w.style = CS_HREDRAW | CS_VREDRAW;
    w.cbClsExtra = 0;
    w.cbWndExtra = 0;

    if (!RegisterClass(&w))
        return 0;

    hWnd = CreateWindow(ProgName,
        L"LAB 3. Osmanov Ervin",
        WS_OVERLAPPEDWINDOW,
        100,
        100,
        1200,
        600,
        (HWND)NULL,
        (HMENU)NULL,
        (HINSTANCE)hInstance,
        (HINSTANCE)NULL);

    ShowWindow(hWnd, nCmdShow);

    while (GetMessage(&lpMsg, hWnd, 0, 0)) {
        TranslateMessage(&lpMsg);
        DispatchMessage(&lpMsg);
    }
    return(lpMsg.wParam);
}

void arrow(int px, int py, int dx, int dy, HDC hdc) {
    int lx, ly = py, rx = px, ry;
    if (dx == 0) return;
    else lx = px + (dx / abs(dx)) * 15;
    if (dy == 0) {
        ly = py - 15;
        ry = py + 15;
        lx = px + (15 * dx / abs(dx));
        rx = lx;
    }
    else ry = py + (dy / abs(dy)) * 15;
    MoveToEx(hdc, lx, ly, NULL);
    LineTo(hdc, px, py);
    LineTo(hdc, rx, ry);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT messg, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps;

    switch (messg) {
    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);
        int xPos[12];
        int yPos[12];
        int startCoordx = 20;
        int startCoordy = 560;
        char* ellipseName[12] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "a", "b" };

        int R = 250;
        int step = 0;
        int Centre1_X = 300, Centre1_Y = 400;
        for (int vertex = 0; vertex < N; vertex++) {
            xPos[vertex] = Centre1_X + R * cos(step * PI / 180);
            yPos[vertex] = Centre1_Y + R * sin(step * PI / 180);
            step += 360 / N;
        }

        int dtx = 5, radius = 16, divine = 1, dx, dy, xDif, yDif;
        float koef;
        HPEN BluePen = CreatePen(PS_SOLID, 2, RGB(50, 0, 255));
        HPEN BlackPen = CreatePen(PS_SOLID, 1, RGB(20, 20, 5));

        SelectObject(hdc, BlackPen);
        for (int start = 0; start < N; start++) {
            for (int end = 0; end < N; end++) {
                if (A[start][end] == 1) {
                    xDif = xPos[start] - xPos[end];
                    yDif = yPos[start] - yPos[end];
                    koef = sqrt(xDif * xDif + yDif * yDif) / radius;
                    dx = xDif / koef;
                    dy = yDif / koef;
                    if (start == end) {
                        MoveToEx(hdc, xPos[end], yPos[end], NULL);
                        LineTo(hdc, xPos[end] + 40, yPos[end] + 10);
                        LineTo(hdc, xPos[end] + 40, yPos[end] + 40);
                        LineTo(hdc, xPos[end] + 10, yPos[end] + 40);
                        LineTo(hdc, xPos[end], yPos[end]);
                        arrow(xPos[end] + 2, yPos[end] + 13, 2, 13, hdc);


                    }
                    else if (A[start][end] == 1 && A[end][start] == 1) {
                        MoveToEx(hdc, xPos[start], yPos[start], NULL);
                        LineTo(hdc, xPos[end] + xDif / 2 + (20 * divine), yPos[end] + yDif / 2 + (20 * divine));
                        LineTo(hdc, xPos[end], yPos[end]);
                        arrow(xPos[end] + dx, yPos[end] + dy, dx, dy, hdc);
                        divine = -divine;
                    }
                    else {
                        MoveToEx(hdc, xPos[start], yPos[start], NULL);
                        if (yDif == 0 && abs(xDif) > 300 && end <= 3) {
                            LineTo(hdc, xPos[end] + xDif / 2, yPos[end] - 35);
                            dx = xDif / 2 / koef;
                            dy = (yDif - 35) / koef;
                        }
                        else if (abs(xDif) == 300 && abs(yDif) == 300 && (end == 0 || end == 3)) {
                            LineTo(hdc, xPos[end] + xDif / 2, yPos[end] + yDif / 1);
                            dx = xDif / 2 / koef;
                            dy = yDif / koef;
                        }
                        LineTo(hdc, xPos[end], yPos[end]);
                        arrow(xPos[end] + dx, yPos[end] + dy, dx, dy, hdc);
                    }
                }
            }
        }


        int xPos1[12];
        int yPos1[12];
        int startCoordx1 = 20;
        int startCoordy1 = 560;
        char* ellipseName1[12] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "a", "b" };

        int R1 = 250;
        int step1 = 0;
        int Centre11_X = 900, Centre11_Y = 400;
        for (int vertex = 0; vertex < N; vertex++) {
            xPos1[vertex] = Centre11_X + R * cos(step1 * PI / 180);
            yPos1[vertex] = Centre11_Y + R * sin(step1 * PI / 180);
            step1 += 360 / N;
        }

        int dtx1 = 5, radius1 = 16, divine1 = 1, dx1, dy1, xDif1, yDif1;
        float koef1;
        HPEN BluePen1 = CreatePen(PS_SOLID, 2, RGB(50, 0, 255));
        HPEN BlackPen1 = CreatePen(PS_SOLID, 1, RGB(20, 20, 5));
        SelectObject(hdc, BlackPen1);
        for (int start = 0; start < N; start++) {
            for (int end = 0; end < N; end++) {
                if (B[start][end] == 1) {
                    xDif1 = xPos1[start] - xPos1[end];
                    yDif1 = yPos1[start] - yPos1[end];
                    koef1 = sqrt(xDif1 * xDif1 + yDif1 * yDif1) / radius1;
                    dx1 = xDif1 / koef1;
                    dy1 = yDif1 / koef1;
                    if (start == end) {
                        MoveToEx(hdc, xPos1[end], yPos1[end], NULL);
                        LineTo(hdc, xPos1[end] + 40, yPos1[end] + 10);
                        LineTo(hdc, xPos1[end] + 40, yPos1[end] + 40);
                        LineTo(hdc, xPos1[end] + 10, yPos1[end] + 40);
                        LineTo(hdc, xPos1[end], yPos1[end]);

                    }
                    else if (B[start][end] == 1 && B[end][start] == 1) {
                        MoveToEx(hdc, xPos1[start], yPos1[start], NULL);
                        LineTo(hdc, xPos1[end] + xDif1 / 2 + (20 * divine1), yPos1[end] + yDif1 / 2 + (20 * divine1));
                        LineTo(hdc, xPos1[end], yPos1[end]);
                        divine1 = -divine1;
                    }
                }
            }
        }


        SelectObject(hdc, BluePen);
        for (int i = 0; i < N; i++) {
            Ellipse(hdc, xPos[i] - radius, yPos[i] - radius, xPos[i] + radius, yPos[i] + radius);
            TextOut(hdc, xPos[i] - dtx, yPos[i] - 8, ellipseName[i], 1);
        }

        SelectObject(hdc, BluePen1);
        for (int i = 0; i < N; i++) {
            Ellipse(hdc, xPos1[i] - radius1, yPos1[i] - radius1, xPos1[i] + radius1, yPos1[i] + radius1);
            TextOut(hdc, xPos1[i] - dtx1, yPos1[i] - 8, ellipseName1[i], 1);
        }

        EndPaint(hWnd, &ps);
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return(DefWindowProc(hWnd, messg, wParam, lParam));
    }
    return 0;
}
/*
//MATRIX GENERATION
int** randmatrix(float k) {
    srand(0520);
    int matrix[N][N];
    float num;
    int element;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            num = (rand() / (float)RAND_MAX * 2) * k;
            if (num < 1) element = 0;
            else element = 1;
            matrix[i][j] = element;
            printf("%d ", element);
        }
        printf("\n");
    }
    return matrix;
}
int main() {
    int** A = randmatrix(1.0 - 0 * 0.02 - 4 * 0.005 - 0.25);
    return 0;
}
*/
