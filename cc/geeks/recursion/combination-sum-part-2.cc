#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi  vector<int>
#define vvi vector<vector<int>>
#define M 1e9+7
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define DEBUG 01
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[*] "<<#x<<" : "<<x<<endl;
#define fastIO ios_base::sync_with_stdio(false),cin.tie(NULL)

set<vi> res;
void comb(vi &v, int n, int sum, vi temp){
  if(sum < 0) return;
  if(sum == 0){
    sort(all(temp));
    res.insert(temp);
    return;
  }
  if(n<0) return;
  comb(v,n-1,sum,temp);
  temp.push_back(v[n]);
  comb(v,n-1,sum-v[n],temp);
}
void print_comb(vi &v, int n, int sum){
  res.clear();
  vi temp;
  comb(v,n-1,sum, temp);

  if(res.empty())
    cout << "Empty" << endl;
  else{
    for(auto r: res){
      cout<<"(";
      for(int i = 0; i < r.size()-1;i++)
        cout<<r[i]<<' ';
      cout<<r[r.size()-1]<<')';
    }
    cout << endl;
  }
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  T(){
    int n;
    cin >> n;
    vi v(n);
    REP(i,n) cin>>v[i];
    int sum;
    cin >> sum;
    print_comb(v,n,sum);
  }
  return 0;
}
