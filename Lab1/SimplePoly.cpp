#include "SimplePoly.h"
#include <iostream>
#include <string>

using namespace std;

void SimplePoly::main(){

  SimplePoly P(5,-1);
  return 0;
  
}


SimplePoly::SimplePoly(float a, float b){
  aValue = a;
  bValue = b;
}

void SimplePoly::ADD(SimplePoly thing){
  aValue += thing.getAValue();
  bValue += thing.getBValue();
  
}

void SimplePoly::Scale(int n){
  aValue *= n;
	}

float SimplePoly::Read(int n){

  if (n == 1)
	return aValue;
  if (n == 2)
	return bValue;
  else
	return -1;
}

float SimplePoly::getAValue(){
  return aValue;
}

float SimplePoly::getBValue(){
  return bValue;
}

void SimplePoly::print(){
  cout << aValue << "*x + " << bValue;
}
