#pragma once
#include<iostream>
using namespace std;

int len(string text) {
	int length = 0;
	for (int i = 0; text[i] != NULL; i++) {
		length++;
	}
	return length;
}

bool find(string text,string subText) {
	int j = 0;
	for (int i = 0; i < len(text); i++) {
		if (text[i] == subText[j]) {
			j++;
		}
		else {
			j = 0;
		}
		if (j == len(subText)) {
			//cout << "\nFound";
			return true;
		}
	}
	//cout << "Not Found";
	return false;
}

string toString(char arr[]) {
	string line = "";
	for (int i = 0; arr[i] != NULL; i++) {
		line += arr[i];
	}
	return line;
}


//string* split(string line, char sep) {
//	string arr[100];
//	int j = 0;
//	for (int i = 0; i < len(line); i++) {
//		arr[j] += line[i];
//		if (line[i] == sep) {
//			j++;
//		}
//	}
//	string* ptr = &arr[0];
//	return ptr;
//}
