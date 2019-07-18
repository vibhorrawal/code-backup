#include<iostream>
using namespace std;
int binarySearch(int arr[],int low, int high, int key){
  if(low >= high) return -1;

  int mid = (low + high) / 2;
  if(arr[mid] == key) return mid;

  if(arr[mid] > key)
   return binarySearch(arr, low, mid - 1, key);
   else
    return binarySearch(arr, mid + 1, high, key);
}
int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 101;
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1) ? printf("Element is not present in array\n")
                   : printf("Element is present at index %d\n",
                            result);
    return 0;
}
