#include<iostream>
using namespace std;

int x = 2;

int &fun(){
  return x;
}

void display(int &xi){
  cout << xi << endl;
}
int main(){
  display(x);
  fun() = 5;
  display(x);
}
