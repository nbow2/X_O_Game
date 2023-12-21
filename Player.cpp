
#include<iostream>

#include"BoardGame_Classes.h"
using namespace std;

// as it does not ask for a name
Player::Player(char symbol) {
    this->symbol = symbol;
}

// Like Player 1 and Player 2
Player::Player (int order, char symbol) {
    cout << "Welcome player " << order << endl;
    cout << "Please enter your name: ";
    cin >> name;
    this->symbol = symbol;
}

// Virtual (can change for other player types)
void Player::get_move (int& x, int& y) {
    cout << "\nPlease enter your move x and y (0 to 4) separated by spaces: ";
    cin >> x >> y;
}

// Give player info as a string
string Player::to_string(){
    return "Player: " + name ;
}

// Get symbol used by player
char Player::get_symbol() {
    return symbol;
}
