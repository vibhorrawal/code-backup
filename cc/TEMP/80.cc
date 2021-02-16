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
#define endl char(10)
#define pb emplace_back
#define fastIO ios_base::sync_with_stdio(false),cin.tie(NULL)
template<class T> void read(T& x) { cin >> x; }
template<class A> void read(vector<A>& a) { for(auto& x: a) read(x); }
template<class T>string to_string(const vector<T> &v) {
  string res; REP(i,sz(v)) res += to_string(v[i]) + " "; res.pop_back(); return res; }
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
  cerr << to_string(h); if(sizeof...(t)) cerr << ", "; DBG(t...); }
#define db(...) if(1) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)

int lexiographicRank(string s)
{
    // Length of string
    int n = s.length();

    vector<int> alphaIndex[26];

    // Traverse the given string
    // and store the indices of
    // each character
    for (int i = 0; i < s.length(); i++) {

        // Extract the index
        int x = s[i] - 'a';

        // Store it in the vector
        alphaIndex[x].push_back(i);
    }

    // Traverse the aphaIndex array
    // lesser than the index of first
    // character of given string
    int rank = 0;

    for (int i = 0; i < 26
                    && 'a' + i < s[0];
         i++) {

        // If alphaIndex[i] size exceeds 0
        if (alphaIndex[i].size() > 0) {

            // Traverse over the indices
            for (int j = 0;
                 j < alphaIndex[i].size(); j++) {

                // Add count of substring
                // equal to n - alphaIndex[i][j]
                rank = rank
                       + (n
                          - alphaIndex[i][j]);
            }
        }
    }

    vector<string> str;

    for (int i = 0;
         i < alphaIndex[s[0] - 'a'].size();
         i++) {

        // Store all substrings in a vector
        // str starting with the first
        // character of the given string
        string substring;

        int j = alphaIndex[s[0] - 'a'][i];

        for (; j < n; j++) {

            // Insert the current
            // character to substring
            substring.push_back(s[j]);

            // Store the substring formed
            str.push_back(substring);
        }
    }

    // Sort the substring in the
    // lexicographical order
    sort(str.begin(), str.end());

    // Find the rank of given string
    for (int i = 0; i < str.size(); i++) {

        if (str[i] != s) {

            // increase the rank until
            // the given string is same
            rank++;
        }

        // If substring is same as
        // the given string
        else {
            break;
        }
    }

    // Add 1 to rank of
    // the given string
    return rank + 1;
}

int check(string s){
    set<string> used;
    for(int i = 0; i < s.size(); i++){
        for(int j = 0; j <= s.size(); j++) {
            string sub = s.substr(i, j);
            used.insert(sub);
        }
    }
    int r = 0;
    for(string ss : used) {
        // cout<<ss<<endl;

        if(ss == s) return r;
        r++;

    }
    return -1;
}

int32_t main(int argc, char const *argv[]){
    fastIO;
    T(){
        string s;
        cin>>s;
        cout << check(s) << endl;
        // assert(check(s) == lexiographicRank(s));
        // cout << lexiographicRank(s) << endl;
    }
    return 0;
}
