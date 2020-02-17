#pragma once
#include<iostream>
using namespace std;

class Pair {
private:
	int key, value;
	Pair* next;
public:

	Pair() {
		key = -1, value = -1;
		next = NULL;
	}


	void setKey(int key) {
		this->key = key;
	}

	int getKey() {
		return key;
	}

	void setValue(int value) {
		this->value = value;
	}

	int getValue() {
		return value;
	}

	void setNext(Pair* next) {
		this->next = next;
	}

	Pair* getNext() {
		return next;
	}


};
