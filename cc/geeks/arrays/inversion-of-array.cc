#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define FOR(i,a) for(auto i=a.begin();i!=a.end();i++)
#define DEBUG true
#define pb(a) push_back(a)
#define mp(i,j) make_pair(i,j)

int merge(int a[], int low, int mid, int high){
  int i,j,k, inv_count=0;
  int temp[high-low+1];
  i = low;
  j=mid;
  k = 0;
  while(i<=mid-1 && j <= high){
    if(a[i] <= a[j]) temp[k++] = a[i++];
    else{
      temp[k++] = a[j++];
      inv_count += (mid - i);
    }
  }
  while(i<=mid-1) temp[k++] = a[i++];
  while(j<=high) temp[k++] = a[j++];
  k=0;
  for (int i = low; i <= high; i++) {
    a[i] = temp[k++];
  }
  return inv_count;
}
int mergesort(int a[], int low, int high){
  int mid, inv_count = 0;
  if(low<high){
    mid = (low + high) / 2;
    inv_count += mergesort(a,low,mid);
    inv_count += mergesort(a,mid+1,high);
    inv_count += merge(a,low,mid,high);
  }
  return inv_count;
}
int32_t main(int32_t argc, char const *argv[]){
T(){
  int n;cin>>n;
  int a[n];
  REP(i,n) cin>>a[i];
  cout<<mergesort(a,0,n-1)<<endl;
  }
  return 0;
}
