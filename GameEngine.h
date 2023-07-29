#ifndef __GAMEENGINE_H__
#define __GAMEENGINE_H__

#include <curses.h>
#include <unistd.h>
#include <iostream>
#include <stdio.h>

#include "Item.h"
#include "Snake.h"
using namespace std;


enum CRASH_CHECK{ BOMB = 0, PASS };
class GameEngine{
	private:
		DIRECTION GetUserInput(){
			DIRECTION direction;

			char userInput = getch();
			if( userInput == 'q')     direction = QUIT;
			else if(userInput == 'j') direction = LEFT;
			else if(userInput == 'l') direction = RIGHT;
			else if(userInput == 'i') direction = UP;
			else if(userInput == 'k') direction = DOWN;
			return direction;
		}

		CRASH_CHECK CrashCheck(Snake* snake, Item* item){
			CRASH_CHECK check;
			
			for(int i = 0; i < item->itemVector.size(); i++){
				if(snake->snakeVector[0]->x == item->itemVector[i]->x && snake->snakeVector[0]->y == item->itemVector[i]->y){
					check = BOMB;
					return check;
				}
			}

			check = PASS;
			return check;
		}

		
	public:
	void RunEngine(Snake* snake){
		int count = 0;
		Item* item = new Item;
		
		while(1){
			clear();
			snake->Draw();
			item->Draw();
			refresh();

			if(count % 100 == 0)
				item->MakeItem();

			/*
			if(CheckSnakeBound())
				break;
			*/


			DIRECTION dir = GetUserInput();
			if(dir == QUIT)
				break;

			snake->Move(dir);
			CRASH_CHECK Crash = CrashCheck(snake, item);
			if( Crash == BOMB ){
				snake->AddSnake();
				item->DeleteItem(snake);
			}
		}	
	}



};

#endif
