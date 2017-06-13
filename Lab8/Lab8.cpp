#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

struct interval {
	int left;
	int right;
};

int * icp1(interval * a, int n);
//int * labMarked(interval *a, int n);
void quicksort(interval *a, int left, int right);
void quicksortDec(interval *a, int left, int right);
const int intervalSize = 9;
int markedSize = intervalSize;
interval data[intervalSize];
void subset(interval *data, int size);
void icp2(interval *data, int n);

int main() {

	interval data[9];
	for (int i = 0; i < 9; i++) {
		data[i].left = -1;
		data[i].right = -1;
	}

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

	data[7].left = 1;
	data[7].right = 3;

	data[8].left = 6;
	data[8].right = 8;

	cout << "UNSORTED" << endl;

	for (int i = 0; i < 9; i++) {
		cout << '[' << data[i].left << ':' << data[i].right << ']';
	}

	cout << endl;
	
	// mark things
	int *marked = icp1(data, 9);

	// Perform Quicksort
	icp2(data, intervalSize);
	cout << endl;
	
	for (int i = 0; i < 9; i++) {
		cout << '[' << data[i].left << ':' << data[i].right << ']';
	}
	
	cout << endl;

	for (int i = 0; i < markedSize; i++) {
		cout << marked[i] << ' ';
	}

	cout << endl;
	
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


void quicksort(interval *data, int left, int right) {

	int i = left;
	int j = right;
	interval temp;
	int pivot = data[(left + right) / 2].left;
	//cout << "quickSortAscending" << endl;

	while (i <= j) {
		while (data[i].left < pivot) {
			i++;
		}
		while (data[j].left > pivot) {
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
	}
	

	if (left < j)
		quicksort(data, left, j);
	if (i < right)
		quicksort(data, i, right);
}


void quicksortDec(interval *data, int left, int right) {

	int i = left;
	int j = right;
	interval temp;
	int pivot = data[(left + right) / 2].right;
	//cout << "quickSortAscending" << endl;

	while (i <= j) {
		while (data[i].right > pivot) {
			i++;
		}
		while (data[j].right < pivot) {
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
	}


	if (left < j)
		quicksort(data, left, j);
	if (i < right)
		quicksort(data, i, right);
}

void subset(interval *data, int n) {

	int j = 0;

	for (int i = 0; i < n; ) {
		while (data[i].left == data[j].left) {
			j++;
		}
		if (i != j) {
			quicksortDec(data, i, j);
			i = j + 1;
			j++;
		}
		else {
			i++;
		}
	}
	
}

void icp2(interval *data, int intervalSize) {

	int left = 0;
	int right = intervalSize;

	quicksort(data, left, right);
	subset(data, intervalSize);
	icp1(data, intervalSize);


}