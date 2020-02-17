#pragma once
#include <string>
#include "Node.h"
using namespace std;

class Edge {
private:
	string name;
	Node* source;
	Node* destination;
	int weight;
	
public:
	//initillizer
	Edge() {
		name = "";
		source = destination = NULL;
		weight = 0;
	}
	//setters
	void setName(string name) {
		this->name = name;
	}

	void setSource(Node* source) {
		this->source = source;
	}

	void setDestination(Node* destination) {
		this->destination = destination;
	}

	void setWeight(int weight) {
		this->weight = weight;
	}
	
	//getters
	string getName() {
		return name;
	}

	Node* getSource() {
		return source;
	}

	Node* getDestination() {
		return destination;
	}

	int getWeight() {
		return weight;
	}
};
