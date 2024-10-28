#include <iostream>
#include <vector>
using namespace std;

const int N = 8;
int board[N][N];

// Các bước di chuyển của quân mã theo 8 hướng
int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

bool isValid(int x, int y)
{
    return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1);
}

bool solveKnightTour(int x, int y, int moveCount)
{
    if (moveCount == N * N)
    {
        return true;
    }

    for (int i = 0; i < 8; i++)
    {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (isValid(newX, newY))
        {
            board[newX][newY] = moveCount;
            if (solveKnightTour(newX, newY, moveCount + 1))
            {
                return true;
            }
            board[newX][newY] = -1; // Quay lui
        }
    }
    return false;
}

void printBoard()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << board[i][j] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            board[i][j] = -1;
        }
    }
    board[0][0] = 0;

    if (solveKnightTour(0, 0, 1))
    {
        printBoard();
    }
    else
    {
        cout << "Không có lời giải cho bài toán mã đi tuần." << endl;
    }
    return 0;
}
