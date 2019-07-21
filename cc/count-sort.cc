#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

void countSort(vector<int> &arr){
  int max = *max_element(arr.begin(), arr.end());
  int min = *min_element(arr.begin(), arr.end());
  int range = max - min + 1;

  std::vector<int > count(range), output(arr.size());
  for (int i = 0; i < arr.size(); i++) {
    count[arr[i] - min]++;
  }

  for (int i = 1; i < count.size(); i++) {
    count[i] += count[i-1];
  }

  for (int i = arr.size()-1; i >= 0; i--) {
    output[count[(arr[i] - min)] - 1] = arr[i];
    count[arr[i] - min]--;
  }

  for (int i = 0; i < arr.size(); i++) {
    arr[i] = output[i];
  }
}
void printArray(vector <int> & arr)
{
    for (int i=0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << "\n";
}
int main(int argc, char const *argv[]){
  std::vector<int> arr = {0,-3,-3,1,5,7,0,9,6,5};
  printArray(arr);
  countSort (arr);
  cout<<"Sorted Array:\n";
  printArray (arr);
  return 0;
}
