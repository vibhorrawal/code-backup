#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi  vector<int>
#define vvi vector<vector<int>>
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define sz(x) (int) x.size()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define DEBUG 01
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[*] "<<#x<<" : "<<x<<endl;
#define fastIO ios_base::sync_with_stdio(false),cin.tie(NULL)

string to_string(deque<int> &dq){
  string res;
  for(int i : dq) {
    res += i;
    res += ",";
  }
  return res;
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  int n,k1,k2,t;
  deque<int> q1,q2;
  cin>>n>>k1;
  REP(i,k1) {
    cin>>t;
    q1.push_back(t);
  }
  cin>>k2;
  REP(i,k2){
    cin>>t;
    q2.push_back(t);
  }
  deque<int> dq1(all(q1)), dq2(all(q2));
  ll count = 0;
  unordered_set<string> s1,s2;
  while(dq1.size() && dq2.size()){
    int d1 = dq1.front(); dq1.pop_front();
    int d2 = dq2.front(); dq2.pop_front();
    if(d1 > d2){
      dq1.push_back(d2);
      dq1.push_back(d1);
    }
    else{
      dq2.push_back(d1);
      dq2.push_back(d2);
    }
    count++;
    // cout<<"\ndq1: ";
    // for(int i : dq1) cout<<i<<' ';
    // cout<<"\ndq2: ";
    // for(int i : dq2) cout<<i<<' ';
    if(s1.count(to_string(dq1)) && s2.count(to_string(dq2))) {
      cout << "-1" << endl;
      exit(0);
    }
    s1.insert(to_string(dq1));
    s2.insert(to_string(dq2));
  }
  cout << count << ' ' << (dq1.size() ? '1' : '2') << endl;
  return 0;
}
