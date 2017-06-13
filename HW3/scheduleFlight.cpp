/*
Keoni Akina
HW3

This Program was intended to simulate a airtraffic management
*note - I was unsuccessful in getting my parser to work properly, the example of it is at the bottom outside the scope of the
class definition as ParseAttempt as well as Flight Parser.

The rest is well written and there are severarl functions to handle edge cases.

*/

#include "flight.h"


struct flightCList {
	int flightID;
	char type;
	string from;
	string to;
	int time[2];
};


void flightParser(flightCList &data, string command, int spaces);

int main() {

	Flight myFlights;

	return 0;
}

int parseAttempt() {

	Flight myFlights;

	string line;
	ifstream myFile("flight.in.txt");
	//int numFlights, numCommands;
	vector<flightCList> flightSchedule;


	if (myFile.is_open()) {

		string command = "";
		int commands[2];
		int numFlights, numCommands;
		int j = 0;

		// parses the commands N and M
		getline(myFile, line);
		for (int i = 0; i < line.size(); i++) {
			while (line[i] != ' ') {
				command += line[i];
				i++;
			}

			commands[j] = stoi(command);
			j++;
			command = "";
		}

		//
		numFlights = commands[0];
		numCommands = commands[1];

		flightSchedule.resize(numFlights);

		// This section parses through the Flight Commands
		command = "";

		int i = 0;
		int space = 0;

		for (int i = 0; i < numFlights; i++) {
			flightCList newFlight;
			getline(myFile, line);
			for (int j = 0; j < line.size(); j++) {
				while (line[j] != ' ' && j <= line.size()) {
					command += line[j];
					cout << line[j] << ' ' << endl;
					cin.ignore();
					j++;
				}
				flightParser(newFlight, command, space);
				command = "";
				space++;
			}

			command = "";
			flightSchedule[i] = newFlight;
		}

		cout << "TEST CODE" << endl;

		for (int i = 0; i < numFlights; i++) {
			cout << flightSchedule[i].flightID << endl;
			cout << flightSchedule[i].from << endl;
			cout << flightSchedule[i].to << endl;
			cout << flightSchedule[i].time[0] << ':' << flightSchedule[i].time[1] << endl;
		}
		/*
		cout << "END TEST CODE" << endl;

		//cout << numCommands << endl;

		for (int i = 0; i < numCommands; i++) {
		getline(myFile, line);
		for (int j = 0; j < line.size(); j++) {
		while (line[j] != ' ') {
		command += line[j];
		j++;
		}
		}
		cout << command << endl;
		command = "";
		}

		}
		*/
	}
	myFile.close();
	return 0;
}

void flightParser(flightCList &flightCommand, string data, int spaces) {

	cout << "Flight Parser" << endl;

	if (spaces == 0) {
		cout << "flightID: " << data;
		flightCommand.flightID = stoi(data);
	}

	if (spaces == 1) {
		cout << "type: " << data;
		flightCommand.type = data[0];
	}

	if (spaces == 2) {
		cout << "from: " << data;
		flightCommand.from = data;
	}

	if (spaces == 3) {
		cout << "to: " << data;
		flightCommand.to = data;
	}

	if (spaces == 4) {
		int i = 0;
		string newTime = "";
		string newTime2 = "";
		while (data[i] != ':') {
			newTime += data[i];
			i++;
		}
		for (int j = i + 1; j < i + 3; j++) {
			//cout << data[j] << endl;
			newTime2 += data[j];
		}
		int hour = 0;
		int minute = 1;
		cout << "newTime: " << newTime << " newTime2: " << newTime2 << endl;
		//flightCommand.time[hour] = stoi(newTime);
		//flightCommand.time[minute] = stoi(newTime2);
	}
}