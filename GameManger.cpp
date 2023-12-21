//
// Created by NBow on 12/17/2023.
//


// Class definition for XO_GameManager class
// Author:  ahmed dafalla mohmed
// ID : 20210912
// Date:    12/17/2023
// Version: 2
// Version: 1

#include <iostream>
#include "BoardGame_Classes.h"
using namespace std;

GameManager::GameManager(Pyramid_Board* board, Player* playerPtr[2] ) {
    boardPtr = board;
    players[0] = playerPtr[0];
    players[1] = playerPtr[1];


}

// run for Game 5x5 x_o
void GameManager::run5x5() {
    int x, y;

    // Display the initial state of the board
    boardPtr->display_board();

    while (!boardPtr->game_is_over()) {
        for (int i : {0, 1 }) {
            players[i]->get_move(x, y);
            while (!boardPtr->update_board(x, y, players[i]->get_symbol())) {
                cout << "Invalid move! Try again.\n";
                players[i]->get_move(x, y);
            }

            // Display the board after the player's move
            boardPtr->display_board();

            // Check for a winner after the player's move
            if (boardPtr->is_winner()) {
                cout << players[i]->to_string() << " wins!\n";
                return; // End the game
            }

            // Check for a draw after the player's move
            if (boardPtr->is_draw()) {
                cout << "Draw!\n";
                return; // End the game
            }
        }
    }
}

//run for game Pyramic Tic-Tac-Toe
void GameManager::runp()
{


    int x, y;
    char currentPlayer = 'X';

    boardPtr->display_boardPyramid();

    while (!boardPtr->game_is_overPyramid())
    {
        for (int i: {0, 1})
        {
            players[i]->get_move(x,y);
            while (!boardPtr->update_boardPyramid(x, y, players[i]->get_symbol()))
            {
                players[i]->get_move(x,y);
            }
            boardPtr->display_boardPyramid();
            if (boardPtr->is_winnerPyramid())
            {
                cout << players[i]->to_string() << " wins\n";
                return;
            }
            if (boardPtr->is_drawPyramid())
            {
                cout << "Draw!\n";
                return;
            }
        }

    }

}

void GameManager::run2()
{

}

