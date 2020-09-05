// { Driver Code Starts
// Initial Template for C++
/* script for test case http://code.geeksforgeeks.org/PetjYq */
#include <bits/stdc++.h>

using namespace std;

string findOrder(string[], int, int);
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s[n];
        for (int i = 0; i < n; i++) cin >> s[i];

        string ss = findOrder(s, n, k);
        order = "";
        for (int i = 0; i < ss.size(); i++) order += ss[i];

        string temp[n];
        std::copy(s, s + n, temp);
        sort(temp, temp + n, f);

        bool f = true;
        for (int i = 0; i < n; i++)
            if (s[i] != temp[i]) f = false;

        cout << f;
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


// User function Template for C++

/*
dict : array of strings denoting the words in alien langauge
N : Size of the dictionary
K : Number of characters
*/
void dfs(int u, bool vis[], vector<vector<int>> &adj, string &res, map<char, int> &mp){
  vis[u] = true;

  for(auto v: adj[u]){
    if(!vis[v])
      dfs(v, vis, adj, res, mp);
  }
  char c;
  for(auto it: mp){
    if(it.second == u){
      c = it.first;
      break;
    }
  }
  res += c;
}
void top_sort(vector<vector<int>> &adj, string &res, map<char, int> &mp){
  bool vis[adj.size()];
  memset(vis, false, sizeof vis);

  for(int v = 0; v < adj.size(); v++){
      if(!vis[v])
        dfs(v, vis, adj, res, mp);
  }
}
string findOrder(string dict[], int n, int k) {
    // Your code here
    vector<vector<int>> adj(k);
    //map for characters mapping
    map<char, int> mp;
    int k_ = 0;
    for (int i = 0; i < n; i++) {
      for(auto c: dict[i]){
        if(mp.find(c) == mp.end())
          mp[c] = k_++;
      }
      if(mp.size() == k)
      break;
    }
    int u,v;
    for (int i = 0; i < n-1; i++) {
      int j = 0;
      while(1){
        u = mp[dict[i][j]];
        v = mp[dict[i+1][j]];
        if(u != v /*&& find(adj[u].begin(), adj[u].end(), v) == adj[u].end()*/)
          break;
        j++;
        if(j >= min(dict[i].size(), dict[i+1].size()))
          break;
      }
      adj[u].push_back(v);
      // cout << "u: "<<char(u+'a')<<" v: "<<char(v+'a') << endl;
    }
    string res = "";
    top_sort(adj, res, mp);
    reverse(res.begin(), res.end());
    // res = "abcdefghijkl";
    cout << res << endl;
    return res;
}
