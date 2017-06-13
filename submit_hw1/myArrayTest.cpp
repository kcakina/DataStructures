/*
Author: Keoni Akina
Program: my_array_test.cpp
Last Modification: <Oct 16 2016>
*/

/*
This is a Client Program that tests
myArrayClass implementation
*/
#include <iostream>
#include <string>
#include <stdlib.h>
#include "myArray.h"

using namespace std;

void ansMe();
void ansContinue();
void testLockandUnlock();
void testSearch();
void testSingular();
void testSort();
void testSort2();
void testSelect();
void testReverse();
void testPalindrome();

int main() {
  
	testLockandUnlock();
	testSearch();
	testSingular();
	//testSort2();
	testSelect();
	testReverse();
	testPalindrome();
  
  
	ansMe();
		return 0;
	
}

void testLockandUnlock() {
	// LOCK and Unlock
	cout << endl << "TESTING Read, Write, LOCK AND UNLOCK" << endl;
	ansContinue();

	myArrayClass a(5);
	cout << "Attempting to read from an unused index..." << endl;
	cout << a.read(3) << endl;

	for (int i = 0; i < 5; i++) {
		a.write(i, rand() % 100);
	}

	a.lock(3);
	a.lock(0);
	a.printData();
	a.printDataLocked();
	cout << "Number of Locked Indexes: " << a.lockCount() << endl;
	cout << "Attempting to write locked index..." << endl;
	a.write(3, rand());

	a.unlock(3);
	a.unlock(0);
	a.printData();
	a.printDataLocked();
	cout << "Number of Locked Indexes: " << a.lockCount() << endl;
	// End Lock and Unlock
}

void testSearch() {
	
	// test Search
	cout << endl << "TESTING SEARCH" << endl;
	ansContinue();

	myArrayClass b(5);

	int inArray = 0;
	int notinArray = INT_MAX;
	for (int i = 0; i < 5; i++) {
		inArray = rand() % 100;
		b.write(i, inArray);
	}

	b.printData();
	int tempOut = b.search(inArray);
	cout << "Searching for value: " << inArray << ": " << endl;
	if (tempOut != -1) {
		cout << "Index: " << tempOut << endl;
	}
	else {
		cout << "Not found... " << endl;
	}

	tempOut = b.search(notinArray);
	cout << "Searching for value: " << notinArray << ": " << endl;
	if (tempOut != -1) {
		cout << "Index: " << tempOut << endl;
	}
	else {
		cout << "Not found... " << endl;
	}
	// End Test Search
}

void testSingular() {
	
	cout << endl << "TESTING SINGULAR2" << endl;
	ansContinue();

	// Test Singular2
	myArrayClass c(5);
	c.write(0, 1);
	c.write(1, 1);
	c.write(2, 2);
	c.write(3, 3);
	c.write(4, 3);

	c.printData();
	cout << "xor = " << c.singular2() << endl;
	// End Test Singular2
}

void ansMe() {
	
	const char QUIT = 'q';
	char user = 'a';

	while (user != QUIT) {
		cout << "Enter q to quit: ";
		cin >> user;

	}
}

void ansContinue() {
	const char CONTINUE = 'c';
	char user = 'a';

	while (user != CONTINUE) {
		cout << "Enter c to contine: ";
		cin >> user;

	}
}

void testSort() {
	
	cout << "Testing Sort" << endl;
	ansContinue();

	myArrayClass a(5);
	for (int i = 0; i < a.getLength() ; i++) {
		a.write(i, rand() % 100);
	}

	cout << endl;
	myArrayClass d = a.sort();
	cout << "myArrayClass a(5); ";
	a.printData();
	cout << "myArrayClass d = a.sort(); ";
	d.printData();
	cout << endl;

	myArrayClass b(5);
	for (int i = 0 ; i < b.getLength() ; i++){
	  b.write(i, rand() % 100);
	}
	
	cout << "SEGFAULT?" << endl;
	myArrayClass e = b.sort('a');
	cout << "myArrayClass b(5); ";
	b.printData();
	cout << "myArrayClass e = b.sort('a'); ";
	e.printData();
	cout << endl;
	cout <<"See me?" << endl;

	myArrayClass f = a.sort('d');
	cout << "myArrayClass a(5); ";
	a.printData();
	cout << "myArrayClass f = a.sort('d'); ";
	f.printData();
	cout << endl;
	
}

void testSort2() {
	myArrayClass a(5);
	for (int i = 0; i < a.getLength(); i++) {
		a.write(i, rand() % 100);
	}
	a.printData();

	myArrayClass b = a.sort('d');
	b.printData();

	myArrayClass c = a.sort('a');
	c.printData();
	
}

void testSelect() {

	cout << endl << "TESTING SELECT" << endl;
	ansContinue();
	myArrayClass a(10);
	for (int i = 0; i < a.getLength(); i++) {
		a.write(i, rand() % 100);
	}

	cout << "Searching for 1st,5th,10th and 11th order value..." << endl;
	ansContinue();
	cout << "Original Array: ";
	a.printData();
	cout << a.select(1) << endl;
	cout << a.select(5) << endl;
	cout << a.select(10) << endl;
	cout << a.select(11) << endl;

}

void testReverse() {
	
	cout << endl << "TESTING REVERSE" << endl << endl;
	ansContinue();
	myArrayClass a(10);
	for (int i = 0; i < a.getLength(); i++) {
		a.write(i, rand() % 100);
	}

	cout << "First Array: ";
	a.printData();
	myArrayClass *b = new myArrayClass(a.reverse());
	cout << endl;
	cout << "First Array: ";
	a.printData();
	cout << "Reversed Array: ";
	b->printData();

}

void testPalindrome() {

	cout << "TESTING PALINDROME" << endl;
	ansContinue();

	myArrayClass a(5);
	a.write(0, 1);
	a.write(1,2);
	a.write(2,3);
	a.write(3,2);
	a.write(4,1);
	a.printData();
	
	if (a.palindrome())
		cout << "This is a palindrome" << endl;

	myArrayClass b(5);
	b.write(0, 1);
	b.write(1, 2);
	b.write(2, 7);
	b.write(3, 8);
	b.write(4, 1);
	b.printData();

	if (!b.palindrome())
		cout << "This is not a palindrome..." << endl;


}
