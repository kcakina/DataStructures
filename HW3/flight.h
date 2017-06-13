/*
Keoni Akina
HW3

This Program was intended to simulate a airtraffic management
*note - I was unsuccessful in getting my parser to work properly, the example of it is at the bottom outside the scope of the
class definition as ParseAttempt as well as Flight Parser.

The rest is well written and there are severarl functions to handle edge cases.

*/

#ifndef FLIGHT_H
#define FLIGHT_H

#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>
#include <array>
#include <fstream>

using namespace std;

class Flight {

	public:
		
		struct flightNode {

			int flightID;
			char flightType;
			string from;
			string to;
			int time[2];
			flightNode *left = NULL;
			flightNode *right = NULL;

		};

		// Variables
		int flightCount;
		vector<array<int,2>> flightTimes;
		struct flightNode *takeOffs;
		struct flightNode *landings;
		struct flightNode *allFlightsByTime = NULL;
		struct flightNode *allFlightsByNum = NULL;
		const int hour = 0;
		const int minute = 1;
		int insertCount = 0;

		// Dummy Variables
		struct flightNode *root;

		// Poser Variables
		const char T = 'T';
		const char L = 'L';
		const int MAXHOUR = 23;
		const int MAXMINUTE = 59;

		// alterations
		struct flightNode * insertFlightByTime(struct flightNode *root, int flightID, char flightType, string from, string to, int time[2]);
		struct flightNode * insertFlightByNumber(struct flightNode *root, int flightID, char flightType, string from, string to, int time[2]);
		void insertBoth(int flightID, char flightType, string from, string to, int time[2]);

		// Client Functions
		explicit Flight();
		void fillTimes(vector<array<int,2>> &flightTimes, int n);
		struct flightNode * deleteFlightNum(struct flightNode *root, int flightID);
		struct flightNode * deleteFlightTime(struct flightNode *root, int time[2]);
		void deleteBoth(int flightID);
		struct flightNode * Arrivals();
		struct flightNode * Departures();
		struct flightNode * nextTakeOff();
		struct flightNode * nextDeparture();
		void quickSortAscHour(vector<array<int,2>> &, int left, int right);
		void quickSortAscMin(vector<array<int, 2>> &, int left, int right);
		void subset(vector<array<int, 2>> &, int n);
		void printFlightTimes();
		void printFlights(struct flightNode * root);
		void parser(string fileName);
		array<int,2> getCommands(string data);

		// Ghetto Functions
		bool isValidTime(struct flightNode *data, int time[2]);
		bool isValidNumber(struct flightNode *data, int flightNum);
		bool timeEdgeCase(int m1, int m2);
		bool compareTimes(int time1[2], string boolOP, int time2[2]);
		bool checkRange(int time1[2], int time[2]);
		struct flightNode * minValueNode(struct flightNode *root);
		struct flightNode * timeToFlightNumber(struct flightNode * root, struct flightNode *root2);
		struct flightNode * traverseTimeDelete(struct flightNode *root, int flightID);

		//debug function
		void debugFunction(string message);

		~Flight();

	private:

};

#endif //
