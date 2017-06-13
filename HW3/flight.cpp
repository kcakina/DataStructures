/*
Keoni Akina
HW3

This Program was intended to simulate a airtraffic management
*note - I was unsuccessful in getting my parser to work properly, the example of it is at the bottom outside the scope of the 
class definition as ParseAttempt as well as Flight Parser.

The rest is well written and there are severarl functions to handle edge cases.

*/


#include "flight.h"
#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
#include <array>
#include <fstream>
#include <sstream>

using namespace std;

Flight::Flight() {

	
	string airports[10];
	airports[0] = "DIA";
	airports[1] = "SEA";
	airports[2] = "LAX";
	airports[3] = "YYZ";
	airports[4] = "POR";
	airports[5] = "KRK";
	airports[6] = "DEP";
	airports[7] = "AFI";
	airports[8] = "=w=";
	airports[9] = "POO";

	int testTime[2];
	testTime[hour] = 3;
	testTime[minute] = 33;
	
	flightCount = 10;
	flightTimes.resize(flightCount);
	fillTimes(flightTimes, flightCount);
	printFlightTimes();
	
	insertBoth(69, 'L', "TEX", "SEA", testTime);

	int j = flightCount - 1;
	int h;
	int m;
	for (int i = 1; i < flightCount; i++) {
		int newTime[2] = { flightTimes[i][hour],flightTimes[i][minute] };
		insertBoth(i + 12, 'T', airports[i], airports[j], newTime);
		j--;
	}
	
	insertBoth(123, 'T', "SFX", "LTD", testTime);

	// After insertion
	printFlights(allFlightsByTime);
	cout << endl;
	printFlights(allFlightsByNum);

	deleteBoth(123);

	// After Deletion
	cout << endl << endl << endl;
	printFlights(allFlightsByTime);
	cout << endl;
	printFlights(allFlightsByNum);
	
}

// Times
void Flight::fillTimes(vector<array<int, 2>> &data, int flightCount) {


	int hour = 0;
	int minute = 1;
	vector<array<int, 2>> *newArray = new vector<array<int, 2>>;

	for (int i = 0; i < flightCount; i++) {
		data[i][hour] = rand() % 23 + 0;
		data[i][minute] = rand() % 59 + 0;
	}
	data = *newArray;
	//printFlightTimes();
}

Flight::flightNode * Flight::insertFlightByTime(Flight::flightNode *root, int flightID, char flightType, string from, string to, int time[2]) {

	//cout << "INSERT CALLED" << endl;

	Flight::flightNode *newNode = new Flight::flightNode;
	newNode->flightID = flightID;
	newNode->flightType = flightType;
	newNode->from = from;
	newNode->to = to;
	newNode->time[hour] = time[hour];
	newNode->time[minute] = time[minute];
	
	if (root == NULL) {
		//cout << "insert root == null" << endl;
		return newNode;
	}
	
	insertCount++;

	while (!isValidTime(root, newNode->time)) {
		//cout << "ISVALID" << endl;
		if (newNode->time[minute] == MAXMINUTE) { // if minute == 59
			if (newNode->time[hour] == MAXHOUR) { // if hour == 23
				newNode->time[hour] = 0;
			}
			newNode->time[minute] = 0;
			newNode->time[hour]++;
		}
		else {
			newNode->time[minute]++;
		}
	}

	Flight::flightNode *parent = NULL, *current = root;

	while (current != NULL) {
		parent = current;
		if (compareTimes(current->time, "<=", time))
			current = current->right;
		else
			current = current->left;
	}


	if (compareTimes(parent->time, "<=", time)) {
		parent->right = newNode;
	}else {
		parent->left = newNode;
	}
	return root;
}

Flight::flightNode * Flight::insertFlightByNumber(Flight::flightNode *root, int flightID, char flightType, string from, string to, int time[2]) {

	//cout << "INSERT CALLED" << endl;

	Flight::flightNode *newNode = new Flight::flightNode;
	newNode->flightID = flightID;
	newNode->flightType = flightType;
	newNode->from = from;
	newNode->to = to;
	newNode->time[hour] = time[hour];
	newNode->time[minute] = time[minute];

	if (root == NULL) {
		return newNode;
	}

	/*
	if (!isValidNumber(allFlightsByTime, flightID)) {
		cout << "ERROR: DUPLICATE ENTRIES NOT ALLOWED" << endl;
		delete newNode;
		return root;
	}
	*/

	Flight::flightNode *parent = NULL, *current = root;

	while (current != NULL) {
		parent = current;
		if (current->flightID < flightID)
			current = current->right;
		else
			current = current->left;
	}


	if (parent->flightID < flightID) {
		parent->right = newNode;
	}
	else {
		parent->left = newNode;
	}
	return root;
}

void Flight::insertBoth(int flightID, char flightType, string from, string to, int time[2]) {
	this->allFlightsByNum = insertFlightByNumber(this->allFlightsByNum, flightID, flightType, from, to, time);
	this->allFlightsByTime = insertFlightByTime(this->allFlightsByTime, flightID, flightType, from, to, time);
}

Flight::flightNode * Flight::deleteFlightNum(Flight::flightNode *root,int flightID) {

	cout << "DeleteFlight(int)" << endl;

    if (root == NULL) 
		return root;
 
	if (flightID < root->flightID) {
		root->left = deleteFlightNum(root->left, flightID);
	}

	else if (flightID > root->flightID) {
		root->right = deleteFlightNum(root->right, flightID);
	}

    else
    {
		//cout << "FOUND" << endl;
        // node with only one child or no child
        if (root->left == NULL)
        {
            Flight::flightNode *temp = root->right;
            //free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Flight::flightNode *temp = root->left;
            //free(root);
            return temp;
        }
 
        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        Flight::flightNode *temp = minValueNode(root->right);
 
        // Copy the inorder successor's content to this node
        root->flightID = temp->flightID;
 
        // Delete the inorder successor
        root->right = deleteFlightNum(root->right, temp->flightID);
    }
    return root;
}

Flight::flightNode * Flight::deleteFlightTime(Flight::flightNode *root, int time[2]) {

	//cout << "DeleteFlight(int)" << endl;

	if (root == NULL)
		return root;

	if (compareTimes(time, "<" ,root->time)) {
		//cout << "time < root->time" << endl;
		root->left = deleteFlightTime(root->left, time);
		
	}

	else if (compareTimes(time, ">", root->time)) {
		//cout << "time < root->time" << endl;
		root->right = deleteFlightTime(root->right, time);
	}

	else
	{
		
		// node with only one child or no child
		if (root->left == NULL)
		{
			Flight::flightNode *temp = root->right;
			//free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			Flight::flightNode *temp = root->left;
			//free(root);
			return temp;
		}

		// node with two children: Get the inorder successor (smallest
		// in the right subtree)
		Flight::flightNode *temp = minValueNode(root->right);

		// Copy the inorder successor's content to this node
		root->flightID = temp->flightID;

		// Delete the inorder successor
		root->right = deleteFlightTime(root->right, temp->time);
	}
	return root;
}

void Flight::deleteBoth(int flightID) {
	allFlightsByNum = deleteFlightNum(allFlightsByNum, flightID);
	traverseTimeDelete(allFlightsByTime, flightID);
}

Flight::flightNode * Flight::Arrivals() {
	return allFlightsByTime;
}

Flight::flightNode * Flight::Departures() {
	return allFlightsByTime;
}

Flight::flightNode * Flight::nextTakeOff() {
	return allFlightsByTime;
}

Flight::flightNode * Flight::nextDeparture() {
	return allFlightsByTime;
}

void Flight::quickSortAscHour(vector<array<int,2>> &arr, int left, int right) {
	
	//char thing = 'a';
	int i = left, j = right, hour = 0;
	array<int, 2> temp;
	int pivot = arr[(left + right) / 2][hour];
	//cout << "Pivot: " << pivot << endl;

	/* partition */
	while (i <= j) {
		while (arr[i][hour] < pivot)
			i++;
		while (arr[j][hour] > pivot)
			j--;
		//cout << "i: " << i << " j: " << j << endl;
		if (i <= j) {
			//debugFunction("while loop");
			temp = arr[i];
			//debugFunction("temp = arr[i]");
			arr[i] = arr[j];
			//debugFunction("arr[i] = arr[j]");
			arr[j] = temp;
			//debugFunction("arr[j] = temp");
			i++;
			j--;
			//debugFunction("J++ j--");
		}
	};

	/* recursion */
	if (left < j)
		quickSortAscHour(arr, left, j);
	if (i < right)
		quickSortAscHour(arr, i, right);
}

void Flight::quickSortAscMin(vector<array<int, 2>> &data, int left, int right) {

	//cout << "QUICKMIN called" << endl;

	int hour = 0;
	int minute = 1;
	int i = left;
	int j = right;
	int pivot = data[(left + right)/2][minute];
	array<int, 2> temp;
	//cout << "quickSortAscending" << endl;

	while (i <= j) {
		while (data[i][minute] < pivot) {
			i++;
		}
		while (data[j][minute] > pivot) {
			j--;
		}
		if (i <= j) {
			// data change
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
			i++;
			j--;
		}
	};

	if (left < j)
		quickSortAscMin(data, left, j);
	if (i < right)
		quickSortAscMin(data, i, right);
}

void Flight::subset(vector<array<int, 2>> &data, int n) {
	
	//cout << "subset called" << endl;

	int j = 0;
	int hour = 0;
	int minute = 1;

	for (int i = 0; i < n; ) {
		j = i;
		while (data[i][hour] == data[j+1][hour]) {
			j++;
		}
		if (i != j) { 
			quickSortAscMin(data, i, j);
			//debugFunction("after");
			i = j + 1;
		}
		else {
			i++;
		}
	}

}

void Flight::printFlightTimes() {

	int hour = 0;
	int minute = 1;
	string hr = "";
	string min = "";

	cout << "Flight Times" << endl;
	for (int i = 0; i < flightCount ; i++) {
		if (flightTimes[i][hour] < 10) {
			 hr = "0";
		}
		if (flightTimes[i][minute] < 10) {
			min = "0";
		}
		cout << hr << flightTimes[i][hour] << ":" << min <<flightTimes[i][minute] << " ";
		hr = "";
		min = "";
	}

	cout << endl;

}

void Flight::printFlights(Flight::flightNode *root) {

	if (root == NULL)
		return;
	if (root == allFlightsByTime)
		cout << "ALL FLIGHTS BY TIME" << endl;
	if (root == allFlightsByNum)
		cout << "ALL FLIGHT BY NUMBER" << endl;
	
	printFlights(root->left);

	cout << "FL#" << root->flightID << ' ';
	cout << root->flightType << ' ';
	cout << root->from << ' ';
	cout << root->to << ' ';
	cout << root->time[hour] << ":" << root->time[minute] << endl;

	printFlights(root->right);
}

void Flight::parser(string fileName) {

	string commands;
	ifstream myfile(fileName);
	int nmCom[2];

	if (myfile.is_open()) {
		while (getline(myfile, commands)) {
			cout << commands;
		}
		myfile.close();
	}

	//getCommands(commands);
	
}

array<int, 2> Flight::getCommands(string data) {

	char newLine = '\n';
	char space = ' ';
	string convert = "";
	array<int, 2> commands;

	for (int i = 0; i < data.size() ; i++) {
		while (data[i] != space || data[i] != newLine) {
			data[i];
		}
	}
	return commands;
}

// Ghetto Functions
bool Flight::isValidTime(Flight::flightNode *data, int time[2]) {

	//cout << "isValidTime" << endl;
	if (data == NULL) {
		// cout << "isValue data == Null" << endl;
		return true;
	}

	int hour = 0;
	int minute = 1;
	int h1 = data->time[hour];
	int h2 = time[hour];
	int m1 = data->time[minute];
	int m2 = time[minute];

	if (!isValidTime(data->left, time)) {
		return false;
	}
	if (!checkRange(data->time, time)) {
		return false;
	}
	if (!isValidTime(data->right, time)) {
		return false;
	}
	
	return true;
}

// Passes in Flight Number to make sure its valid entry *no duplicates!
// Probably woulnd't be safe
bool Flight::isValidNumber(Flight::flightNode *root, int flightNum) {

	if (root == NULL)
		return true;
	if (!isValidNumber(root->left, flightNum))
		return false;
	if (root->flightID == flightNum)
		return false;
	if (!isValidNumber(root->right, flightNum))
		return false;
	return true;
}

bool Flight::timeEdgeCase(int m1, int m2) {

	cout << "timeEdgeCase" << endl;

	if ((m1 == 59 && m2 == 01) || (m1 == 59 && m2 == 00) || (m1 == 58 && m2 == 00))
		return false;
	return true;
}

bool Flight::compareTimes(int time1[2], string boolOp, int time2[2]) {
	
	//cout << "compare times" << endl;

	int h1 = time1[hour];
	int h2 = time2[hour];
	int m1 = time1[minute];
	int m2 = time2[minute];


	if (boolOp == ">") {
		if (h1 > h2)
			return true;
		if (h1 == h2 && m1 > m2)
			return true;
		return false;
	}

	if (boolOp == ">=") {
		if (h1 > h2)
			return true;
		if (h1 == h2 && m1 == m2)
			return true;
		if (h1 == h2 && m1 > m2)
			return true;
		return false;
	}

	if (boolOp == "==") {
		if (h1 == h2 && m1 == m2)
			return true;
		return false;
	}

	if (boolOp == "<") {
		if (h1 < h2)
			return true;
		if (h1 == h2 && m1 < m2)
			return true;
		return false;
	}

	if (boolOp == "<=") {
		if (h1 < h2)
			return true;
		if (h1 == h2 && m1 == m2)
			return true;
		if (h1 == h2 && m1 < m2)
			return true;
		return false;
	}

	if (boolOp == "!=") {
		if (h1 != h2 || m1 != m2)
			return true;
		return false;
	}
}

Flight::flightNode * Flight::minValueNode(Flight::flightNode *root) {

	if (root->left == NULL)
		return root;
	else
		return(root->left);
}

Flight::flightNode * Flight::traverseTimeDelete(Flight::flightNode *root, int flightID) {

	if (root == NULL)
		return root;
	traverseTimeDelete(root->left, flightID);
	if (root->flightID == flightID) {
		return deleteFlightTime(allFlightsByTime, root->time);
	}
	traverseTimeDelete(root->right, flightID);
}

// Debug Helpers
void Flight::debugFunction(string message) {
	
	printFlightTimes();
	cout << message << endl;
	cin.ignore();
}

bool Flight::checkRange(int time1[2], int time2[2]) {

	int h1 = time1[hour];
	int h2 = time2[hour];
	int m1 = time1[minute];
	int m2 = time2[minute];
	int minTime = 3;

	if (h1 > h2) {
		if (h1 - h1 > 1) {
			return true;
		}
		if (h1 - h2 == 1) {
			if (m1 - m2 >= minTime) {
				return true;
			}
			return timeEdgeCase(m2, m1);
		}
	}

	 if (h2 > h1) {
		if (h2 - h1 > 1) {
			return true;
		}
		if (h2 - h1 == 1) {
			if (m1 - m2 >= minTime) {
				return true;
			}
			return timeEdgeCase(m1, m2);
		}
	}
	else { // h1 == h2
		return (abs(m1 - m2) >= minTime);
	}
}

Flight::~Flight() {

}
