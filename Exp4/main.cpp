#include<iostream>
#include "Graph.h"
using namespace std;


int main() {
	int ch = 0;
	Graph g;	//here we are considering just one graph  so one object is sufficient
	do
	{
		cout << "\n1.Create new graph \n2.Add Edge \n3.Display list of vertices"
			"\n4.minimum spanning tree\nEnter your choice : ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			g.create();	//call only once in running phase of programe
			break;
		case 2:
			g.addEdge();
			break;
		case 3:
			g.display();
			break;
		case 4:
			cout << "\n\t\t Spanning Tree : ";
			g.findMinimumSpnningTree();
			break;
		case 10:
			cout << "\n\t\t\t\t\tThank you for using this software\n\n";
			exit(0);   //for Stop the programe by entering choice 10
		}
	} while (1);
	return 0;
}
