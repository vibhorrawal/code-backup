#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define v1d  vector<int>
#define v2d  vector<vector<int> >
#define M 1000000007
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define endl '\n'
#define REP(i,n) for(auto i=0;i<(n);i++)
#define FOR(i,a) for(auto i=a.begin();i!=a.end();i++)
#define DEBUG true
void iinternaut(){
    ///freopen("output.txt","w",stdout);
    ///freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int32_t main(int argc, char const *argv[]){
  iinternaut();
  v1d arr;

  T(){
    int n,k;
    cin>>n>>k;
    int sum = 0;
    int temp;
    for (int i = 0; i < n; i++) {
      cin>>temp;
      if(temp <= k) sum += temp;
      else arr.push_back(temp);
    }

    if(DEBUG){ cout<<"array: "; for(auto i = arr.begin(); i != arr.end() ; i++){ cout<<*i<<' ';}cout<<endl; };
    sort(arr.begin(), arr.end());

    for(int i = 0; i < arr.size()-1; i++){
      int temp = arr[i] - k;
      if(DEBUG){ cout<<"temp: "<<temp<<endl; };
      arr[i] = k;

      if(DEBUG){ cout<<"*i: "<<arr[i]<<endl; };
      arr[(i+1)] -= temp;

      if(DEBUG){ cout<<"arr[(i+1)]: "<<arr[(i+1)]<<endl;  };
    }

    int ans = 0;
    FOR(i,arr) ans += *i;

    cout<<ans+sum<<endl;

    arr.clear();
  }
  return 0;
}
