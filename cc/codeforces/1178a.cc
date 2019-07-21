#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define v1d  vector<int>
#define v2d  vector<vector<int> >
#define M 1000000007
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define endl "\n"
#define REP(i,n) for(auto i=0;i<(n);i++)
#define FOR(i,a) for(auto i=a.begin();i!=a.end();i++)
#define DEBUG false

int32_t main(int argc, char const *argv[]){
  ///freopen("output.txt","w",stdout);
  ///freopen("input.txt","r",stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin>>n;
  int arr[n];
  int seats = 0;
  REP(i,n){
    cin>>arr[i];
    seats += arr[i];
  }
  // if no need of coalition
  if(seats/2 < arr[0]){
    cout << 1<<endl<<1 << endl;
    return 0;
  }
  std::vector<int> v;
  int total = arr[0];
  for (int i = 1; i < n; i++) {
    if(arr[i] <= arr[0]/2){
      v.push_back(i);
      total += arr[i];
      if(DEBUG){cout<<"DE: "<<arr[i]<<endl;}
    }
  }
  // not possible
  if(total <= seats/2){
    cout<<0<<endl;
    return 0;
  }

  cout<<v.size()+1<<endl;

  cout<<1;
  FOR(i,v){
    cout<<' '<<*i + 1;
  }
  return 0;
}
