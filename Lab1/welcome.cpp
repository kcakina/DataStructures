/*rogram: welcome.cpp
Last Modification: <09/26/2016>*//*
Description: this program prints a welcome message to the
name you  provide as the input.*/

#include <iostream>
#include <string>
using namespace std;

int main(){
  string name;
  cout << "What is your name?";
  cin >> name;
  cout << "Welcome " << name << "!" << endl;
  return 0;
}
