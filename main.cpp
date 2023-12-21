// Class definition for XO_App class
// Author:  ahmed dafalla mohmed
// ID : 20210912
// Date:    12/17/2023
// Version: 2

#include <iostream>
#include "BoardGame_Classes.h"
using namespace std;

int main() {
    int choice;
    Player* players[2];
    players[0] = new Player (1, 'x');



    int y ;
    cout << "Welcome to FCAI X-O Game. :)\n";
    cout << "1- Pyramic Tic-Tac-Toe\n";
    cout << "2- Four-in-a-row \n";
    cout << "3- 5 x 5 Tic Tac Toe \n";
    cin>>y;

    switch (y) {

        case 2:
        {
            cout << "Press 1 if you want to play with computer \n";
            cout << "Press 2 if you want to play with Friend \n";
            cin >> choice;
            if (choice != 1)
                players[1] = new Player(2, 'o');
            else
                //Player pointer points to child
                players[1] = new RandomPlayer('o', 3);

            GameManager x_o_gamep(new Board(), players);
            x_o_gamep.runp();
            system("pause");

            // if two players want to play
            if (choice != 2) {
                players[1] = new Player(2, 'o');
                GameManager xo_Game(new Pyramid_Board(), players);
                xo_Game.runp();
                system("cls");
            }
        }
        break;

        case 3: {
            cout << "Press 1 if you want to play with computer \n";
            cout << "Press 2 if you want to play with Friend \n";
            cin >> choice;
            if (choice != 1)
                players[1] = new Player(2, 'o');
            else
                //Player pointer points to child
                players[1] = new RandomPlayer('o', 3);

            GameManager x_o_game5(new X_O_Board(), players);
            x_o_game5.run5x5();
            system("pause");

            // if two players want to play
            if (choice != 2) {
                players[1] = new Player(2, 'o');


                GameManager xo_Game(new X_O_Board(), players);
                xo_Game.run5x5();
                system("cls");
            }
        }
            break;
//        case 2:
//            break;
//        case 3:
//            break;
//        case 4:
//            break;


    }



}
