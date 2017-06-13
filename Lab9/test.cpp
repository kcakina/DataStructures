#include "MapClass.h"
#include <iostream>
#include <string>

using namespace std;

int main();

int main() {


	MapClass myMap;
	myMap.printAll();
	myMap.insert(72, "Modest Mouse");
	myMap.printAll();

	return 0;

}
