// A C++ program to move all zeroes at the end of array
#include<bits/stdc++.h>
using namespace std;
void pushZerosToEnd(int arr[], int n) {
  int count = 0;
  for (size_t i = 0; i < n; i++) {
    if(arr[i]){
      arr[count] = arr[i];
      count++;
    }
  }
  while (count < n)
    arr[count++] = 0;
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


