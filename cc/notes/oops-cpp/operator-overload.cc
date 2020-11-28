#include<iostream>
using namespace std;

class Counter {
public:
  int count;
  Counter() : count(0) { }
  Counter(int c) : count(c) { }
  void show() { cout << count << endl; }
  Counter operator ++(); // prefix
  Counter operator ++(int); // postfix
};

Counter Counter::operator ++(){
  cout << "prefix called" << endl;
  return Counter(++count);
}

Counter Counter::operator ++(int){
  cout << "postfix called" << endl;
  return Counter(count++);
}

class Distance {
public:
  int dis;
  Distance() : dis(0) {}
  Distance(int d) : dis(d) { }
  Distance(Counter c) : dis(c.count) { } // type conversion (implicit)
  Distance operator+(const Distance b) const { // binary + overloading
    int temp_d = dis + b.dis;
    return Distance(temp_d);
  }
};

class Lol {
public:
  int var;
  Lol(int a) : var(a) { }
  
  // if explicit is also added before operator then only constructor can use this conversion
  operator Counter(){ // conversion operator
    return Counter(var);
  }
};

int main(){
  Counter cc;
  ++cc;
  cc.show();
  Counter c2 = cc++;
  c2.show();

  Distance a = 3;
  Distance b(a);
  Distance c = a + b;
  cout << c.dis << endl;

  a = cc;
  cout << a.dis << endl;

  Lol obj(20);
  cc = obj; // type casted like: cc = (Counter) obj OR static_cast<Counter>(obj)
  cc.show();
}
