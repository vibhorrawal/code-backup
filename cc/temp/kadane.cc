// Kadane's Algorithm to find the maximum sum subarray
#include<bits/stdc++.h>
using namespace std;

void kadane(int arr[], int n){
  int max_sub,global_max;
  max_sub = global_max = arr[0];

  for (size_t i = 0; i < n ; i++) {
    max_sub = max(arr[i], max_sub + arr[i]); // max untill current subarray or current element
    global_max = max(global_max, max_sub);
  }
  cout<<global_max<<endl;
  return;
}
void printIndKadane(int arr[], int n){
  int max_sub,global_max;
  max_sub = global_max = arr[0];
  int index[2] = {0,0};
  int lower;
  for (size_t i = 0; i < n ; i++) {
    if(arr[i] > 0){
      max_sub = max_sub + arr[i];
      // index[1] = i;
    }
    else{
      max_sub = 0;
      lower = i+1;
    }

    if(max_sub > global_max){
      global_max = max_sub;
      index[1] = i;
      index[0] = lower;
    }
  }
  cout<<global_max<<endl;
  cout << "(i,j) : (" <<index[0]<<", "<<index[1]<<")"<< endl;
  return;
}
int main(int argc, char const *argv[]){
  int arr[] = {2,-3,2,1,-1,5,-7,1,2,3,-8};
  int n = sizeof(arr) / sizeof(arr[0]);
  kadane(arr,n);
  printIndKadane(arr,n);
  return 0;
}
