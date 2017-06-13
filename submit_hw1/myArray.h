#ifndef MYARRAYCLASS_H
#define MYARRAYCLASS_H

#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

class myArrayClass {

public:

  
  explicit myArrayClass(int size); // Constructor
	myArrayClass(const myArrayClass& source); // Copy Constructor
	myArrayClass& operator=(const myArrayClass& source); // OAO
	~myArrayClass();

	//int main(void); // Main Function
	int length(); // Returns Length of myArray object
	int read(int index); // Retuns value at given index
	bool write(int index, int value);
	void lock(int index);
	void unlock(int index);
	int lockCount();
	int search(int value);
	void printData();
	void printDataUsed();
	void printDataLocked();
	int select(int k);
	int singular2();

	//void singular2(int dataCount[]);

	//Sort Functions
	myArrayClass sort(char sortOrder);
	myArrayClass sort(void);
	myArrayClass reverse();
	void quickSortAscending(int left, int right);
	void quickSortDecending(int left, int right);
	bool palindrome();

	string place(int index);


	// Get Functions
	int *getData();
	bool *getDataUsed();
	int getLength();

private:
	// arrays
	int *data;
	bool *dataLocked;
	bool *dataUsed;
	
	int len;
	int list;
	int *dataCount;
	int countSize;



};

#endif
