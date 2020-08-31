#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define v1d  vector<int>
#define v2d  vector<vector<int> >
#define M 1e9+7
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define FOR(i,a) for(auto i=a.begin();i!=a.end();i++)
#define DEBUG 01
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[ "<<#x<<" : "<<x<<" ]"<<endl;
#define endl '\n'

void clr(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int sqrt(int x)
{
    if (x == 0 || x == 1)
       return x;

    int start = 1, end = x, ans;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (mid*mid == x)
            return mid; 
        if (mid*mid < x)
        {
            start = mid + 1;
            ans = mid;
        }
        else // If mid*mid is greater than x
            end = mid-1;
    }
    return ans;
}
int32_t main(int argc, char const *argv[]){
  clr();
  int n;
  while(1){
    cin>>n;
    if(!n) break;
    ll s = sqrt(n);
    if(s*s == n) cout<<"yes"<<endl;
    else cout << "no" << endl;
  }
  return 0;
}
