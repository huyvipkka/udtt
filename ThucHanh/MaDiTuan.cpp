#include <iostream>
using namespace std;

const int N = 5;
int board[N][N];

// Các bước di chuyển của quân mã theo 8 hướng
int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

bool isValid(int x, int y)
{
    return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1);
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

bool backtrack(int x, int y, int moveCount)
{
    if (moveCount == N * N)
    {
        return true;
    }

    for (int i = 0; i < 8; i++)
    {
        int posX = x + dx[i];
        int posY = y + dy[i];
        if (isValid(posX, posY))
        {
            board[posX][posY] = moveCount;
            if (backtrack(posX, posY, moveCount + 1))
            {
                return true;
            }
            board[posX][posY] = -1;
        }
    }
    return false;
}

int main()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = -1;
    board[0][0] = 0;
    if (backtrack(0, 0, 1))
    {
        printBoard();
    }
}