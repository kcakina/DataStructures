#include "myArray.h"
#include <string>
#include <iostream>
#include <vector>

// Constructor
myArrayClass::myArrayClass(int size) {

	// Arrays
	data = new int[size];
	dataUsed = new bool[size];
	dataLocked = new bool[size];
	len = size;

	//Assuming values ranging from 0 - 100
	countSize = 101;
	dataCount = new int[countSize];

	for (int i = 0; i < len; i++) {
		data[i] = INT_MIN;
		dataUsed[i] = false;
		dataLocked[i] = false;
	}

}
/*
This is a copy Constructor
*/
myArrayClass::myArrayClass(const myArrayClass& source) { // Copy Constructor

	//cout << "Copy Constructor Called" << endl;
	this->data = new int[source.len];
	this->dataUsed = new bool[source.len];
	this->dataLocked = new bool[source.len];
	this->dataCount = new int[source.countSize];
	this->len = source.len;

	
	for (int i = 0; i < source.len; i++) { // copies all data
		data[i] = source.data[i];
		this->dataUsed[i] = source.dataUsed[i];
		this->dataLocked[i] = source.dataLocked[i];
		//cout << data[i] << " ";
	}

	for (int i = 0; i < source.countSize; i++) { // copies count
		this->dataCount[i] = source.dataCount[i];
	}
	return;
}

/*
This is a Overloaded assignment opperator
*/
myArrayClass& myArrayClass::operator=(const myArrayClass& source) { // Overloaded Assignment Operator
	//cout << "OverLoaded Assignment Called. " << endl;
	if (this == &source) {
		return *this;
	}

	for (int i = 0; i < source.len; i++) { // copies all data
		data[i] = source.data[i];
		dataUsed[i] = source.dataUsed[i];
	}

	for (int i = 0; i < source.countSize; i++) { // copies count
		dataCount[i] = source.dataCount[i];
	}

	return *this;
}
 
/*
Sort takes in value a or d to dictate ascending or descending
*/
myArrayClass myArrayClass::sort(char sortOrder) {
	
	if (sortOrder == 'a') {
		myArrayClass *newSorted = new myArrayClass(*this);
		newSorted->quickSortAscending(0, newSorted->len - 1);
		return *newSorted;
	}
	else if (sortOrder == 'd') {
		myArrayClass *newSorted = new myArrayClass(*this);
		newSorted->quickSortDecending(0, newSorted->len - 1);
		return *newSorted;
	}
	else {
		cout << "invalid argument" << endl;
	}
	return *this;
}
/*
Sort defaults to ascending
*/
myArrayClass myArrayClass::sort(void) {
	
	myArrayClass *newSorted = new myArrayClass(*this);
	newSorted->quickSortAscending(0, newSorted->len - 1);
	return *newSorted;
}

/*
QuickSort Ascending Order - I learned this implementaion from here
https://www.youtube.com/watch?v=aQiWF4E8flQ
*/
void myArrayClass::quickSortAscending(int left, int right) {

	int i = left; 
	int j = right;
	int temp;
	bool tempBool;
	bool tempLock;
	int pivot = data[(left + right) / 2];
	//cout << "quickSortAscending" << endl;

	while (i <= j) {
		while (data[i] < pivot) {
			i++;
		}
		while (data[j] > pivot) {
			j--;
		}
		if (i <= j) {
			// data change
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
			// used change
			tempBool = dataUsed[i];
			dataUsed[i] = dataUsed[j];
			dataUsed[j] = tempBool;
			// lock change
			tempLock = dataLocked[i];
			dataLocked[i] = dataLocked[j];
			dataLocked[j] = tempLock;

			i++;
			j--;
		}
	}

	if (left < j)
		quickSortAscending(left, j);
	if (i < right)
		quickSortAscending(i, right);
}

/*
QuickSort Ascending Order - I learned this implementaion from here
https://www.youtube.com/watch?v=aQiWF4E8flQ
*/
void myArrayClass::quickSortDecending(int left, int right) {

	int i = left;
	int j = right;
	int temp;
	bool tempBool;
	bool tempLock;
	int pivot = data[(left + right) / 2];

	while (i <= j) {
		while (data[i] > pivot) { // I think this is right
			i++;
		}
		while (data[j] < pivot) { // I think this is right
			j--;
		}
		if (i <= j) {
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;

			//
			tempBool = dataUsed[i];
			dataUsed[i] = dataUsed[j];
			dataUsed[j] = tempBool;
			//
			tempLock = dataLocked[i];
			dataLocked[i] = dataLocked[j];
			dataLocked[j] = tempLock;
			i++;
			j--;
		}
	}

	if (left < j)
		quickSortDecending(left, j);
	if (i < right)
		quickSortDecending(i, right);

}

/*
This function finds the exclusive case within the array
I borrowed your implementation from class
*/
int myArrayClass::singular2(){
  
  int xOr = data[0];
  for (int i = 1; i < len; i++) {
	xOr = xOr^data[i];
  }
  return xOr;
}

/*
returns length of the myArrayClass
*/
int myArrayClass::length() {
	return len;
}

/*
Reads given index passed only if the data has been used
*/
int myArrayClass::read(int index) {
	
	if (dataUsed[index]) { // if Data used at index
		return data[index];
	}
	else {
		cout << "Index has not been used" << endl;
		return -1;
	}

}

/*
writes to given fucntion
*/
bool myArrayClass::write(int index, int value) {

	if (value == INT_MIN) {
		cout << "invalid value" << endl;
		return false;
	}

	if (dataLocked[index]) { // if Data used at index
		cout << "Index Locked... Cannot store value at this index..." << endl;
		return false;
	}
	else {
		data[index] = value;
		dataUsed[index] = true;
		return true;
	}
}

/*
Locks given index
*/
void myArrayClass::lock(int index) {
	dataLocked[index] = true;
}

/*
unlocks given index
*/
void myArrayClass::unlock(int index) {
	dataLocked[index] = false;
}
/*
counts number of locks in array
*/
int myArrayClass::lockCount() {

	int count = 0;

	for (int i = 0; i < len; i++) {
		if (dataLocked[i] == true)
			count++;
	}

	return count;
}
/*
Searches for given value in array
*/
int myArrayClass::search(int value) {

	for (int i = 0; i < len; i++) {
		if (data[i] == value)
			return i;
	}
	return -1;
}

/*
returns data array from given object
*/
int* myArrayClass::getData() {
	return data;
}
/*
returns dataUsed array from given object
*/
bool* myArrayClass::getDataUsed() {
	return dataUsed;
}
/*
Prints data
*/
void myArrayClass::printData() {
	
	cout << endl << "DATA: ";
	for (int i = 0; i < this->len ; i++) {
		cout << this->data[i] << ' ';
	}
	cout << endl;
}
/*
prints dataUsed
*/
void myArrayClass::printDataUsed() {
	
	cout << endl << "DATA USED: ";
	for (int i = 0; i < len; i++) {
		cout << dataUsed[i] << ' ';
	}
	cout << endl;
}
/*
prints data locked
*/
void myArrayClass::printDataLocked() {
	
	cout << endl << "DATALOCKED: ";
	for (int i = 0; i < len; i++) {
		cout << dataLocked[i] << ' ';
	}
	cout << endl;
}
/*
return length of given array
*/
int myArrayClass::getLength() {
	return len;
}
/*

*/
int myArrayClass::select(int k) {
	
	cout << endl;
	if (k > this->len || k <= 0) {
		cout << "Invalid Argument" << endl;
		return -1;
	}
	myArrayClass *temp = new myArrayClass(*this);
	cout << "ORDERED ARRAY: ";
	temp->sort();
	temp->printData();
	cout << k << temp->place(k) << " Power = ";
	int kPower = temp->read(k - 1);
	return kPower;

}

myArrayClass myArrayClass::reverse() {

	if (this->len <= 1)
		return *this;

	myArrayClass *reArr = new myArrayClass(*this);
	int temp;
	int j = reArr->len - 1;

	if (reArr->len % 2 == 0) {
		for (int i = 0; i < len / 2; i++) {
			temp = reArr->data[i];
			reArr->data[i] = reArr->data[j];
			reArr->data[j] = temp;
			j--;
		}
	}
	else {
		for (int i = 0; i < len / 2 + 1; i++) {
			temp = reArr->data[i];
			reArr->data[i] = reArr->data[j];
			reArr->data[j] = temp;
			j--;
		}
	}
	return *reArr;
}

bool myArrayClass::palindrome() {

	myArrayClass *reverse = new myArrayClass(this->reverse());

	for (int i = 0; i < len; i++) {
		if (reverse->data[i] != this->data[i]) {
			return false;
		}
	}
	return true;

}

string myArrayClass::place(int index) {

	if (index == 1) {
		return "st";
	}
	if (index == 2) {
		return "nd";
	}
	if (index == 3) {
		return "rd";
	}
	if (index >= 4) {
		return "th";
	}

}

myArrayClass::~myArrayClass() { // Destructor
	
	//cout << "Destructor Called " << endl;
	delete[] data;
	delete[] dataUsed;
	delete[] dataCount;
}





