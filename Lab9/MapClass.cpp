#include "MapClass.h"
#include <iostream>
#include <string>
#include <map>
#include <string>
#include <cstdlib>

using namespace std;

MapClass::MapClass(){

	mapSize = 10;
	string words[10];
	words[0] = "RadioHead";
	words[1] = "Dillinger ESC Plan";
	words[2] = "The Beatles";
	words[3] = "Weezer";
	words[4] = "Bryan Adams";
	words[5] = "Curtis Mayfield";
	words[6] = "Johnny Smith";
	words[7] = "The Locust";
	words[8] = "GlassJaw";
	words[9] = "Converge";


	for (int i = 0; i < mapSize; i++) {
		int key = rand() % 20 + 0;
		insert(key, words[i]);
	}

}

void MapClass::insert(int key, string data) {

	myMap[key] = data;
	return;
}

string MapClass::getKeyValue(int key) {
	
	return myMap[key];
	
}

void MapClass::printAll() {
	cout << endl;
	for (auto it = myMap.begin(); it != myMap.end(); ++it)
		cout << it->first << " => " << it->second << '\n';
	cout << endl;
}

