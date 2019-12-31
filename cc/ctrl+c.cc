// not working
#include<iostream>
using namespace std;

int main(int argc, char const *argv[]){
  int i = 0;
  while (1) {
    cout << "message" << endl;
    i++;
    if(i%10==0) system("echo \032");
  }
  return 0;
}
