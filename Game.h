#ifndef __GAME_H__
#define __GAME_H__

#include <curses.h>
#include <unistd.h>
#include <iostream>
#include "GameEngine.h"
#include "Snake.h"
using namespace std;

class Game{
	GameEngine *engine;
	public:
		Game(){
			engine = new GameEngine;	
			initscr(); 
			curs_set(0); 
		}
		void Run(){
			Snake *snake = new Snake(4);
			engine->RunEngine(snake);
		}

		~Game(){ endwin(); delete engine; }
};

#endif
