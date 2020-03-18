#include<iostream>
using namespace std;

int main() {
	int heap[10] = {};
	int no = 0;
	cout << "\nEnter No. of  marks : ";
	cin >> no;
	for (int i = 0; i < no; i++) {
		cout << "\nEnter Marks : ";
		cin >> heap[i];

		for (int j = 0; j < i; j++) {
			if (heap[i] > heap[j]) {
				//swap(&heap[i], &heap[j]);
				int temp = heap[i];
				heap[i] = heap[j];
				heap[j] = temp;
			}
		}
	}

	for (int i = 0; i < no; i++)
	{
		cout << "\t" << heap[i];
	}

	cout << "\nMaximum marks is : " << heap[0];
	cout << "\nMinimum Mark is : " << heap[no - 1];

	return 0;
}