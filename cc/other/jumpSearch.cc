#include<iostream>
#include<cmath>
using namespace std;

int jumpSearch(int arr[], int key, int n){
  int step = sqrt(key); // optimal block size
  int block = 0;
  while(arr[block] < key){
    block += step;
    if(block >= n)
      break;
  }
  for (size_t i = (block - step); i < block; i++) {
    if(arr[i] == key)
      return i;
  }
  return -1;
}
// Driver program to test function
int main()
{
    int arr[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21,
                34, 55, 89, 144, 233, 377, 610 };
    int x = 55;
    int n = sizeof(arr) / sizeof(arr[0]);

    // Find the index of 'x' using Jump Search
    int index = jumpSearch(arr, x, n);

    // Print the index where 'x' is located
    cout << "\nNumber " << x << " is at index " << index;
    return 0;
}
