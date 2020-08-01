#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define FOR(i,a) for(auto i=a.begin();i!=a.end();i++)
#define DEBUG true
#define pb(a) push_back(a)

void swap(int &a, int &b){
  int temp = a;
  a = b;
  b = temp;
}
void merge(int arr1[], int arr2[], int x, int y){
  int i=0,j=0;
  while (i<x && j<y) {
    if(arr1[i] <= arr2[j]){
      i++;
    }
    else{
      swap(arr1[i],arr2[j]);
      i++; 
    }
  }

  REP(k,x) cout<<arr1[k]<<' ';
  REP(k,y) cout<<arr2[k]<<' ';
  cout<<endl;
}
int main(int argc, char const *argv[]){
  T(){
    int x,y;
    cin>>x>>y;
    int arr1[x],arr2[y];
    REP(i,x) cin>> arr1[i];
    REP(i,y) cin>> arr2[i];
    merge(arr1,arr2,x,y);
  }
  return 0;
}
