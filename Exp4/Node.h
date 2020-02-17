#pragma once
#include <string>
using namespace std;

class Node {
private:
	string name;
	bool isCovered;
public:

	Node() {
		isCovered = false;
	}

	void setName(string name)
	{
		this->name = name;
	}

	bool isCover() {
		return isCovered;
	}
	void setEnableCover() {
		isCovered = true;
	}

	void setDisableCover() {
		isCovered = false;
	}

	string getName()
	{
		return name;
	}

	Node* getAddress() {
		return this;
	}
};
