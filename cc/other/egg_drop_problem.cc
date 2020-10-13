#include<iostream>
#include <climits>
using namespace std;

//recursive
int eggdrops(int n, int k);
//using Dynamic Programming

int dp(int n, int k);

//using dynamic + binary search
int binary(int n, int k);
//--------------------------------------------------------------
int main(int argc, char const *argv[]){
  int e; //no of eggs
  int f; // no of floors
  cin>>e>>f;
  cout<<"Max no of egg drops is "<<binary(e,f)<<endl;
  return 0;
}
//---------------------------------------------------------------
int eggdrops(int n, int k){
  if(n == 1) return k;
  if(k == 0) return 0;
  if(k == 1) return 1;

  int minimum = INT_MAX;

  for (int i = 1; i <= k; i++) {
    minimum = min(minimum, 1+max(eggdrops(n-1,i-1), eggdrops(n,k-i)));
  }
  return minimum;
}
int dp(int n, int k){
  int numdrops[n+1][k+1];
  for (int j = 0; j <= k; j++) {
    numdrops[1][j] = j;
    numdrops[0][j] = 0; // this line is not needed
  }
  for (int i = 0; i <= n; i++) {
    numdrops[i][0] = 0;
    numdrops[i][1] = 1;
  }
  int minimum;
  for (int i = 2; i <= n; i++) {
    for (int j = 2; j <= k; j++) {
      minimum = INT_MAX;
      for (int x = 1; x <= j; x++) {
        minimum = min(minimum, 1 + max(numdrops[i-1][x-1], numdrops[i][j-x]));
      }
      numdrops[i][j] = minimum;
    }
  }

    // cout<<"\nArray:\n";
    // //Prints numeggs
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=k;j++){
    //         cout<<numdrops[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }

  return numdrops[n][k];
}
long long nCr_binomial(int n, int r){
  // calc nCr_binomial using sigma( (n-i+1)/i )[i = 0 to k]
  long long answer = 0;
  long aux = 1;
  for (int i = 1; i <= n; i++) {
    aux = aux * ( r - i + 1 )/( (float) i );
    answer += aux;

    //needed here in this question
    // if(answer > k) break;
  }
  return answer;
}
int binary(int n, int k){
  int low = 0, high = k;
  int mid;

  while(1<high-low){
    mid = low + (high-low)/2;
    if(nCr_binomial(n,mid) < k)
      low = mid;
    else
    high = mid;
  }

  return 1+low;
}
