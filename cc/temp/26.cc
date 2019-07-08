// move all zero to end
#include<bits/stdc++.h>
using namespace std;
void pushZerosToEnd(int arr[], int n){
  int count = 0;
  int i = 0, j = 0;
  while(i < n){
    if(arr[i] == 0)
      count++;
    else
     arr[j++] = arr[i];

    i = i + 1;
  }
  // i--;
  while(count--){
    arr[--i] = 0;
  }
}
int main(int argc, char const *argv[]){
  int arr[] = {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9};
  int n = sizeof(arr) / sizeof(arr[0]);
  pushZerosToEnd(arr, n);
  cout << "Array after pushing all zeros to end of array :\n";
  for (int i = 0; i < n; i++)
      cout << arr[i] << " ";
  return 0;
}
