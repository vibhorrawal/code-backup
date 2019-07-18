// box stacking problem using dynamic programming
#include<bits/stdc++.h>
using namespace std;
const bool DEBUG = true;
struct box {
  int l,b,h;
};
int compare(const void* a, const void* b){
  return ((*(box*)b).b * (*(box*)b).l) - ((*(box*)a).b * (*(box*)a).l);
}
int maxStackHeight(box arr[], int n){
  box allRotations[3*n];
  int index = 0;
  for (size_t i = 0; i < n ; i++) {
    // length is taken more than base
    //copying the original
    allRotations[index].l = max(arr[i].b, arr[i].l);
    allRotations[index].b = min(arr[i].b, arr[i].l);
    allRotations[index].h = arr[i].h;
    index++;

    // first rotation
    allRotations[index].l = max(arr[i].h, arr[i].l);
    allRotations[index].b = min(arr[i].h, arr[i].l);
    allRotations[index].h = arr[i].b;
    index++;

    // second rotation
    allRotations[index].l = max(arr[i].b, arr[i].h);
    allRotations[index].b = min(arr[i].b, arr[i].h);
    allRotations[index].h = arr[i].l;
    index++;

  }
  int N = 3 * n;
  if(DEBUG){ cout<<"N: "<<N<<endl; };
  // now we need to sort
  qsort(allRotations,N,sizeof(box),compare);

  if(DEBUG){for(int i = 0; i < N; i++ ) printf("%d x %d x %d\n", allRotations[i].h, allRotations[i].b, allRotations[i].l); };

  int result[N];
  for (size_t i = 0; i < N ; i++) {
    result[i] = allRotations[i].h;
  }

  for (size_t i = 1; i < N ; i++) {
    for (size_t j = 0; j < i ; j++) {
      if((allRotations[i].b < allRotations[j].b) && (allRotations[i].l < allRotations[j].l))
        result[i] = max(result[i], result[j] + allRotations[i].h/*result[i]*/);
    }
  }
  int max_ans = -1;
  for (size_t i = 0; i < N ; i++) {
    max_ans = max(max_ans, result[i]);
  }
  return max_ans;
}
int main(int argc, char const *argv[]){
  box arr[] = { {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} };
   int n = sizeof(arr)/sizeof(arr[0]);

   printf("The maximum possible height of stack is %d\n",
   maxStackHeight (arr, n) );
  return 0;
}
