#include <string>
#include <iostream>
#include <vector>
#include <climits>

class hash {

public:


	struct node {
		int val;
		bool used;
		int sisterVal;
		node *nextNode;
	};

	struct node *hashTable;
	int numElements;
	int hashSize;

	//Functions
	explicit hash();
	bool insert(int val);
	bool resize();
	void print();
	struct node* search(int val);
	~hash();

};

hash::hash() {
	hashTable = new hash::node[10];
	hashSize = 10;
	numElements = 0;

	for (int i = 0; i < 10; i++) {
		hash::node *newNode = new hash::node;
		newNode->used = false;
		newNode->val = INT_MIN;
		newNode->sisterVal = INT_MIN;
		newNode->nextNode = NULL;
		hashTable[i] = *newNode;
	}

}

hash::~hash() {

}

bool hash::insert(int val) {
	
	if (numElements >= hashSize / 2) {
		resize();
	}

	int index = val % hashSize;
	if (hashTable[index].used == false) {
		hashTable[index].val = val;
		hashTable[index].used = true;
		hashTable[index].sisterVal = INT_MIN;
	}
	else {
		//std::cout << "working" << std::endl;
		hash::node *ptr = new hash::node;
		ptr = (hashTable + index);
		hash::node *newNode = new hash::node;
		newNode->val = val;
		while(ptr->nextNode != NULL){
			ptr = ptr->nextNode;
		}
		std::cout << "working" << std::endl;
		ptr = newNode;
	}
		

	
	numElements++;
	//std::cout << numElements << "\n";
	print();
	return true;
}

bool hash::resize() {

	std::cout << "Resize... numElements: " << numElements <<  "\n";
	int newSize = hashSize * 2;
	hash::node *newHash = new hash::node[hashSize];

	for (int i = 0; i < newSize; i++) {
		hash::node *newNode = new hash::node;
		newNode->nextNode = NULL;
		newNode->val = INT_MIN;
		newNode->used = false;
		newHash[i] = *newNode;
	}

	int index;
	for (int i = 0; i < hashSize; i++) {
		index = hashTable[i].val % hashSize;
		if (newHash[index].used == false) {
			newHash[index] = hashTable[i];
		}
		else {
			int linear = 0;
			while (newHash[linear].used == true) {
				linear++;
			}
			newHash[linear] = hashTable[i];
		}
	}
	hashSize = newSize;
	hashTable = newHash;
}

hash::node * hash::search(int val){
	
	int index = val % hashSize;
	hash::node *returnNode = new hash::node;
	if(hashTable[index].used == false){
		std::cout << "Not found1" << std::endl;
		return NULL;
	}else{
		if(hashTable[index].val == val){
			std::cout << "Found1" << std::endl;
			return returnNode;
		}
		hash::node *ptr = (hashTable + index);
		while(ptr != NULL){
			if (ptr->val == val){
				std::cout << "Found!" << std::endl;
				return ptr;
			}
			ptr = ptr->nextNode;
		}

	}
	std::cout << "Not found" << std::endl;
	return NULL;
}

void hash::print(){

	for (int i = 0; i < hashSize; i++) {
		if (hashTable[i].val == INT_MIN)
			std::cout << "X ";
		else{
			std::cout << hashTable[i].val << " ";
		}
	}
std::cout << std::endl;
}

int main() {
	hash a;
	
	a.insert(5);
	a.insert(23);
	a.insert(3);
	a.search(3);
	a.insert(1);
	a.insert(9);
	a.insert(10);
	a.insert(15);
	a.insert(5);
	a.insert(69);

	std::cout << a.search(5) << "\n";
	std::cout << a.search(23) << "\n";

	return 0;
}