#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define v1d  vector<int>
#define v2d  vector<vector<int> >
#define M 1000000007
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define FOR(i,a) for(auto i=a.begin();i!=a.end();i++)
#define DEBUG 0
#define pb(a) push_back(a)

int main(int argc, char const *argv[]){
  T(){
    int n,x;
    cin>>n>>x;
    int k;
    v1d arr;
    REP(i,n){
      cin>>k;
      arr.pb(k);
    }
    sort(all(arr));

    if(DEBUG){ cout<<"array: "; for(int i = 0; i < n ; i++){ cout<<arr[i]<<' ';}cout<<endl; };

    auto it = lower_bound(all(arr), x);
    int count = n  - (it - arr.begin());

    if(DEBUG){ cout << count << endl; };

    if(count == 0){
      cout<<0<<endl;
      continue;
    }
    long long  sum = 0;
    for (int i = n - count; i < n ; i++) {
      sum += arr[i];

      if(DEBUG){ cout << "sum " <<sum<< endl; };
    }

    if(DEBUG){  cout<<"val: "<<sum / count<<endl; };

    for (int i = n - count - 1; i >= 0; i--) {
      // cout<<arr[i];
      sum += arr[i];
      long long val = sum / (count + 1);
      if(val >= x){
        count++;
      }
      else{
        break;
      }
    }
    cout<<count<<endl;
  }
  return 0;
}
