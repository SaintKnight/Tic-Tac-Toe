#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "scoreboard.h"

class Player {
	// only two Players
	static Player *X;
	static Player *O;
	// connect to one scoreboard
	Scoreboard *B;
	
public:
	// get Player
	static Player *getInstance();
	// free Players
	static void cleanup();
	// Player name
	const char name;
	// Player source(stdin or file name)
	std::string source;
	// record file input
	std::istringstream ss;
	// constructor
	Player(const char name);

	// read input from file
	void readFile();
	// make next move
	void makeMove();
};

#endif
