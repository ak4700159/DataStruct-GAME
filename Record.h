#ifndef __RECORD_H__
#define __RECORD_H__
#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;

 
 // 쓰기 : put write out(출력)//
// 읽기 : get read in(입력) //



int My_atoi(char* str) {
	if (str == NULL)
		return -1;

	int str_len = strlen(str);

	int multi_num = 1;
	for(int i = 0; i < str_len - 1; i++)
		multi_num *= 10;

	int result = 0;

	for (int i = 0; i < str_len; i++) {
		if (str[i] < 48 || str[i] > 57) {
			printf("문자 오류 : |%c|", str[i]);
			return -1;
		}
		else {
			switch (str[i]) 
			{
			case '0': result += 0;             multi_num /= 10; break;
			case '1': result += 1 * multi_num; multi_num /= 10; break;
			case '2': result += 2 * multi_num; multi_num /= 10; break;
			case '3': result += 3 * multi_num; multi_num /= 10; break;
			case '4': result += 4 * multi_num; multi_num /= 10; break;
			case '5': result += 5 * multi_num; multi_num /= 10; break;
			case '6': result += 6 * multi_num; multi_num /= 10; break;
			case '7': result += 7 * multi_num; multi_num /= 10; break;
			case '8': result += 8 * multi_num; multi_num /= 10; break;
			case '9': result += 9 * multi_num; multi_num /= 10; break;
			}
		}
	}

	return result;
}


void InitFile(const char* filename) {
	ofstream fout(filename, ios::out);

	fout << "RECORD 1th : 1" << endl;
	fout << "RECORD 2th : 2" << endl;
	fout << "RECORD 3th : 3" << endl;

	fout.close();
}

int GetRecord1(const char* filename) {
	ifstream fin(filename, ios::in);
	while (char ch = fin.get() != ':');
	char ch = fin.get();

	char string[100];
	fin.getline(string, sizeof(string));
	int data = My_atoi(string);
	if (data == -1)
		printf("GetRecord1 오류\n");

	fin.close();
	return data;
}


int GetRecord2(const char* filename) {
	ifstream fin(filename, ios::in);
	while (char ch = fin.get() != ':');
	while (char ch = fin.get() != ':');
	char ch = fin.get();

	char string[100];
	fin.getline(string, sizeof(string));
	int data = My_atoi(string);
	if (data == -1)
		printf("GetRecord2 오류\n");

	fin.close();
	return data;
}


int GetRecord3(const char* filename) {
	ifstream fin(filename, ios::in);
	while (char ch = fin.get() != ':');
	while (char ch = fin.get() != ':');
	while (char ch = fin.get() != ':');
	char ch = fin.get();

	char string[100];
	fin.getline(string, sizeof(string));
	int data = My_atoi(string);
	if (data == -1)
		printf("GetRecord3 오류\n");

	fin.close();
	return data;
}

void PutRecord(const char* filename, int r1, int r2, int r3) {
	ofstream fout(filename, ios::out);

	fout << "RECORD 1th : " << r1 << endl;
	fout << "RECORD 2th : " << r2 << endl;
	fout << "RECORD 3th : " << r3 << endl;

	fout.close();
	printf("SUCCESSS\n");
}


void CompareAndPutData(const char* filename, int data) {
	int record1 = GetRecord1(filename);
	int record2 = GetRecord2(filename);
	int record3 = GetRecord3(filename);


	if (data > record1) {
		int temp = record1;
		record1 = data;
		record3 = record2;
		record2 = temp;
	}
	else if (data > record2) {
		int temp = record2;
		record2 = data;
		record3 = temp;
	}
	else if (data > record3) {
		record3 = data;
	}

	PutRecord(filename, record1, record2, record3);

}

#endif
