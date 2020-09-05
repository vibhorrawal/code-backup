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
  map< int,int> mp;
  T(){
    int n;
    cin>>n;
    int l[n],r[n],v[n];
    int count;
    for (int i = 0; i < n; i++) {
      cin>>l[i]>>r[i]>>v[i];
    }
    for (int i = 0; i < n; i++) {
      mp.clear();
      count = 0;
      mp[l[i]]++;
      mp[r[i]+1]--;
      for (int j = 0; j < n; j++) {
        if(i != j){
          if(v[i] == v[j]){
            mp[l[j]]++;
            mp[r[j]+1]--;
          }
        }
      }

      FOR(i,mp){
        count += i->second;
        // if(DEBUG){ cout << "count: "<<count; };
        if(count > 2){
          cout<<"NO"<<endl;
          goto end;
        }
        // if(DEBUG){ cout<<" db: "<<i->first<<" : "<<i->second<<endl; };
      }
    }

    cout<<"YES"<<endl;
    end:;
  }
  return 0;
}
