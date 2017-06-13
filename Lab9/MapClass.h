#ifndef MAPCLASS_H
#define MAPCLASS_H

#include <map>

using namespace std;

class MapClass {



public:

	map<int, string> myMap;
	int mapSize;
	explicit MapClass();
	void insert(int key, string data);
	string getKeyValue(int key);
	void printAll();

private:
};

#endif