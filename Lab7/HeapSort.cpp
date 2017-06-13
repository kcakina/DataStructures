#include <string>
#include <iostream>
#include <cstdlib>
#include <climits>

using namespace std;

int data[10];
int heapSize = 10;

void heapafy();
int parent(int index);
int left(int index);
int right(int index);
bool bounds(int index);
void maxHeap();
void print();
void siftDown(int val);
bool isLeaf(int index);

int main(){

	for (int i = 0 ; i < heapSize ; i++){
		data[i] = rand() % 100;
	}

	print();
	cout << endl;
	maxHeap();
	print();

	return 0;
}

void maxHeap(){

	for (int i = heapSize/2 -1 ; i >= 0 ; i--){
		siftDown(i);
	}
}

int left(int index){
	return 2*index+1;
}

int right(int index){
	return 2*index+2;
}

void print(){
	
	for (int i = 0 ; i < heapSize ; i++){
		cout << data[i] << ' ';
	}
}

void siftDown(int index){

	int temp;
	int idx = index;

	while(!isLeaf(idx)){
		if(data[idx] > data[left(idx)]  && data[idx] > data[right(idx)]){
			return;
		}

		if (data[left(idx)] > data[right(idx)]){
			temp = data[idx];
			data[idx] = data[left(idx)];
			idx = left(idx);
		}else{
			temp = data[idx];
			data[idx] = data[right(idx)];
			idx = right(idx);
		}

	}
}

bool isLeaf(int index){

	if (left(index) < heapSize || right(index) < heapSize){
		return false;
	}
	return true;
}