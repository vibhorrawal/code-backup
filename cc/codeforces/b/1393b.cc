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
#define DEBUG 0
#define pb(a) push_back(a)

void iinternaut(){
    ///freopen("output.txt","w",stdout);
    ///freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main() {
  int n;
  cin>>n;
  int cnt[100000]={0};
  int x,sum2=0,sum4=0;
  REP(i,n){
    cin>>x;
    sum2 -= cnt[x]/2;
    sum4 -= cnt[x]/4;
    cnt[x]++;
    sum2 += cnt[x]/2;
    sum4 += cnt[x]/4;
  }

  int q;
  cin>>q;
  char c;
  REP(i,q){
    cin>>c;
    cin>>x;
    sum2 -= cnt[x]/2;
    sum4 -= cnt[x]/4;
    if(c=='+') cnt[x]++;
    else cnt[x]--;
    sum2 += cnt[x]/2;
    sum4 += cnt[x]/4;

    if(sum2 >= 4 && sum4 >=1) cout << "YES" << endl;
    else cout << "NO" << endl;
  }

}

// int32_t main(int argc, char const *argv[]){
//   // iinternaut();
//   int n;
//   cin>>n;
//   ht mp;
//   REP(i,n) {
//     int a;
//     cin>>a;
//     mp[a]++;
//   }
//   T(){
//     char c;
//     int q;
//     cin>>c;
//     cin>>q;
//     if(c=='+'){
//       mp[q]++;
//     }
//     else mp[q]--;
//     bool four=0,two1=0,two2=0;
//
//     for(auto it: mp){
//
//       if(DEBUG){ cout << " f: "<<it.first <<" val: "<<it.second; };
//
//       if(four && two1 && two2) break;
//       if(it.second >= 8) four = two1 = two2 = true;
//       else if(!four && it.second >= 6){
//         four = true;
//         if(!two1) two1 = true;
//         else /*if(val1 != it.first)*/ two2 = true;
//       }
//       else if(!four && it.second >= 4) four = true;
//       else if(four && it.second >= 4) two1 = two2 = true;
//       else if(!two1 && it.second >= 2) two1 = true;
//       else if(two1 && it.second >= 2) two2 = true;
//     }
//     if(four && two1 && two2) cout<<"YES\n";
//     else cout<<"NO\n";
//   }
//   return 0;
// }
