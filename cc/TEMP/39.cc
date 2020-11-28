// currently isnt working
// quick sort implemented for arrays
#include<bits/stdc++.h>
using namespace std;

const bool DEBUG = true;
int n;
void qsort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
////////////////////////////////////////////////////////////////////
int main(int argc, char const *argv[]){
  int arr[] = {0,1,2};
   n = sizeof(arr) / sizeof(arr[0]);

  qsort(arr, 0, n-1);
  for (size_t i = 0; i < n ; i++) {
    cout<<arr[i]<<' ';
  }
  return 0;
}
/////////////////////////////////////////////////////////////////
int partition(int arr[], int low, int high){

  int pivot = arr[low]; // lowest element taken as pivot
  int i = low+1;
  int j = high;
  if(DEBUG) for(size_t k = 0; k < n ; k++){ cout<<arr[k]<<' ';}cout<<endl;

  while (i < j) {
    while (arr[++i] < pivot && i<j);
    while (arr[--j] > pivot && j>i);
    if(DEBUG) cout << "swapping " <<i <<" with " <<j<<endl;
    swap(arr[i], arr[j]);
    if(DEBUG) for(size_t k = 0; k < n ; k++){ cout<<arr[k]<<' ';}cout<<endl;
  }
  i=i-1;
  if(DEBUG) cout << "end swapping "<< low << " with " << i << endl;
  swap(arr[i], arr[low]);

  if(DEBUG) for(size_t k = 0; k < n ; k++){ cout<<arr[k]<<' ';}cout<<endl;
  if(DEBUG) cout << "returning: " <<i<< endl;
  return i;
}
void qsort(int arr[], int low, int high){
  if(low < high)
  {
    int pivot = partition(arr,low,high);
    qsort(arr,low,pivot-1);
    qsort(arr,pivot+1,high);
  }
}
