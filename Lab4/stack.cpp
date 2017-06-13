#include <iostream>
#include <cassert>
#include <cstdlib>

using namespace std;

class stack {

private:
	int *s;
	int sp;
	int capacity;

public:
	explicit stack(int size = 1) { // Contructor
		s = new int(size);
		capacity = size;
		sp = 0;
	}

	~stack() {
		delete[] s;
	}

	void push(int val) {
		assert(sp < capacity);
			s[sp] = val;
			sp++;
		return;
	}

	int pop() {
		assert(sp > 0);
			sp--;
		return s[sp];
	}

	bool empty() {
		if (sp == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	bool full() {
		if (sp == capacity) {
			return true;
		}
		else {
			return false;
		}
	}

	void print() {

		cout << endl;
		for (int i = 0; i < this->getCapacity() - this->getSp() ; i++) {
			cout << s[i] << ' ';
		}
		cout << endl;
	}

	int getCapacity() {
		return capacity;
	}

	int getSp() {
		return sp;
	}


};

void ansMe();

int main()
{
	cout << "Hello World" << endl;
	stack s(10);
	cout << "s.empty(): " << s.empty() << endl;
	s.push(12);
	s.push(10);
	s.push(7);
	s.push(8);
	cout << "s.empty():" << s.empty() << endl;
	
	for (int i = s.getSp() ; i < s.getCapacity(); i++) {
		s.push(rand() % 100);
	}

	cout << "s.full(): " << s.full() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	

	ansMe();
	return 0;
}

void ansMe() {
	char QUIT = 'q';
	char ans = 'a';

	while (QUIT != ans) {
		cout << "Enter q to quit: ";
		cin >> ans;
	}
	return;
}
