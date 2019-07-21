#include<iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
  int largest = i;
  int leftchild = i * 2 + 1;
  int rightchild = i * 2 + 2;

  // if leftchild if greater
  if(leftchild < n && arr[leftchild] > arr[largest])
    largest = leftchild;
  // if rightchild is greater
  if(rightchild < n && arr[rightchild] > arr[largest])
    largest = rightchild;

  if(largest != i){
    swap(arr[largest], arr[i]);
    heapify(arr,n,largest);
  }
}

void heapSort(int arr[], int n ) {
  for (int i = n/2 - 1; i >= 0; i--) {
    heapify(arr, n, i);
  }

  for (int i = n-1; i >= 0; i--) {
    swap(arr[0], arr[i]);
    heapify(arr, i, 0);
  }
}
// Driver program to test above functions
int main()
{
    int arr[] = {12, 7, 13, 5, 6, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Unsorted array: \n";
    for(size_t i = 0; i < n ; i++){ cout<<arr[i]<<' ';}cout<<endl;

    heapSort(arr, n);
    cout << "Sorted array: \n";
    for(size_t i = 0; i < n ; i++){ cout<<arr[i]<<' ';}cout<<endl;
    return 0;
}
