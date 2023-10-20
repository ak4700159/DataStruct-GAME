#include "Record.h"
#include <cstdio>
#include <cstdlib>

int main(int argc, char* argv[]){
	if(argc != 2){
		fprintf(stderr, "error\n");
		exit(1);
	}
	int score = My_atoi(argv[1]);
	CompareAndPutData("RECORD.txt", score);
	return 0;
}
