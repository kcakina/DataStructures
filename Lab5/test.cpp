#include <iostream>
#include "tree.h"

using namespace std;

void ansMe();

int main() {
  cout << "Hello World" << endl;
  tree * r = new tree;
  r->insert(5);
  r->insert(6);
  r->insert(4);
  r->insert(0);
  r->insert(7);
  r->sorted();
  cout << endl;
  r->deleteNode(7);
  cout << endl;
  r->printTree(r->getRoot());
  cout << endl << "Searching for 5...";
  cout << r->search(5) << endl;
  cout << endl;
  cout << r->successor(r->search(7)) << endl;
  cout << endl;
  cout << r->predecessor(r->search(5)) << endl;
  cout << r->search(13) << endl;
  ansMe();
  return 0;
}

void ansMe() {

  char QUIT = 'q';
  char ans = 'a';

  while (ans != QUIT) {
    cout << "Enter Q to quit:";
    cin >> ans;
  }
}
