#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;


void ansMe() {
	char QUIT = 'q';
	char ans = 'a';
	while (QUIT != ans) {
		cout << "Enter q to Quit:";
		cin >> ans;
	}
}

class doubleLink {

public:

	explicit doubleLink();
	void insertNode(int val, int dir);
	void deleteValue(int val);
	void deleteList();
	void printList(int dir);
	void array2List(int *a, int n);
	~doubleLink();

	struct node {
		int val;
		node *front = NULL;
		node *back = NULL;
	};

	node *head;
};


doubleLink::doubleLink() {
	head = NULL;

}

void doubleLink::insertNode(int val, int dir) {

	if (head == NULL) {
		node *p = new node;
		p->val = val;
		p->back = NULL;
		p->front = NULL;
		head = p;
		return;
	}


	node *ptr = head;
	node *newNode = new node;
	newNode->val = val;

	if (dir == 1) {
		while (ptr->front != NULL) {
			ptr = ptr->front;
		}

		ptr->front = newNode;
		newNode->back = ptr;
		newNode->front = NULL;
	}

	if (dir == 0) {
		head->back = newNode;
		newNode->front = head;
		head = newNode;
	}
	return;

}

void doubleLink::deleteValue(int val) {

	node *ptr = head;
	node *delPtr;

	while (ptr != NULL) {
		if (ptr->val == val) {
			delPtr = ptr;
			ptr->back->front = ptr->front;
			ptr->front->back = ptr->back;
			delete delPtr;
		}
		ptr = ptr->front;
	}
	return;
}

void doubleLink::deleteList() {
	if (head == NULL) {
		return;
	}

	node *ptr = head;
	node *delPtr;

	while (ptr != NULL) {
		delPtr = ptr;
		ptr = ptr->front;
		delete delPtr;
	}

	return;

}

void doubleLink::printList(int dir) {

	node *ptr = head;

	if (dir == 0){
	while (ptr != NULL) {
		cout << ptr->val << " ";
		ptr = ptr->front;
		}
	cout << endl;
	}

	if (dir == 1){
	while (ptr->front != NULL){
		ptr = ptr->front;
	}
	while (ptr != NULL){
		cout << ptr->val << " ";
		ptr = ptr->back;
	}
	}
	cout << endl;

	return;
}

/*
void doubleLink::array2List(int *a, int n){
	
	for (int i = 0 ; i < n ; i++){
		cout << a[i] << " ";
		this->insertNode(index);
	}
}
*/

doubleLink::~doubleLink() {

}

void ansMe();

int main() {


	doubleLink a;

	a.insertNode(1, 0);
	a.insertNode(2, 0);
	a.insertNode(3, 0);
	a.printList(0);
	ansMe();
	a.insertNode(4, 1);
	a.insertNode(5, 1);
	a.insertNode(6, 1);
	a.printList(0);
	ansMe();
	a.deleteValue(5);
	a.printList(0);
	ansMe();
	a.printList(1);


	//a.array2List(newArray,10);
	//a.printList(0);
	ansMe();


	return 0;
}