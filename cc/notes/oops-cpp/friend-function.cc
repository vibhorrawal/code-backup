#include <iostream>
using namespace std;

class beta;
class alpha{
private:
  int data;
public:
  alpha() : data(3) { }
  friend int frifunc(alpha, beta); //friend function
};

class beta {
private:
  int data;
public:
  beta() : data(7) { }
  friend int frifunc(alpha, beta); //friend function
};
int frifunc(alpha a, beta b) {
  return( a.data + b.data );
}

////////////////////////////////////////////////////////////////
class Distance {
private:
  int feet;
  float inches;
public:
  Distance(int ft, float in) { feet = ft; inches = in; }
  friend Distance operator + (Distance, Distance);
};

Distance operator + (Distance d1, Distance d2) { //add d1 to d2
  int f = d1.feet + d2.feet;
  float i = d1.inches + d2.inches;
  if(i >= 12.0)  { i -= 12.0; f++; }
  return Distance(f,i);
}

////////////////////////////////////////////////////////////////
class alpha2 {
private:
  int data1;
public:
  alpha2() : data1(99) { }
  friend class beta2; //beta2 is a friend class
};
class beta2 {
public:
  // all member functions can access private alpha data
  void func1(alpha2 a) { cout << "\ndata1=" << a.data1; }
  void func2(alpha2 a) { cout << "\ndata1=" << a.data1; }
};
