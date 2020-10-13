#include<iostream>
#include <algorithm>
using namespace std;
struct Activity{
  int start, finish; //start time and finish time
};

bool sortFinishTime(Activity a, Activity b){
  return a.finish < b.finish;
}
void printMaxActivity(Activity arr[], int n){
  sort(arr, arr + n, sortFinishTime);
  int end = arr[0].finish;
  cout<<0<<" ";
  for (int i = 1; i < n; i++) {
    if(arr[i].start > end){
      end = arr[i].finish;
      cout<<i<<' ';
    }
  }
}
int main(int argc, char const *argv[]){
  Activity act[] = {{1,2},{3,4},{0,6},{5,7},{8,9},{5,9}};
  int n = sizeof(act) / sizeof(act[0]);
  printMaxActivity(act, n);
  return 0;
}
