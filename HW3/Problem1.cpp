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
node * createValues(node *arr);
node * helper(node *arr, node *newNextValu);
node * insert(node *head, int val);
void print(node *head);

int main() {

	node * newList = new node;
	newList = createValues(newList);
	print(newList);
	newList = reverseNode(newList);
	print(newList);
	return 0;
}

node * reverseNode(node *arr) {
	
	node * newHead = arr;
	node * temp1 = arr;
	node * temp2;

	while (newHead->next != NULL) {
		newHead = newHead->next;
	}
	while (temp1->next != newHead) {
		cout << "reverse While" << endl;
		newHead = helper(newHead,temp1);
		temp1 = temp1->next;
	}

	return arr;
}

node *createValues(node * arr) {
	
	if (arr == NULL)
		return arr;
	
	for (int i = 0; i < listSize; i++) {
		insert(arr, rand() % 10 + 0);
	}
	return arr;

}

node * insert(node *head, int val) {


	if (head == NULL) {
		head->val = val;
		head->next = NULL;
		return head;
	}

	node *ptr = head;
	node *newNode = new node;
	newNode->val = val;
	newNode->next = NULL;
	ptr->val = val;

	while (ptr->next != NULL) {
		ptr = ptr->next;
		cout << "Insert while" << endl;
	}
	cout << "Insert" << endl;
	ptr->next = newNode;
	return head;
}

node * helper(node * arr, node * newNextValue) {

	node * ptr = arr;
	cout << "helper" << endl;
	while (ptr->next != NULL) {
		cin.ignore();
		cout << "helper while" << endl;
		ptr = ptr->next;
	}
	cout << "helper2" << endl;
	ptr->next = newNextValue;
	return arr;
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