#include "Game.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <vector>
#include <unistd.h>
using namespace std;


int main(int argc, char *argv[]){
	Game* game = new Game;
	game->Run();
	

	delete game;
	return 0;
}


