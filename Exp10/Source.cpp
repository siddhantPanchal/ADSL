#include<iostream>
#include<fstream>
#include<string>
#include "String.h"
using namespace std;


class Student {
private:

	string roll;
	string name;
	string address;
	string division;
	fstream file;

	string format(Student* s) {
		string line = "\n"; 
		line += "Roll no : " + s->roll;
		line += ",Name : " + s->name + ",Address : " + s->address + ",Division : " + s->division;
		return line;
	}

	Student format(string line) {
		int j = 0;
		string arr[4];
		for (int i = 0; i < len(line); i++) {
			if (line[i] == ',') {
				j++;
				i++;
			}
			arr[j] += line[i];
		}

		Student s(arr[0], arr[1], arr[2], arr[3]);
		return s;
		
	}

	void write(Student *s) {
		string line = format(s);
		file.open("Record.txt", ios::app);
		file << line;
		file.close();
	}

	void displayData() {
		cout << roll << endl;	cout << name << endl;
		cout << division << endl;	cout << address << endl;
	}

public:

	Student() {
		roll = "";
		name = "";
		address = "";
		division = "";
	}

	Student(string roll, string name, string address, string division) {
		this->roll = roll;
		this->name = name;
		this->address = address;
		this->division = division;
	}

	void accept() {
		cout << "\nEnter roll no : ";
		cin >> roll;
		cout << "\nEnter name of student : ";
		cin >> name;
		cout << "\nEnter division of student : ";
		cin >> division;
		cout << "\nEnter address of student : ";
		cin >> address;
		write(this);
	}

	void display() {
		Student student;
		bool isFound = false;
		string rollno = "";
		cout << "\nEnter Roll No : ";
		cin >> rollno;
		file.open("Record.txt");
		string line = "";
		while (!file.eof()) {
			getline(file , line);
			if (find(line, rollno)) {
				student =  format(line);
				isFound = true;
				break;
			}
		}

		if (!isFound)
			cout << "\nRoll no : " << rollno << " is not present ";
		else
			student.displayData();
		file.close();
	}

};

int main() {
	Student s;
	int size = 0;
	int ch = 0;
	do {
		cout<<"\n1.Insert new Student info \n2.Delete \n3.Display perticular Student info \nEnter Your choice : ";
		cin >> ch;
		switch (ch) {
		case 1:
			s.accept();
			break;
		case 2:
			break;
		case 3:
			s.display();
			break;
		case 10:
			exit(0);
		}
	} while (true);
	return 0;
}