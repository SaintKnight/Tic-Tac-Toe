#include <cstdlib>
#include <iostream>
#include <string>
#include "player.h"
#include "scoreboard.h"

using namespace std;

// initialize the static values declared in scoreboard.h
char Scoreboard::board[9] = {0,0,0,0,0,0,0,0,0};
int Scoreboard::xWins = 0;
int Scoreboard::oWins = 0;
int Scoreboard::totalMove = 0;
char Scoreboard::Winner = 0;
Scoreboard *Scoreboard::instance = 0;


/*********** Scoreboard ***********
  Purpose: Constructor of Class Scoreboard
  Return: this
************************************/
Scoreboard::Scoreboard() {}


/*********** getInstance ***********
  Purpose: A method of Class Scoreboard
           get Scoreboard, only can get once.
  Return: pointer to Scoreboard
************************************/
Scoreboard *Scoreboard::getInstance() {
  if (!instance) {															 // is instance NULL?
    instance = new Scoreboard();
    atexit(cleanup);
  }
  return instance;
} // getInstance


/*********** cleanup ***********
  Purpose: A method of Class Scoreboard
           free instance
  Return: void
************************************/
void Scoreboard::cleanup() {
  delete instance;
} // cleanup


/*********** printScore ***********
  Purpose: A method of Class Scoreboard
           print final score and relative winner 
           information after every game
  Return: void
************************************/
void Scoreboard::printScore(){

	// output winner information
	if(Winner != 0){															 // is winner exist?
		cout << Winner << " wins" << endl;
		if(Winner == 'X'){													 // is winner X?
			xWins++;
		} else {																		 // is winner O?
			oWins++;
		}
	} else {																			 // is Draw?
		cout << "Draw" << endl;
	} // if

	// output score information
	cout << "Score is" << endl;
	cout << "X " << xWins << endl;
	cout << "O " << oWins << endl;
} // printScore


/*********** startGame ***********
  Purpose: A method of Class Scoreboard
           start a new Game, reset all records to initial value 0
  Return: void
************************************/
void Scoreboard::startGame(){

	// A loop to reset all elements in array board.
	for(int i = 0; i < 9; i++){
		board[i] = 0;
	} // for
	totalMove = 0;																 // reset totalMove to 0	
	Winner = 0;																		 // reset Winner to 0
} // startGame


/*********** makeMove ***********
  Purpose: A method of Class Scoreboard
           record the move of the player to board
  Return: void
************************************/
void Scoreboard::makeMove(char player, int pos){
	if(isOccupied(pos) == false){									 // is pos already occupied?
		board[pos] = player;
	} // if
} // makeMove


/*********** isOccupied ***********
  Purpose: A method of Class Scoreboard
  				 judge whether the position is occupied
  Return: if board at index pos is 0(initial value), return false(means not occupied)
				  if board at index pos is not 0(initial value), return true(means occupied)
************************************/
bool Scoreboard::isOccupied(int pos){
	if(board[pos] == 0){													 // is board at index pos 0?
		return false;
	} else {
		return true;
	} // if
} // isOccupied


/*********** checkBoard ***********
  Purpose: A method of Class Scoreboard
					 check whether any one wins the game
  Return: char 'X' if 'X' wins the game
  				char 'O' if 'O' wins the game
  				0 if no one wins(either draw or haven't finish yet)
************************************/
char Scoreboard::checkBoard(){
	int col = 1;
	int row = 3;
	int diag = 4;
	int i, k;

	// A loop to check whether someone wins by finishing one column
	for(i = 1; i <= 7; i=i+3){
		k = col;

		// are elements in one column same?
		if(equal(board[i-k], board[i], board[i+k])&&(board[i]!=0)) {	
			return board[i];
		} // if
	} // for

	// A loop to check whether someone wins by finishing one row
	for(i = 3; i <= 5; i++){
		k = row;
		// are elements in one row same?
		if(equal(board[i-k], board[i], board[i+k])&&(board[i]!=0)){
			return board[i];
		} // if
	} // for

	// A loop to check whether someone wins by finishing one diagonal
	for(k = 2; k <= 4; k=k+2){
		i = diag;
		// are elements in one row same?
		if(equal(board[i-k], board[i], board[i+k])&&(board[i]!=0)){
			return board[i];
		} // if
	} // for
	return 0;
}


/*********** trans ***********
  Purpose: A function of the program
					 transfer from the string of direction to the index of the board
  Return: the index in board according to the string s direction
************************************/
int trans(const string &s){
	if(s == "NW"){
		return 0;
	} else if(s == "N"){
		return 1;
	} else if(s == "NE"){
		return 2;
	} else if(s == "W"){
		return 3;
	} else if(s == "C"){
		return 4;
	} else if(s == "E"){
		return 5;
	} else if(s == "SW"){
		return 6;
	} else if(s == "S"){
		return 7;
	} else {
		return 8;
	} // if
} // trans


/*********** equal ***********
  Purpose: A function of the program
					 judge whether a, b, c is equal.
  Return: true if a,b,c are equal; false otherwise
************************************/
bool equal(char a, char b, char c){
	if((a == b)&&(b == c)){												 // are a,b,c equal?
		return true;
	} else {
		return false;
	} // if
} // equal