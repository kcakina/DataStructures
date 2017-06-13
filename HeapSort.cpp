#include <string>
#include <iostream>


using namespace std;

int data[10];
int heapSize = 10;

void heapafy();
int parent(int index);
int left(int index);
int right(int index);
int maxNode(int current, int left, int right);
bool bounds(int index);
void maxHeap();
void print();

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

	int temp;
	for (int i = heapSize - 1 ; i > 0 ; i--){
		if (!bounds(i)){
			if(data[i] < data[left(i)]){
				temp = data[i];
				data[i] = data[left(i)];
				data[left(i)] = temp;
			}
		}else{
			if(data[i] < data[left(i)] || data[i] < data[right(i)]){
				temp = data[i];
				data[i] = data[maxNode(i,left(i),right(i))];
				data[maxNode(i)] = temp;
			}
		}
	}
}

int parent(int index){
	return (index-1)/2;
}

int left(int index){
	return 2*index+1;
}

int right(int index){
	return 2*index+2;
}

int maxNode(int current, int left, int right){

	if (data[current] > data[left] && data[current] > data[right]){
		return current;
	}

	if (data[left] > data[current] && data[left] > data[current]){
		return left;
	}else{
		return right;
	}
}

void print(){
	
	for (int i = 0 ; i < heapSize ; i++){
		cout << data[i] << ' ';
	}
}

bool bounds(int index){

	if (right(index) > data.size() - 1)
		return false;
	else
		return true;
}