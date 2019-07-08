/*  C++ program to rearrange positive and negative integers in alternate
    fashion while keeping the order of positive and negative numbers. */
#include<bits/stdc++.h>
using namespace std;
void swap(int arr[] , int i, int pos){
  if(pos == -1)
    return;
  int temp = arr[i];
  arr[i] = arr[pos];
  arr[pos] = temp;
  return;
}
int findnext(int arr[], int n, int i){
  // check if we need pos or negative
  if(arr[i] > 0)
    while(arr[i] > 0 && i < n)
      i++;

  else
  while(arr[i] < 0 && i < n)
    i++;

  if(i > n)
      return -1;
  return i;
}
void rearrange(int arr[], int n) {
  // int* new_arr = new int[n];
  list <int> pos;
  list <int> neg;

for (size_t i = 0; i < n ; i++) {
  if(arr[i] >= 0)
    pos.push_back(arr[i]);
  else
    neg.push_back(arr[i]);
  }
  for (size_t i = 0; i < n ; i++) {
    if(i % 2){
      if(!pos.empty()){
        arr[i] = pos.front();
        pos.pop_front();
      }
      else{
        arr[i] = neg.front();
        neg.pop_front();
      }
    }
    else{
      if(!neg.empty()){
        arr[i] = neg.front();
        neg.pop_front();
      }
      else{
        arr[i] = pos.front();
        pos.pop_front();
      }
    }
  }
  return;
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
      cout << arr[i] << " ";
    cout << endl;
}
int main(int argc, char const *argv[]){
    // int i;
      int arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
      int n = sizeof(arr)/sizeof(arr[0]);

      cout << "Given array is \n";
      printArray(arr, n);

      rearrange(arr, n);

      cout << "Rearranged array is \n";
      printArray(arr, n);
  return 0;
}
