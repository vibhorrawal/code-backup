// palindromes of size 9 are printed a-z
#include<iostream>
#include<algorithm>
using namespace std;

int arr[5] = {0};
void print_array(int arr[]);
void increment_arr();

int main(int argc, char const *argv[]){
  int a[5];
  while(1){
    increment_arr();
    if(arr[0] == 26)
      break;
    for (int i = 0; i < 5; i++) a[i] = arr[i];

    do{
      print_array(a);
    } while(next_permutation(a,a+5));
  }
  return 0;
}

void increment_arr(){
  arr[4]++;
  for (int i = 4; i > 0; i--) {
    if(arr[i] == 26){
      arr[i-1]++;
      arr[i]--;
    }
  }
}

void print_array(int arr[]){
  for (int i = 0; i < 5; i++) {
    cout<<char(arr[i] + 'a');
  }
  for (int i = 3; i >= 0; i--) {
    cout<<char(arr[i] + 'a');
  }
  cout<<endl;
}
