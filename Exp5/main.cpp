#include<iostream>
#define max 5
using namespace std;

class TelphoneBook {
public:
	int key;
	string name;
	long long int tel_no;
	TelphoneBook* next;
	TelphoneBook(){
		key = -1;
		tel_no = 0;
		next = NULL;
	}


};

class HashTable {
private:
	TelphoneBook* TB[10];
public:
	HashTable() {
		for (int i = 0; i < 10; i++)
		{
			TB[i] = NULL;
		}
	}
	void accept() {
		TelphoneBook* n=new TelphoneBook;
		cout << "\nEnter Name of client : ";
		cin >> n->name;
		cout << "\nEnter Telphone no : ";
		cin >> n->tel_no;
		n->key = n->tel_no % max;
		if (TB[n->key] == NULL) {
			TB[n->key] = n;
		}
		else {
			TelphoneBook* temp = TB[n->key];
			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = n;
		}
	}

	void display() {
		for (int i = 0; i < 10; i++)
		{
			if (TB[i] != NULL) {
				TelphoneBook* temp = TB[i];
				while (temp != NULL)
				{
					cout << "\nkey : " << temp->key;
					cout << "\tName of Client : " << temp->name;
					cout << "\tTelephone No of Client : " << temp->tel_no;
					temp = temp->next;
				}
			}
		}
	}

	void search() {
		long long int key = 0;
		cout << "\nEnter telephone no to be search : ";
		cin >> key;
		if (TB[key % max] != NULL) {
			TelphoneBook* temp = TB[key%max];
			while (temp != NULL)
			{
				if (temp->tel_no == key) {
					cout << "\nkey : " << temp->key;
					cout << "\tName of Client : " << temp->name;
					cout << "\tTelephone No of Client : " << temp->tel_no;
					break;
				}
				temp = temp->next;
			}
		}
	}
};

int main()
{
	HashTable t;
	int ch = 0;
	do
	{
		cout << "\n1.Enter new Telphone No in book \n2.Display Book \n3.Search Telphone no \nEnter your choice : ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			t.accept();
			break;
		case 2:
			t.display();
			break;
		case 3:
			t.search();
			break;
		case 10:
			exit(0);
		}
	} while (1);
	return 0;
}
