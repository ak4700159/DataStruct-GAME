#ifndef __UNIT_H__
#define __UNIT_H__

#include <iostream>
using namespace std;

void print(int x, int y, char* str){
	move(y, x);
	printw(str);
}

class Unit{
	public:
		int x;
		int y;
		char *shape;
		Unit(int x, int y, char *shape_) : x(x), y(y){ 
	 		this->shape = shape_;
		}
		~Unit(){
			cout << "DELETE" << endl;
		}
};

#endif
