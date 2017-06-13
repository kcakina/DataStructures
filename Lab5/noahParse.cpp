#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int outMessageLen = 15;

float retirement(int amount);

int main(){

	cout <<  "Money Saved:" << retirement(100000) << endl;
	return 0;
}

float retirement(int amount){

	int total = 0;
	
	for (int i = 0; i < 30 ; i++){
		total += amount *(1 + 0.03);
	}

	return total;
}

