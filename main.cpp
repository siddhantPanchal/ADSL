#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;


class Node {
private:

	string word;
	string mean;
	Node *leftChild;
	Node *rightChild;
	Node *parent;
	int height;
	int balencedFactor;

public:

	Node() {
		word = "";
		mean = "";
		leftChild = NULL;
		rightChild = NULL;
		parent = NULL;
		height = 0;
		balencedFactor = 0;
	}

	string getWord() {
		return word;
	}

	void setWord(string word) {
		this->word = word;
	}
	
	string getMean() {
		return mean;
	}

	void setMean(string mean) {
		this->mean = mean;
	}

	Node *getLeftChild() {
		return leftChild;
	}

	void setLeftChild(Node *leftChild) {
		this->leftChild = leftChild;
	}

	Node *getRightChild() {
		return rightChild;
	}

	void setRightChild(Node *rightChild) {
		this->rightChild = rightChild;
	}

	Node *getParent() {
		return parent;
	}

	void setParent(Node *parent) {
		this->parent = parent;
	}

	int getHeight() {
		return height;
	}

	void setHeight(int height) {
		this->height = height;
	}

	int getBalencedFactor() {
		return balencedFactor;
	}

	void setBalencedFactor(int balencedFactor) {
		this->balencedFactor = balencedFactor;
	}
};


class BinaryTree {
private:
	
	Node *root;
	
	void insert(Node* n,Node* temp) {
		if(temp->getWord() > n->getWord()) {
			if(temp->getLeftChild() == NULL) {
				n->setParent(temp);
				temp->setLeftChild(n);
			}
			else
				insert(n,temp->getLeftChild());
		}
		else if(temp->getWord() < n->getWord()) {
			if(temp->getRightChild() == NULL) {
				n->setParent(temp);
				temp->setRightChild(n);
			}
			else 
				insert(n, temp->getRightChild());
		}
		else if(temp->getWord() == n->getWord()) {
			return;
		}
	//	cout<<"Inserted " ;
	}
	
protected:
	void setRoot(Node *root) {
		this->root = root;
	}
	
	virtual void insert(Node *n) {
		if(root == NULL) {
			root = n;
		}
		else
			insert(n, root);
	}
	
	
	void display(Node *temp) {
		if(temp == NULL)
			return;
		else {
			display(temp->getLeftChild());
			cout<<"Word : "<<temp->getWord() << " Mean : "<<temp->getMean();
			display(temp->getRightChild());
		}
	}
	
public:
	
	BinaryTree() {
		setRoot(NULL);
	}
	Node* getRoot() {
		return root;
	}

};

class AVLTree : public BinaryTree {

private:
	 Node* lastNode;
	 
	 int height(Node* temp) {
		if(temp == NULL)
			return 0;
		int count1 = height(temp->getLeftChild()) + 1;
		int count2 = height(temp->getRightChild()) + 1;
		int count = max(count1,count2);
		temp->setHeight(count);
		//cout<<temp->getWord()<< " height : " <<temp->getHeight();
		return count;
	}
	
	
	
	int balenceFactor(Node* n) {
		int balencedFactor = 0 , lh = 0 , rh = 0;
//		balencedFactor = n->getLeftChild()->getHeight() - n->getRightChild()->getHeight();
		if(n->getLeftChild() != NULL) {
			lh = n->getLeftChild()->getHeight();
		}else{
			lh = 0;
		}
		
		if(n->getRightChild() != NULL) {
			rh = n->getRightChild()->getHeight();
		}else{
			rh = 0;
		}
		
//		System->out->println("lh : "+lh+" Rh : "+rh);
		balencedFactor = lh - rh;
		n->setBalencedFactor(balencedFactor);
		return balencedFactor;
	}
	
	bool isBalenced(Node* temp) {
		if(temp == NULL) {
			return true;
		}
		else {
			int bf = balenceFactor(temp);
			lastNode = temp;
			//cout<<"lastNode : "<<lastNode->getWord();
			if(bf >= -1  && bf <= 1) {
				return isBalenced(temp->getLeftChild()) && isBalenced(temp->getRightChild());
			}
			else
				return false;
		}
	}
	
	void leftRotation(Node* temp) {
		if(temp == getRoot())
			setRoot(temp->getRightChild());
		else
			temp->getRightChild()->setParent(temp->getParent());
		temp->setRightChild(NULL);
		temp->setParent(NULL);
		BinaryTree::insert(temp);
	}
	
	void rightRotation(Node* temp) {
		if(temp == getRoot())
			setRoot(temp->getLeftChild());
		else
			temp->getLeftChild()->setParent(temp->getParent());
		temp->setLeftChild(NULL);
		temp->setParent(NULL);
		BinaryTree::insert(temp);
	}
	
	int search(string no,Node *temp) {
		static int count = 0;
		if(temp == NULL)
			return count;
		else {
			if(no == temp->getWord()) {
				cout<<"Word is found ";
				return count;
			}
			else {
				if(no > temp->getWord()) {
					search(no, temp->getRightChild());
				}
				else if(no < temp->getWord()) {
					search(no, temp->getLeftChild());
				}
				count = count + 1;
			}
		}
		return count;
	}
	
	 
public:

	
	AVLTree() {
		lastNode = NULL;
	}
	
	void insert(string word,string mean) {
		Node* n = new Node();
		//cout<<"vd";
		n->setWord(word);
		n->setMean(mean);
		BinaryTree::insert(n);
		height(getRoot());
		isBalenced(getRoot());
		//cout<<"lastNode : "<<lastNode->getWord();
		if(!isBalenced(getRoot())) {
			int lh = 0,rh = 0;
			if(lastNode->getLeftChild() != NULL) {
				lh = lastNode->getLeftChild()->getHeight();
			}else{
				lh = 0;
			}
			
			if(lastNode->getRightChild() != NULL) {
				rh = lastNode->getRightChild()->getHeight();
			}else{
				rh = 0;
			}
			if(lh > rh)
				rightRotation(lastNode);
			else 
				leftRotation(lastNode);
		}
	}

	void display() {
		BinaryTree::display(getRoot());
	}
	
	bool isBalenced() {
		height(getRoot());
		return isBalenced(getRoot());
	}
	
	int search(string no) {
		int searchCount = search(no,getRoot());
		return searchCount;
	}
}avl;


/*
 * 
 * 				5
 * 		3				7
 * 					6
 * 
 * */


int main(){
	int ch = 0;
	string word = "";
	string mean = "";
	while(true) {
		cout<<"\n1->Insert \n2->Display \n3->isBalenced \n10->Exit \nEnter your choice : ";
		cin>>ch;
		
		
		switch (ch) {
		case 1:
			cout<<"\nEnter word : ";
			cin>>word;
			cout<<"\nEnter mean : ";
			cin>>mean;
			avl.insert(word,mean);
			
			break;
			
		case 2:
			cout<<"\nSorted Word : ";
			avl.display();
			break;
			
		case 3:
			cout<<"\nEnter Search word : ";
			cin>>word;
			cout<<"\nSearch Count is : "<< avl.search(word);
			break;
		case 10:
			exit(0);
		default:
			cout<<"\nPlease enter valid choice : ";
			break;
		}
	}
	return 0;
}
