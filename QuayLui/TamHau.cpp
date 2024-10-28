#include <iostream>
#include <vector>
using namespace std;

const int N = 8;
int board[N][N];

bool isSafe(int x, int y)
{
    for (int i = 0; i < x; i++)
    {
        if (board[i][y] == 1)
            return false;
    }

    for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
            return false;
    }

    for (int i = x - 1, j = y + 1; i >= 0 && j < N; i--, j++)
    {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

bool solveNQueens(int x)
{
    if (x == N)
    {
        return true;
    }

    for (int y = 0; y < N; y++)
    {
        if (isSafe(x, y))
        {
            board[x][y] = 1; // Đặt quân hậu

            if (solveNQueens(x + 1))
            {
                return true;
            }

            board[x][y] = 0; // Quay lui, loại bỏ quân hậu
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
            cout << (board[i][j] ? "Q " : ". ");
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
            board[i][j] = 0;
        }
    }

    if (solveNQueens(0))
    {
        printBoard();
    }
    else
    {
        cout << "Không có lời giải cho bài toán 8 hậu." << endl;
    }

    return 0;
}
