#ifdef
#ifndef

#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

class hash{

	private:

		struct node{
			int val = INT_MIN;
			bool occupied = false;
			node *nextNode = NULL;
		}
		int hashSize = 0;
		vector<node> hashTable;

	public:

		explicit hash();
		bool insert(int val);
		int getHashSize();
		void newHash(int size);
		struct node *search(int val);
		~hash();
		

}

#endif
