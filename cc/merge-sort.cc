#include<iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high){
  int n1 = mid - low + 1, n2 = high - mid;
  int L[n1];
  int R[n2];

  for(int k = low; k < n1; k++)
    L[k] = arr[low+k];

  for(int k = mid; k < n2; k++)
    R[k] = arr[mid+1+k];

  int i = 0, j = 0, k = low;
  while((i < n1) && (j < n2)){
    if(L[i] > R[j])
      arr[k++] = R[j++];
    else
      arr[k++] = L[i++];
  }

  while (i < n1)
    arr[k++] = L[i++];
  while (j < n2)
    arr[k++] = R[j++];
}

void  mergeSort(int arr[], int low, int high) {
  if(low >= high) return;

  int mid = (low + high)/2;
  mergeSort(arr, low, mid);
  mergeSort(arr, mid+1, high);

  merge(arr, low, mid, high);
}
// Driver program to test above functions
int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Unsorted array: \n";
    for(size_t i = 0; i < n ; i++){ cout<<arr[i]<<' ';}cout<<endl;

    mergeSort(arr, 0, n-1);
    cout << "Sorted array: \n";
    for(size_t i = 0; i < n ; i++){ cout<<arr[i]<<' ';}cout<<endl;
    return 0;
}
