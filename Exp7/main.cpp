#include<iostream>
#include<algorithm>
#define size 3
using namespace std;

int keys[] = { 10, 20, 30 };
int freq[] = { 2, 5, 3 };

void display(int a[]) {
	cout << "\nTree : ";
	for (int i = 1; i < 10; i++) {
		cout << " " << a[i];
	}
}

int findCost(int rootIndex) {
	int head = rootIndex;
	int tail = 0;
	if (head == 0)
		tail = size - 1;
	else
		tail = head - 1;
	//cout << "\n" << rootIndex;

	int tree[10];
	int level = 0;
	int cost = 0, i = 1;

	tree[1] = keys[rootIndex];
	do{
		//cout << "\nHead : " << head;
		if (keys[rootIndex] > keys[head])
			i = 2 * i;
		else if (keys[rootIndex] < keys[head])
			i = 2 * i + 1;
		tree[i] = keys[head];
		level += 1;
		cost = cost + (level * freq[head]);
		//cout << "\n i : " << i;
		//cout << "\tCost : "<< cost;
		head = (head + 1) % size;
	}while (head != (tail+1)%size);
	//display(tree);
	return cost;
}



int main()
{
	int cost = 0;
	/*for (int i = 0; i < size; i++) {
		cout << "\n\t" << i << "th iteration";
		int cost = findCost(i);
	}*/

	cost = min(min(findCost(1), findCost(2)), findCost(3));
	cout << "\tCost : "<< cost;
	return 0;
}