// minimum-swaps-required-bring-elements-less-equal-k-together
#include<bits/stdc++.h>
using namespace std;

int minSwap(int arr[], int n, int k){
  int count_less_than_k = 0;
  for (size_t i = 0; i < n ; i++) {
    if(arr[i] <= k) count_less_than_k++;
  }
  // int i = 0, j = count_less_than_k;
  // int ans = INT_MAX;
  int bad = 0;
  // while(j < n){
  //   bad = 0;
  //   for (size_t l = i; l < j; l++) {
  //     if(arr[l] > k) bad++;
  //   }
  //   if(bad < min) min = bad;
  //   i++;j++;
  // }
  for (size_t i = 0; i < count_less_than_k; i++) {
    if(arr[i] > k) bad++;
  }
  int ans = bad;
  for (size_t i = 0, j = count_less_than_k; j < n; i++, j++) {
    if(arr[i] > k) bad--;
    if(arr[j] > k) bad++;

    ans = min(bad, ans);
  }
  return ans;
}
int main(int argc, char const *argv[]){
  int arr[] = {2, 1, 5, 6, 3};
int n = sizeof(arr) / sizeof(arr[0]);
int k = 3;
cout << minSwap(arr, n, k) << "\n";

int arr1[] = {2, 7, 9, 5, 8, 7, 4};
n = sizeof(arr1) / sizeof(arr1[0]);
k = 5;
cout << minSwap(arr1, n, k);
return 0;
  return 0;
}
