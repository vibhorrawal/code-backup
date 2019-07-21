// quick sort implemented for arrays
#include<bits/stdc++.h>
using namespace std;

void qsort_hoares(int arr[], int low, int high);
void qsort_lomuto(int arr[], int low, int high);
int partition_lomuto(int arr[], int low, int high);
int partition_hoares(int arr[], int low, int high);
////////////////////////////////////////////////////////////////////
int main(int argc, char const *argv[]){
  int arr[] = {0,2,1,4,5,-3,8,0};
  int n = sizeof(arr) / sizeof(arr[0]);
  qsort_hoares(arr, 0, n-1);
  for (size_t i = 0; i < n ; i++) {
    cout<<arr[i]<<' ';
  } cout<<endl;
  return 0;
}
/////////////////////////////////////////////////////////////////
void qsort_hoares(int arr[], int low, int high){
  if(low < high)
  {
    int pivot = partition_hoares(arr,low,high);
    qsort_hoares(arr,low,pivot);
    qsort_hoares(arr,pivot+1,high);
  }
}
void qsort_lomuto(int arr[], int low, int high){
  if(low < high)
  {
    int pivot = partition_lomuto(arr,low,high);
    qsort_lomuto(arr,low,pivot-1);
    qsort_lomuto(arr,pivot+1,high);
  }
}

//lomuto
int partition_lomuto(int arr[], int low, int high){
  int pivot = arr[high]; // highest element taken as pivot
  int k = low - 1;
  for (size_t i = low; i < high; i++) {
    if(arr[i] < pivot)
      swap(arr[i],arr[++k]);
  }
  swap(arr[++k],arr[high]);
  return k;
}

//hoares
int partition_hoares(int arr[], int low, int high){
  int pivot = arr[low];
  int i = low-1;
  int j = high+1;
  while (true) {
    while(arr[++i] < pivot);
    while(arr[--j] > pivot);

    if(i >= j) return j;

    swap(arr[i], arr[j]);

  }
}
