#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define sz(x) (int) x.size()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define pb emplace_back
#define fastIO ios_base::sync_with_stdio(false),cin.tie(NULL)
template<class T> void read(T& x) { cin >> x; }
template<class A> void read(vector<A>& a) { for(auto& x: a) read(x); }
template<class T>string to_string(const vector<T> &v) {
  string res; REP(i,sz(v)) res += to_string(v[i]) + " "; res.pop_back(); return res; }
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
  cerr << to_string(h); if(sizeof...(t)) cerr << ", "; DBG(t...); }
#define db(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)

string findSum(string str1, string str2)
{
    if (str1.length() > str2.length())
        swap(str1, str2);
    string str = "";
    int n1 = str1.length(), n2 = str2.length();
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    int carry = 0;
    for (int i=0; i<n1; i++)
    {
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
    for (int i=n1; i<n2; i++)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
    if (carry)
        str.push_back(carry+'0');
    reverse(str.begin(), str.end());
    return str;
}
const int M = 1e9 + 7;
long long Solve(long long n){
  string res = "0";
  for (int i = 1; i <= n; i++) {
    string str = bitset<64>(i).to_string();
    res = findSum(res, str);
    res = to_string(stoll(res) % M);
  }
  return stoll(res);
}


/////
int scs(string a, string b){
  map<char,int> fa, fb;
  for(char c : a) fa[c]++;
  for(char c : b) fb[c]++;

  int ans = 0;
  for(int i = 0; i < 26; i++){
    char c = 'a' + i;
    ans += fa[c] * fb[c];
  }
  return ans;
}


//////
// const int M = 1e9 + 7;
long long solve(long long n){
  int ii = 63;
  while(not (n & (1LL << ii))) ii--;
  cerr<<ii<<endl;
  vector<long long> arr(64, 0);

  long long pw = pow(2LL, ii-1);
  pw %= M;

  for(int d = 0; d < ii; d++){
    arr[d] += pw;
  }
  arr[ii] += 1;
  db(arr);
  for(long long i = pow(2LL, ii) + 1; i <= n; i++){
    for(int d = 0; d < 64; d++){
      if(i & (1LL<<d))
        arr[d]++;
    }
  }
  long long ans = 0;
  for(int d = 0; d < 64; d++){
    long long pwd = pow(10LL, d);
    pwd %= M;
    db(pwd);
    ans = (ans + ((arr[d] * pwd) % M)) % M;
  }
  return ans;
}
int32_t main(int argc, char const *argv[]){
  // cout << scs("abdc", "bd") << endl;
  T(){
    ll n;
    cin>>n;
    cout << solve(n) << endl;
  }
  return 0;
}
