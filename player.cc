#include <cstdlib>
#include <iostream>
#include <string>
#include "player.h"
#include "scoreboard.h"

using namespace std;

// initialize the static values declared in player.h
Player *Player::X = 0;
Player *Player::O = 0;


/*********** Player ***********
  Purpose: Constructor of Class Player
  Return: this
************************************/
Player::Player(const char name):name(name) {}


/*********** getInstance ***********
  Purpose: A method of Class Player
           get Player, only can get twice.
  Return: pointer to Player
************************************/
Player *Player::getInstance(){
	if(!X){																				 // is X NULL?
		X = new Player('X');
		atexit(cleanup);
		return X;
	} else if(!O){																 // is O NULL?
		O = new Player('O');
		return O;
	} // if
	return 0;
} // getInstance


/*********** cleanup ***********
  Purpose: A method of Class Player
           free instance
  Return: void
************************************/
void Player::cleanup(){
	delete X;
	delete O;
} // cleanup


/*********** readFile ***********
  Purpose: A method of Class Player
           read input from a file store in ss
  Return: void
************************************/
void Player::readFile(){
	string s = "";
	string tmp = "";
	ifstream f(source.c_str());

	// A loop to read all input from a file and store them as string
	while(f >> s){
		tmp = tmp + s + " ";
	}
	ss.str(tmp.c_str());													 // store string in ss
}


/*********** makeMove ***********
  Purpose: A method of Class Player
           make move by reading instruction from source
  Return: void
************************************/
void Player::makeMove(){
	string move;
	cout << name << "'s move" << endl;

	// read from stdin
	if(source == "stdin"){												 // is source stdin?
		cin >> move;
	} else { // read from source
		ss >> move;
	} // if

	// quit all games end
	if(move == "quit"){														 // quit?
		done = true;
	} else {
		int pos = trans(move);

		// A loop to ignore occupied input
		while(B->isOccupied(pos) != false){
			ss >> move;
			pos = trans(move);
		}
		if(source != "stdin"){											 // is source file?
			cout << "(plays " << move << ")" << endl;
		}
		B->makeMove(name, pos);											 // record move on board
	}
}