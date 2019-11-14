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
  map<string,pair<int,int> > mp; //0,1
  T(){
    mp.clear();
    int N;
    string s;
    int n;
    cin>>N;
    while (N--) {
      cin>>s;
      cin>>n;
      if(n == 0) mp[s].first++;
      else mp[s].second++;
    }

    int c = 0;
    FOR(i,mp){
      c += max(i->second.first, i->second.second);
    }
    cout<<c<<endl;
  }
  return 0;
}
