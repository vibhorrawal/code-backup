#include<iostream>
using namespace std;
int ternarySearch(int arr[], int low, int high, int key){
  while(low <= high){
    int mid1 = low + (high - low) / 3;
    int mid2 = mid1 + (high - low) / 3;

    if(arr[mid1] == key) return mid1;
    if(arr[mid2] == key) return mid2;

    if(arr[mid1] > key) return ternarySearch(arr, low, mid1-1, key);
    if(arr[mid2] < key) return ternarySearch(arr, mid2 + 1, high, key);
  }
  return -1;
}
int main(int argc, char const *argv[]){
  int arr[] = {2, 3, 4, 10, 40};
  int n = sizeof(arr)/ sizeof(arr[0]);
  int x = 101;
  int result = ternarySearch(arr,0, n-1, x);
  (result == -1)? printf("Element is not present in array")
                : printf("Element is present at index %d",
                                                   result);
  return 0;
}
