#include<iostream>
#include "Dictionary.h"
using namespace std;

int main()
{
	Dictionary d;
	int ch = 0;
	do
	{
		cout << "\n1.insert new value \n2.display \n3.delete \n4.search \n10.exit \nEnter your choice : ";
		cin >> ch;
		switch (ch)
		{
		case 1:d.insert();
			break;
		case 2:d.display();
			break;
		case 3:d.delet();
			break;
		case 4:d.search();
			break;
		case 10:
			exit(0);
		default:
			break;
		}
	} while (true);
	return 0;
}
