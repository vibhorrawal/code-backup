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

int exponentialSearch(int arr[], int n, int key){
  if(arr[0] == key) return 0;

  int i = 1;
  while(arr[i] < key)
    i = i * 2;

  return binarySearch(arr,i/2,min(i,n),key) ;
}
// Driver code
int main(void)
{
   int arr[] = {2, 3, 4, 10, 40};
   int n = sizeof(arr)/ sizeof(arr[0]);
   int x = 10;
   int result = exponentialSearch(arr, n, x);
   (result == -1)? printf("Element is not present in array")
                 : printf("Element is present at index %d",
                                                    result);
   return 0;
}
