#ifndef __GAMEENGINE_H__
#define __GAMEENGINE_H__

#include <curses.h>
#include <unistd.h>
#include <iostream>
#include <stdio.h>

#include "Bound.h"
#include "Item.h"
#include "Snake.h"

// 게임 엔진 안의 함수는 게임 시스템과 연관된 함수들이다.
// 게임 엔진 구동 함수는 RunEngine함수이며 이 함수 안에서 반복문을 통해 계속 반복하며 게임을 업데이트한다
// 
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

		bool CheckBound(Snake* snake, Bound* bound){
			for(int i = 1; i < snake->snakeVector.size(); i++){
				if(snake->snakeVector[0]->x == snake->snakeVector[i]->x && snake->snakeVector[0]->y == snake->snakeVector[i]->y)
					return true;
			}
			
			for(int i = 0; i < bound->boundVector.size(); i++){
				if(snake->snakeVector[0]->x == bound->boundVector[i]->x && snake->snakeVector[0]->y == bound->boundVector[i]->y)
					return true;
			}

			return false;
		}

		
	public:
	void RunEngine(Snake* snake){
		int count = 0;
		int scroe = 0;
		Item* item = new Item;
		Bound* bound = new Bound;

		// 아직 쓰레드로 구현X
		// 쓰레드 구현시 사용자가 방향키를 무조건 안눌러도 되고 가장 최근에 갔던 방향으로
		// 뱀이 계속 혼자 움직일 수 있게 된다
		while(1){
			clear(); // 화면은 말 그래도 클리어
			bound->Draw();
			snake->Draw();
			item->Draw();

			refresh(); // 화면 갱신

			if(count % 20 == 0)
				item->MakeItem();

			
			if(CheckBound(snake, bound))
				break;
			


			DIRECTION dir = GetUserInput();
			if(dir == QUIT)
				break;

			snake->Move(dir);
			CRASH_CHECK Crash = CrashCheck(snake, item);
			if( Crash == BOMB ){
				snake->AddSnake();
				item->DeleteItem(snake);
				score = score + 10;
			}

			count++;
		}



		delete item;
		delete bound;
		delete snake;
	}



};

#endif
