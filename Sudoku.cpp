#include <iostream>
using namespace std;

#define SIZE 9

void printBoard(int board[SIZE][SIZE]) {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}

bool isSafe(int board[SIZE][SIZE], int row, int col, int num) {
    for(int x = 0; x < SIZE; x++)
        if(board[row][x] == num)
            return false;

    for(int x = 0; x < SIZE; x++)
        if(board[x][col] == num)
            return false;

    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(board[i + startRow][j + startCol] == num)
                return false;

    return true;
}

bool solveSudoku(int board[SIZE][SIZE]) {
    int row = -1, col = -1;
    bool isEmpty = false;

    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            if(board[i][j] == 0) {
                row = i;
                col = j;
                isEmpty = true;
                break;
            }
        }
        if(isEmpty) break;
    }

    if(!isEmpty)
        return true;

    for(int num = 1; num <= 9; num++) {
        if(isSafe(board, row, col, num)) {
            board[row][col] = num;

            if(solveSudoku(board))
                return true;

            board[row][col] = 0;
        }
    }

    return false;
}

int main() {
    int board[SIZE][SIZE];

    for(int i = 0; i < SIZE; i++)
        for(int j = 0; j < SIZE; j++)
            cin >> board[i][j];

    if(solveSudoku(board))
        printBoard(board);
    else
        cout << "No solution exists\n";

    return 0;
}