#ifndef __BOUND_H__
#define __BOUND_H__

#include <iostream>
#include "Unit.h"
#include <vector>

using namespace std;

class Bound{
	public:
		vector<Unit*> boundVector;

		Bound(){

			for(int j = 19; j < 62; j++) // 윗 모서리
				boundVector.push_back(new Unit(j + 35, 19 - 10, (char*)"-"));
			for(int j = 20; j < 36; j++) // 왼쪽 모서리
				boundVector.push_back(new Unit(19 + 35, j - 10, (char*)"I"));
			for(int j = 20; j < 36; j++) // 오른쪽 모서리
				boundVector.push_back(new Unit(61 + 35, j - 10, (char*)"I"));
			for(int j = 19; j < 62; j++) // 아래 모서리
				boundVector.push_back(new Unit(j + 35, 36 - 10, (char*)"-"));
		}
		
		void Draw(){
			for(int i = 0; i < boundVector.size(); i++)
				print(boundVector[i]->x, boundVector[i]->y, boundVector[i]->shape);
		}

		~Bound(){
			for(int i = 0; i < boundVector.size(); i++)
				delete boundVector[i];
		}



};

#endif
