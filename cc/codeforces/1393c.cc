//#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef cc_hash_table<int, int, hash<int>> ht;
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
#define db(x) cout<<#x<<": "<<x<<endl
#define pb(a) push_back(a)

void iinternaut(){
    ///freopen("output.txt","w",stdout);
    ///freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main(){
  T(){
    int n;
    cin>>n;

    int freq[n+1]={0};
    int maxfreq = 0;
    REP(i,n+1) freq[i]=0;
    int x;
    REP(i,n) {
      cin>>x;
      freq[x]++;
      maxfreq = max(maxfreq,freq[x]);
    }
    int elements_with_same_freq=0;
    REP(i,n+1){
      if(maxfreq == freq[i]) elements_with_same_freq++;
    }
    int ans = (n - elements_with_same_freq) / (maxfreq - 1) -1;
    cout << ans << endl;
  }
}
// int32_t main(int argc, char const *argv[]){
//   // iinternaut();
//   T(){
//     ht mp;
//     int n,a;
//     cin>>n;
//     REP(i,n) {
//       cin>>a;
//       mp[a]++;
//     }
//     vector<int> v;
//     // v.pb({-1,0});
//     int count=0;
//     for(auto it: mp){
//       if(it.second == 1){
//         count++;
//       }
//       else{
//         v.pb(it.second);
//       }
//     }
//     v.pb(count);
//     sort(v.begin(),v.end());
//     // reverse(v.begin(),v.end());
//     if(v.size()==1) cout<<0<<endl;
//     else cout<<v[1]<<endl;
//   }
//   return 0;
// }
