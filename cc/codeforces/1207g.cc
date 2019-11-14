#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define v1d  vector<int>
#define v2d  vector<vector<int> >
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define endl '\n'
#define REP(i,n) for(auto i=0;i<(n);i++)
#define FOR(i,a) for(auto i=a.begin();i!=a.end();i++)
#define DEBUG true
void iinternaut(){
    ///freopen("output.txt","w",stdout);
    ///freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
void computeLPSArray(string pat, int M, int lps[]);

int KMPSearch(string pat, string txt)
{
    int count = 0;
    int M = pat.length();
    int N = txt.length();
    int lps[M];
    computeLPSArray(pat, M, lps);

    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }

        if (j == M) {
          count++;
            j = lps[j - 1];
        }

        else if (i < N && pat[j] != txt[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    delete(lps);
    return count;
}

void computeLPSArray(string pat, int M, int lps[])
{
    int len = 0;

    lps[0] = 0; // lps[0] is always 0

    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {

            if (len != 0) {
                len = lps[len - 1];

            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int32_t main(int argc, char const *argv[]){
  iinternaut();
  int n;
  cin>>n;
  vector<string> ch(n);
  int t,j;
  char c;
  REP(i,n){
    cin>>t;
    if(t == 1){
      cin>>c;
      ch[i] = c;
    }
    else if(t == 2){
      cin>>j>>c;
      ch[i] = ch[j-1]+c;
    }
    // cout<<ch[i]<<endl;
  }
  T(){
    int k;
    string txt;
    cin>>k>>txt;
    cout<<KMPSearch(txt,ch[k-1])<<endl;
  }
  return 0;
}
