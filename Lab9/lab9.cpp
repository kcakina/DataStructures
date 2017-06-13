#include <iostream>
#include <map>

using namespace std;

void example1();
void example2();
void example3();
void example4();
void example5();

std::map<char, int> myMap;

int main (){
	//std::map<char,int> myMap;
	myMap['a']=10;
	myMap['b']=30;
	myMap['c']=50;
	myMap['d']=70;
	cout<<myMap.size()<<endl;

	//example1();
	//example2();
	//example3();
	//example4();
	example5();

	return 0;
}

void example1() {
	for (map<char, int>::iterator it = myMap.begin(); it != myMap.end(); ++it)    
		cout << it->first << " => " << it->second << '\n';
}

void example2() {
	for (map<char, int>::reverse_iterator it = myMap.rbegin(); it != myMap.rend(); ++it)
		cout << it->first << " => " << it->second << '\n';
}

void example3() {
	for (map<char, int>::iterator it = myMap.begin(); it != myMap.end(); advance(it, 3))     
		cout << it->first << " => " << it->second << '\n';
}

void example4() {
	for (auto it = myMap.begin(); it != myMap.end(); ++it)
		cout << it->first << " => " << it->second << '\n';
}

void example5() {
	for (auto it = myMap.begin(); it != myMap.end(); ++it) { 
		cout << it->first << " => " << it->second << '\n';   
		it->second += 5;
	}  
	for (auto it = myMap.cbegin();
		it != myMap.cend(); ++it) {
		cout << it->first << " => " << it->second << '\n'; 
	}  
	
}