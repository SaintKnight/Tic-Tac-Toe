#include <iostream>
#include <sstream>
#include <string>
#include "player.h"
#include "scoreboard.h"

using namespace std;

// a switch to know whether all games ends
bool done = false;

int main(){
	// get one scoreboard and two players
	Scoreboard *B = Scoreboard:: getInstance();
	Player *X = Player:: getInstance();
	Player *O = Player:: getInstance();

	// keep track the games who starts first
	char first = 'X';
	char second = 'O';
	string temp;

	// A loop to start games
	while(getline(cin, temp)){
		done = false;
		if(temp.empty()) continue;
		istringstream line(temp.c_str());
		string command;
		string source1;
		line >> command;

		// command game means start a new game
		if(command == "game"){
			line >> X->source >> O->source;						 // record player source from input
			if(cin.eof()){break;}

			// read from file if X source is file
			if(X->source != "stdin"){
				X->readFile();
			}
			// read from file if O source is file
			if(O->source != "stdin"){
				O->readFile();
			}
			// start new Game
			B->startGame();

			// A loop to record things happend in one game
			while (B->totalMove < 9){
				// whose move
				if(((B->totalMove%2 == 0)&&(first == 'X'))||
				   ((B->totalMove%2 == 1)&&(first == 'O'))) {			// should X move?
					X->makeMove();
				} else {
					O->makeMove();
				}
				// record winner(maybe winner is still 0 because of draw or not finished)
				B->Winner = Scoreboard:: checkBoard();
				B->totalMove++;
				if(B->Winner != 0){										 // is there a winner?
					B->printScore();															 // print summary of this game
					break;
				}
			}
			if(B->Winner == 0){B->printScore();}
			if(first == 'X') {first = 'O';second = 'X';}			 // change turn
			else {first = 'X'; second = 'O';}
			if(done == true) {break;}													 // games finish?
		}
		if(command == "quit"){break;}
	}
}

