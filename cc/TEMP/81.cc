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

int makeStringEmpty(string s) {
        if(s.empty()) return 0;
        if(s[0] != 'g') return -1;

        // code here
    int ans = 0;
    stack<string> st;
    st.push("g");
    s.erase(s.begin());

    for(char c : s){
        string t = st.top();
        switch (t.back()) {
            case 'g':
            if(c == 'e') {
                st.pop();
                st.push("ge");
            }
            else st.push(string(1, c));
            break;

            case 'e':
            if(c == 'e'){
                if(t.size() == 2) {
                    st.pop();
                    st.push("gee");
                }
                // else return -1;
            }
            else{
                if(t.size() == 3){
                    if(c == 'k'){
                        st.pop();
                        st.push("geek");
                    }
                    else {
                    st.push(string(1, c));
                    }
                }
            }
            break;
            case 'k':
                st.push(string(1, c));
        }
        while(st.size()>1 and st.top().size() == 4){
            st.pop();
            ans++;
        }
    }
    while(st.size() and st.top().size() == 4){
        st.pop();
        ans++;
    }
    while(st.size()){
        cout<<st.top();
        st.pop();
    }
    if(st.size()) return -1;
    return ans;

}

int32_t main(int argc, char const *argv[]){
    fastIO;
    cout << makeStringEmpty("gegeekek") << endl;
    return 0;
}
