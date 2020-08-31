/*

In the end, it is impossible not to become what others believe you are.

*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int     long long int
#define ull     unsigned int
#define ld      long double
#define pb      push_back
#define pa      pair<int,int>
#define v1d     vector<int>
#define v2d     vector<vector<int> >
#define vpa     vector<pair<int,int>>
#define M       1000000007
#define MN      LLONG_MIN
#define MX      LLONG_MAX
#define ff      first
#define ss      second
#define endl    "\n"
#define v1s     vector<string>
#define all(v)  v.begin(),v.end()
#define S(v)    sort(v.begin(),v.end())
#define RS(v)   sort(v.rbegin(),v.rend())
#define R(v)    reverse(v.begin(),v.end())
#define mxpq(T)    priority_queue <T>
#define mnpq(T)    priority_queue<T,vector<T>,greater<T>>
#define T       int tc;cin>>tc;while(tc--)
#define p2d(v)     for(auto a:v){for(auto b:a)cout<<b<<" ";cout<<endl;}
#define p1d(v)      for(auto a:v)cout<<a<<" ";cout<<endl;
#define ppd(v)      for(auto a:v)cout<<a.ff<<" "<<a.ss<<endl;
#define sz(v)       (int)(v.size())
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> oset;
#define N 400005

void solve(){
    int n,a,b,c;cin>>n>>a>>b>>c;
    if(a==b&&b==c&&a==1&&n!=1){cout<<"IMPOSSIBLE\n";return;}
    // if(a+b-c>n){cout<<"IMPOSSIBLE\n";return;}
    int left=n-a-b+c;
    vector<int>ans;
    for(int i=0;i<c;i++)ans.pb(n);
    for(int i=0;i<a-c;i++){
        ans.insert(ans.begin(),n-i-1);
    }
    for(int i=0;i<b-c;i++)ans.pb(n-i-1);
        int flag=1;
    // p1d(ans)
    if(ans.size()>n){cout<<"IMPOSSIBLE\n";return;}
    for(int i=0;i<ans.size();i++){
        if(ans[i]==n&&i!=0&&ans[i-1]!=n){
            int k=n-ans.size();
            while(k--)
            ans.insert(ans.begin()+i,1);
            break;
        }
        if(i>0&&ans[i-1]==n&&ans[i]!=n){
            int k=n-ans.size();
            while(k--)
            ans.insert(ans.begin()+i,1);
            break;
        }
    }
    for(int i=0;i<ans.size();i++){
        if(ans[i]==n&&i>0&&ans[i-1]==n){
            int k=n-ans.size();
            while(k--)
            ans.insert(ans.begin()+i,1);
            break;
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;




}
void Weapons19(){
    int t;cin>>t;
    for(int i=0;i<t;i++){
        cout<<"Case #"<<i+1<<": ";
        solve();
    }


}

int32_t main(){

    /*
    त्यक्तवाधर्मं च लोभं च
    मोहंचो द्यमास्थिता।
    युद्ध्यध्वमनहंकारा
    यतो धर्मस्ततो जयः।।
    */

    cout<<fixed<<setprecision(16);
    cin.sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    // #ifndef ONLINE_JUDGE
    //  freopen("input.txt",  "r",  stdin);
    //  freopen("output.txt", "w", stdout);
    // #endif

    Weapons19();

}
