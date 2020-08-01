#include<iostream>
using namespace std;

int main(int argc, char const *argv[]){
  char r, c = '@';
  int count = 0;
  while(!cin.eof()){
    cin>>r;
    if(r==c) count++;
  }
  cout<< count<<endl;
  return 0;
}
