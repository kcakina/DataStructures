#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

struct node {
	int val;
	node * next;
};

// variables
node *arr = NULL;
static const int listSize = 10;

// fucntions
node * reverseNode(node *arr);
node * createValues();
node * helper(node *arr, node *newNextValu);
node * insert(node *head, int val);
void print(node *head);

int main() {
	
	node* newList;
	newList = createValues();
	print(newList);
	newList = reverseNode(newList);
	print(newList);
	return 0;

}

node * reverseNode(node *arr) {
	
	node * newHead = arr;
	node * temp1 = arr;
	node * temp2 = temp1->next;

	while (newHead->next != NULL) {
		newHead = newHead->next;
	}
	while (temp1 != newHead) {
		temp1->next = newHead->next;
		newHead->next = temp1;
		temp1 = temp2;
		temp2 = temp2->next;
	}

	return arr;
}

node *createValues() {
	
	node * newList;
	newList = NULL;
	
	for (int i = 0; i < listSize; i++) {
		newList = insert(newList, rand() % 10 + 0);
	}
	return newList;

}

node * insert(node *head, int val) {

	node *ptr = head;
	node *newNode = new node;
	newNode->val = val;
	newNode->next = NULL;

	if (head == NULL) {
		return newNode;
	}

	while (ptr->next != NULL) {
		ptr = ptr->next;
		//cout << "Insert while" << endl;
	}
	//out << "Insert" << endl;
	ptr->next = newNode;
	return head;
}

void print(node * arr) {

	if (arr == NULL)
		return;

	cout << "print "<<endl;

	node * ptr = arr;

	while (ptr != NULL) {
		cout << ptr->val << " ";
		ptr = ptr->next;
	}
	cout << endl;

}