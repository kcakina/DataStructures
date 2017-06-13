#ifndef SIMPLEPOLY_H
#define SIMPLEPOLY_H

class SimplePoly {

 public:
  explicit SimplePoly(float a, float b);
  void ADD(SimplePoly thing);
  void Scale(int n);
  float Read(int n);
  void print();
  float getAValue();
  float getBValue();
  void main();
  
 private:
  float aValue;
  float bValue;
};

#endif
