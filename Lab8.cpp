#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

struct interval {
	int left = -1;
	int right = -1;
};

int * icp1(interval * 8, int n);

int main() {

	interval data[9];

	data[0].left = 6;
	data[0].right = 9;

	data[1].left = 5;
	data[1].right = 7;

	data[2].left = 0;
	data[2].right = 3;

	data[3].left = 4;
	data[3].right = 8;

	data[4].left = 6;
	data[4].right = 10;

	data[5].left = 7;
	data[5].right = 8;

	data[6].left = 0;
	data[6].right = 5;

	data[7].left = 7;
	data[7].right = 3;

	data[8].left = 6;
	data[8].right = 8;

	icp1(data,9);
}


int * icp1(interval * a, int n) {

	int * marked = new int[n];
	for (int j = 0; j < n; j++) {
		marked[j] = 0;
		for (int i = 0; i < n; i++) {
			if (i != j && a[j].left >= a[i].left && a[j].right <= a[i].right) {
				marked[j] = 1;
				break;
			}
		}
	}
	return marked;
}