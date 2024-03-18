#include "Header.h"

void printBoard(int board[][16], int n) { //print 16x16 board
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}

bool valid(int board[][16], int row, int col, int n) {
    for (int i = 0; i < col; i++) //check whether there is queen in the left or not
        if (board[row][i])
            return false;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) //check whether there is queen in the left upper diagonal or not
            return false;
    for (int i = row, j = col; j >= 0 && i < n; i++, j--)
        if (board[i][j]) //check whether there is queen in the left lower diagonal or not
            return false;
    return true;
}

bool solve16Queen(int board[][16], int col, int n) {
    if (col >= n) //when N queens are placed successfully
        return true;
    for (int i = 0; i < n; i++) { //for each row, check placing of queen is possible or not
        if (valid(board, i, col, n)) {
            board[i][col] = 1; //if validate, place the queen at place (i, col)
            if (solve16Queen(board, col + 1, n)) //Go for the other columns recursively
                return true;
            board[i][col] = 0; //When no place is vacant remove that queen
        }
    }
    return false; //when no possible order is found
}

bool TryQueen(int board[][16], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = 0; //set all elements to 0
    if (solve16Queen(board, 0, n) == false) { //starting from 0th column
        cout << "Solution does not exist";
        return false;
    }
    printBoard(board, n);
    return true;
}