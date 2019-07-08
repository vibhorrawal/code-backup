// C++ program to sort an array according to given indexes
#include<bits/stdc++.h>
using namespace std;
void reorder(int arr[], int index[], int n){
  for (size_t i = 0; i < n ; i++) {
    while (index[i] != i) {
      int oldIndex = index[index[i]];
      char oldArr = arr[index[i]];

      arr[index[i]] = arr[i];
      index[index[i]] = index[i];

      arr[i] = oldArr;
      index[i] = oldIndex;
    }
  }
}
int main(int argc, char const *argv[]){
    int arr[] = {50, 40, 70, 60, 90};
    int index[] = {3,  0,  4,  1,  2};
    int n = sizeof(arr)/sizeof(arr[0]);

    reorder(arr, index, n);

    cout << "Reordered array is: \n";
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";

    cout << "\nModified Index array is: \n";
    for (int i=0; i<n; i++)
        cout << index[i] << " ";
  return 0;
}
