#ifndef __SNAKE_H__
#define __SNAKE_H__

#include <curses.h>
#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include "Unit.h"
using namespace std;
enum DIRECTION{ UP = 0, DOWN, LEFT, RIGHT, QUIT };

void print(int x, int y, char* str){
	move(y, x);
	printw(str);
}



class Snake{
	public:
		int size;
		vector<Unit*> snakeVector;
	public:
		Snake(int size){
			this->size = size;
			for(int i = 0; i < size; i++){
				snakeVector.push_back(new Unit(10, 10-i, (char*)"O"));
			}
		}

		void Draw(){
			for(int i = 0; i < snakeVector.size(); i++){
				print(snakeVector[i]->x, snakeVector[i]->y, snakeVector[i]->shape);
			}
		}


		void Move(DIRECTION dir){
			for(int i = snakeVector.size()-1; i > 0; i--){
				snakeVector[i]->x = snakeVector[i-1]->x;
				snakeVector[i]->y = snakeVector[i-1]->y;
			}

			switch(dir){
				case LEFT: snakeVector[0]->x = snakeVector[0]->x - 1; break;
				case RIGHT: snakeVector[0]->x = snakeVector[0]->x + 1; break;
				case UP: snakeVector[0]->y = snakeVector[0]->y - 1; break;
				case DOWN: snakeVector[0]->y = snakeVector[0]->y + 1; break;
			}
		}

		void AddSnake(){
			snakeVector.push_back(new Unit(snakeVector[3]->x,snakeVector[3]->y,(char*)"O"));
		}

		~Snake(){
			for(int i = 0; i < snakeVector.size(); i++)
				delete snakeVector[i];
		}

};


#endif
