#pragma once
#include<iostream>
#include<string>
#include<algorithm>
#include "Node.h"
#include "Edge.h"
using namespace std;
class Graph {
private:
	int vno, currentEdges, currentEdgesInTree;
	Edge setOfEdges[10];
	Node setOfNodes[5];
	Edge setOfEdgesInTree[10];
	int IgnoreSet[10];
	int index;

	void setIgnoreSet() {
		for (int i = 0; i < index; i++) {
			IgnoreSet[i] = -1;
		}
	}


	Node* getAddressByName(string name) {
		for (int i = 0; i < vno; i++) {
			if (setOfNodes[i].getName() == name) {
				//cout << setOfNodes[i].getAddress()->getName() << endl;
				return setOfNodes[i].getAddress();
			}
		}
		return NULL;
	}

	void connect(Node* from, Node* to) {
		if (from == NULL || to == NULL) {
			cout << "Invalid name of nodes ";
		}
		else {
			Edge e;	string name;	int w = 0;
			cout << "\nEnter name : ";	
			cin>>name;
			e.setName(name);
			cout << "Enter Weight : ";
			cin >> w;
			e.setWeight(w);
			e.setSource(from);
			e.setDestination(to);
			setOfEdges[currentEdges] = e;
			currentEdges++;
		}
	}

	void sort() {
		for (int i = 0; i < currentEdges; i++){
			for (int j = i+1; j < currentEdges; j++) {
				if (setOfEdges[i].getWeight() > setOfEdges[j].getWeight()) {
					Edge temp = setOfEdges[i];
					setOfEdges[i] = setOfEdges[j];
					setOfEdges[j] = temp;
				}
			}
		}
	}

	bool isInIgnoreSet(int no) {
		for (int i = 0; i < index; i++)
		{
			if (IgnoreSet[i] == no)
				return true;
		}
		return false;
	}

	bool isMatchingWithDest(Node* source,Edge mainEdge) {
		for (int  i = 0; i < currentEdgesInTree; i++)
		{
			if (!(isInIgnoreSet(i))) {
				if (source == setOfEdgesInTree[i].getSource()) {
					IgnoreSet[index] = i; index++;
					isMatchingWithDest(setOfEdgesInTree[i].getDestination(),mainEdge);
				}
				else if (source == setOfEdgesInTree[i].getDestination()) {
					IgnoreSet[index] = i; index++;
					isMatchingWithDest(setOfEdgesInTree[i].getSource(), mainEdge);
				}
			}
			else {
				if (source == mainEdge.getDestination()) {
					return true;
				}
				else {
					return false;
				}
			}
		}
	}



	bool isMakingLoop(Edge e) {
		setIgnoreSet();
		if (e.getSource()->isCover() && e.getDestination()->isCover()) {
			if (isMatchingWithDest(e.getSource() , e))
				return true;
			else
				return false;
		}
		return false;
	}

public:
	Graph() {
		vno = 0;
		currentEdges = 0;
		currentEdgesInTree = 0;
		index = 0;
	}

	void create() {
		string name = "";
		cout << "\nEnter no of vertices : ";
		cin >> vno;
		for (int i = 0; i < vno; i++) {
			cout << "\nEnter name : ";
			cin >> name;
			setOfNodes[i].setName(name);
			cout << "\nAdded Successfully";
		}
		cout << "\n\tGraph created successfully";
	}

	void addEdge() {
		string toString, fromString;
		cout << "\n\tFrom : ";
		cin>>fromString;
		cout << "\n\tTo : ";
		cin>>toString;
		connect(getAddressByName(fromString),getAddressByName(toString));
	}

	void display() {
		for (int i = 0; i < currentEdges; i++)
		{
			Edge e = setOfEdges[i];
			cout << "\nName of Edge : " << e.getName();
			cout << "\tSource : " << e.getSource()->getName();
			cout << "\tDestination : " << e.getDestination()->getName();
			cout << "\t\tWeight : " << e.getWeight();
		}
	}

	void findMinimumSpnningTree() {
		//step 1 : sort edges by weight
		//step 2 : check adding edge making closed loop
		//step 3 : if yes then don't add this edge 
		//step 4 : if not then add edge 
		//step 5 : repeat step 2 3 4 until end of the edge list

		sort();
		int index = 0;
		for (int i = 0; i < currentEdges; i++) {
			Edge e = setOfEdges[i];
			if (!isMakingLoop(e)) {
				e.getSource()->setEnableCover();	
				e.getDestination()->setEnableCover();
				setOfEdgesInTree[index] = e;
				index++;
			}
		}

		for (int i = 0; i < index; i++)
		{
			Edge e = setOfEdgesInTree[i];
			cout << "\nName of Edge : " << e.getName();
			cout << "\tSource : " << e.getSource()->getName();
			cout << "\tDestination : " << e.getDestination()->getName();
			cout << "\t\tWeight : " << e.getWeight();
		}
	}

};
