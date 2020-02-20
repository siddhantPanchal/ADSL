#pragma once
#include "Pair.h"

class Dictionary {
private:
	Pair* p[10];   //set of pair that stores key and value 

	void insert(int key ,int value) {
		Pair* n = new Pair();
		n->setKey(key);
		n->setValue(value);

		Pair* temp = p[key];
		if (p[key] == NULL) {
			p[key] = n;
			temp = n;
		}
		else {
			while (temp->getNext() != NULL)
			{
				if (temp->getValue() == value)
					return;
				temp = temp->getNext();
			}
			temp->setNext(n);
		}
	}

	void delet(int key, int value) {
		Pair* temp = p[key];
		bool isFound = false;

		if (temp == NULL)
		{
			cout << "\n\tWrong value ";
		}
		else if (temp->getValue() == value)
		{
			p[key] = temp->getNext();
			free(temp);
			isFound = true;
		}
		else
		{
			Pair* temp1 = temp;
			temp = temp->getNext();
			while (temp != NULL) {
				if (temp->getValue() == value)
				{
					temp1->setNext(temp->getNext());
					isFound = true;
					break;
				}
				temp1 = temp;
				temp = temp->getNext();
			}
		}

		if (isFound) {
			cout << "\n\tDeleted successfully ";
		}
		else
			cout << "\n\tValue is not found ";
	}

public:

	Dictionary() {
		for (int i = 0; i < 10; i++)
			p[i] = NULL;
	}


	void insert() {
		int value = 0;
		cout << "\nEnter value : ";
		cin >> value;
		//hashing
		int key = value % 10;
		//inserting
		insert(key, value);
	}

	void display() {
		int i = 0;
		for (; i < 10; i++) {
			Pair* temp = p[i];
			if (temp == NULL)
				continue;
			else
			{
				while (temp!=NULL)
				{
					cout << "\n\tkey : " << temp->getKey() << "\tValue : " << temp->getValue();
					temp = temp->getNext();
				}
			}
		}
	}


	void delet() {
		int value = 0;
		cout << "\nEnter Vlue to be deleting : ";
		cin >> value;

		int key = value % 10;

		delet(key, value);

	}

	void search() {
		int value = 0, key = 0;
		cout << "\nEnter value : ";
		cin >> value;
		key = value % 10;
		if (p[key] == NULL) {
			cout << "\nNot Found ";
		}
		else if(p[key]->getValue() == value) {
			cout << "Value found at : " << key;
		}
		else {
			Pair* temp = p[key];
			while (temp != NULL) {
				if (temp->getValue() == value)
					cout << "Value found at : " << key;
				temp = temp->getNext();
			}
		}
		
	}


};
