#include "Game.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <vector>
#include <unistd.h>
using namespace std;

// 메인함수 : 게임을 실행한다 -> Game 오브젝트 game의 Run함수 실행
int main(int argc, char *argv[]){
	Game* game = new Game;
	game->Run();
	
	// 동적 해제
	delete game;
	return 0;
}



