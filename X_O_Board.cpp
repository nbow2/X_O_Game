//
// Created by NBow on 12/17/2023.
//
// Class definition for X_O_Board class
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1
#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "BoardGame_Classes.h"
using namespace std;

// Set the board
X_O_Board::X_O_Board() {
    n_rows = n_cols = 5;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}

// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool X_O_Board::update_board(int x, int y, char mark) {
    // Only update if move is valid
    if (!(x < 0 || x >= n_rows || y < 0 || y >= n_cols) && (board[x][y] == 0)) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    } else {
        return false;
    }
}

// Display the board and the pieces on it
void X_O_Board::display_board() {
    for (int i = 0; i < n_rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < n_cols; j++) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board[i][j] << " |";
        }
        cout << "\n-----------------------------------------------";
    }
    cout << endl;

    int playerX_count  = 0, playerO_count = 0;
    if (is_winner()) {
        cout << "\nWe have a winner: ";
        if (playerX_count  > playerO_count) {
            cout << "Player X";
        } else if (playerO_count > playerX_count ) {
            cout << "Player O";
        } else {

        }
        cout << endl;
    }
}
// Returns true if there is any winner
// either X or O
// Written in a complex way. DO NOT DO LIKE THIS.
// Count consecutive sequences of the same player in a set of cells
void X_O_Board::count_sequence(char cell1, int& playerX_count, int& playerO_count, char cell2, char cell3) {
    if (cell1 == cell2 && cell2 == cell3) {
        if (cell1 == 'X') {
            playerX_count++;
        } else if (cell1 == 'O') {
            playerO_count++;
        }
    }
}

// Check if there is a winner
bool X_O_Board::is_winner() {
    int playerX_count = 0;
    int playerO_count = 0;

    // Check rows
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 3; ++j) {
            count_sequence(board[i][j], playerX_count, playerO_count, board[i][j + 1], board[i][j + 2]);
            count_sequence(board[i][j],playerO_count,playerO_count,board[i][j + 2],board[i][j + 3]);
            count_sequence(board[i][j],playerO_count,playerO_count,board[i][j + 3],board[i][j + 4]);
        }

    }

    // Check columns
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 3; ++j) {
            count_sequence(board[j][i], playerX_count, playerO_count, board[j + 1][i], board[j + 2][i]);
            count_sequence(board[j][i], playerX_count, playerO_count, board[j + 2][i], board[j + 3][i]);
            count_sequence(board[j][i], playerX_count, playerO_count, board[j + 3][i], board[j + 4][i]);
        }

    }

    // Check diagonals
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            count_sequence(board[i][j], playerX_count, playerO_count, board[i + 1][j + 1], board[i + 2][j + 2]);
            count_sequence(board[i + 2][j], playerX_count, playerO_count, board[i + 1][j + 1], board[i][j + 2]);
            //-----------------------------------------------------------------------------------
            count_sequence(board[i][j], playerX_count, playerO_count, board[i + 2][j + 2], board[i + 3][j + 3]);
            count_sequence(board[i + 3][j], playerX_count, playerO_count, board[i + 3][j + 3], board[i][j + 4]);
            //-----------------------------------------------------------------------------------
            count_sequence(board[i][j], playerX_count, playerO_count, board[i + 3][j + 3], board[i + 4][j + 4]);
            count_sequence(board[i + 4][j], playerX_count, playerO_count, board[i + 4][j + 4], board[i][j + 1]);
        }

    }

    // There is a winner if either player has a count greater than 0
    return playerX_count > 0 || playerO_count > 0;
}


// Return true if 25 moves are done and no winner
bool X_O_Board::is_draw() {
    return (n_moves == 25 && !is_winner());
}

bool X_O_Board::game_is_over() {
    return n_moves >= 25;
}

//

Pyramid_Board::Pyramid_Board () {
    n_rows = 3 ;
    n_cols = 5;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}

// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool Pyramid_Board::update_boardPyramid(int x, int y, char mark) {
    // Only update if move is valid
    if (!(x < 0 || x > n_rows  || y < 0 || y > n_cols) && (board[x][y] == 0)) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}

// Display the board and the pieces on it
void Pyramid_Board::display_boardPyramid() {
    for (int i = 0; i < n_rows; i++) {
        cout << "\n ";
        for (int j = 0; j < 2 * n_rows - 1; j++) {
            if (j >= n_rows - i - 1 && j <= n_rows + i - 1) {
                cout << "(" << i << "," << j << ")";
                cout << setw(2) << board[i][j] << " ";
            } else {
                cout << "       "; // Adjust the width based on your needs
            }
        }
        cout << "\n-----------------------------------------------";
    }
    cout << endl;
}

// Returns true if there is any winner
// either X or O
// Written in a complex way. DO NOT DO LIKE THIS.
bool Pyramid_Board::is_winnerPyramid() {
    // Check for horizontal, vertical, and diagonal wins
    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_cols - 2; j++) {
            // Check horizontal win
            if (board[i][j] == board[i][j + 1] && board[i][j + 1] == board[i][j + 2] && board[i][j] != 0) {
                return true;
            }
        }
    }

    for (int i = 0; i < n_rows - 2; i++) {
        for (int j = 0; j < n_cols; j++) {
            // Check vertical win
            if (board[i][j] == board[i + 1][j] && board[i + 1][j] == board[i + 2][j] && board[i][j] != 0) {
                return true;
            }
        }
    }

    // Check diagonal wins
    for (int i = 0; i < n_rows - 2; i++) {
        for (int j = 0; j < n_cols - 2; j++) {
            // Check diagonal (left-top to right-bottom)
            if (board[i][j] == board[i + 1][j + 1] && board[i + 1][j + 1] == board[i + 2][j + 2] && board[i][j] != 0) {
                return true;
            }

            // Check diagonal (left-bottom to right-top)
            if (board[i + 2][j] == board[i + 1][j + 1] && board[i + 1][j + 1] == board[i][j + 2] && board[i + 2][j] != 0) {
                return true;
            }
        }
    }
    return false;
}

// Return true if 9 moves are done and no winner
bool Pyramid_Board::is_drawPyramid() {
    return (n_moves == 15 && !is_winner());
}

bool Pyramid_Board::game_is_overPyramid () {
    return n_moves >= 15;
}

