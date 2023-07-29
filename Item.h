#ifndef __ITEM_H__
#define __ITEM_H__

#include <iostream>
#include "Unit.h"
#include "Snake.h"
#include <vector>
#include <iterator>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


class Item{
	public:
		vector<Unit*> itemVector;
	public:
		Item() { }
		void Draw(){
			for(int i = 0; i < itemVector.size(); i++){
				print(itemVector[i]->x, itemVector[i]->y, itemVector[i]->shape);
			}
		}

		void MakeItem(){
			srand((unsigned int)time(NULL));
			itemVector.push_back(new Unit(rand() % 20, rand() % 20, (char*)"A"));
		}


		void DeleteItem(Snake* snake){
			vector<Unit*>::iterator it = itemVector.begin();
			for(int i = 0; i < itemVector.size(); i++){
				if(snake->snakeVector[0]->x == itemVector[i]->x && snake->snakeVector[0]->y == itemVector[i]->y){
					itemVector.erase(it);
					return;
				}
				it++;	
			}
		}


};

#endif
