#ifndef __GAME_H__
#define __GAME_H__

#include <iostream>
#include <string>
#include "player.h"


class Scoreboard {
  // only one Scoreboard
  static Scoreboard *instance;
  // constructor
  Scoreboard();

public:
  // get Scoreboard
  static Scoreboard *getInstance();
  // free instance
  static void cleanup();
  // scoreboard in every game.
  static char board[9];
  // record the total number of games X wins
  static int xWins;
  // record the total number of games O wins
  static int oWins;
  // record the total move every game
  static int totalMove;
  // record Winner in every game
  static char Winner;
  
  // start a new Game, reset all records to initial value 0
  void startGame();
  // record the move of the player to board
  void makeMove(char player, int pos);
  // print final score and relative information for every game
  void printScore();
  // judge whether the position is occupied 
  static bool isOccupied(int pos);
  // check whether any one wins the game
  static char checkBoard();
};

// whether game is finished
extern bool done;

// transfer from the string of direction to the index of the board
int trans(const std::string &s);

// judge whether a, b, c is equal.
bool equal(char a, char b, char c);

#endif