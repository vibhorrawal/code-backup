/*
त्यक्तवाधर्मं च लोभं च
मोहंचो द्यमास्थिता।
युद्ध्यध्वमनहंकारा
यतो धर्मस्ततो जयः।।
*/
#include<bits/stdc++.h>
using namespace std;
#define int     long long
#define ld      long double
#define pb      push_back
#define pa      pair<int,int>
#define v1d     vector<int>
#define v2d     vector<vector<int> >
#define M       1000000021
#define mp      make_pair
#define MN      LLONG_MIN
#define MX      LLONG_MAX
#define ff      first
#define ss      second
#define ump     map<int,int>
#define endl    "\n"
#define v1s     vector<string>
#define S(v)    sort(v.begin(),v.end())
#define RS(v)   sort(v.rbegin(),v.rend())
#define mxpq    priority_queue <int>
#define mnpq    priority_queue<int,vector<int>,greater<int>>
#define T       int tc;cin>>tc;while(tc--)
void Weapons19(){
    cin.sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
}

int32_t main(){
    Weapons19();










}



BFS COUNT
v1d freq;
void bfsCount(v2d &v,int n){
	v1d visited(n+1,0);
	queue<int>q;
	int nodes=0;
	for(int i=1;i<=n;i++){
    	if(visited[i]==0){
        	q.push(i);
        	visited[i]=1;
        	nodes++;
        	while(!q.empty()){
            	int t=q.front();
            	for(int j=0;j<v[t].size();j++){
                	if(visited[v[t][j]]==0){
                    	q.push(v[t][j]);
                    	visited[v[t][j]]=1;
                    	nodes++;
                	}
            	}
            	q.pop();
        	}
    	freq.pb(nodes);
    	nodes=0;
    	}
	}
 }








COMBINATIONS


int binomialCoeff(long long n, long long k)
{
	int ans=1;
	if(k>n-k)
	k=n-k;
   for(int i=0;i<k;i++)
   {
   	ans=ans*(n-i)/(i+1);
   }

 return ans;
}

SIEVE OF ERATOSTHENES
vector<int> sieve;
void SieveOfEratosthenes(int n){
    vector<bool>v(n+1,1);
    for(int i=4;i<=n;i+=2){
        v[i]=0;
    }
    for(int i=3;i*i<=n;i+=2){
        if(v[i]){
            for(int p=i*i;p<=n;p+=2*i)v[p]=0;
        }
    }
    for(int i=2;i<=n;i++){
        if(v[i])sieve.push_back(i);
    }
}

COMPARATOR
bool comp(v1d v1,v1d v2){
    return (v1[2]>v2[2]);
}








GCD & INVERSE MODULO
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
int x,y,GCD;
void extEuclid(int a,int b){
    if(b==0){
        x=1;y=0;GCD=a;return ;
    }
    extEuclid(b,a%b);
    int cx,cy;
    cx=y;
    cy=x-(a/b)*y;
    x=cx;
    y=cy;

}

COMBINATIONS TABLE
v2d comb;
void combinations(int n,int r){
    comb.resize(n+1,v1d(r+1,0));
    for(int i=0;i<=n;i++)comb[i][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            comb[i][j]=(comb[i-1][j]+comb[i-1][j-1])%mod;
        }
    }
}
IS BIPARTITE
bool isBipartite(v2d &v,int n,v1d &vis){
    for(int i=1;i<=n;i++){
        if(vis[i]==-1){
            if(v[i].size()<1)continue;
            vis[i]=1;
            queue<int>q;
            q.push(i);
            while(!q.empty()){
                int a=q.front();
                for(int j=0;j<v[a].size();j++){
                    if(vis[v[a][j]]==-1){
                        vis[v[a][j]]=(vis[a]+1)%2;
                        q.push(v[a][j]);
                    }
                    if(vis[v[a][j]]==vis[a]){
                        return 1;
                    }
                }
                q.pop();
            }
        }
    }
    return 0;
}





PATH EXIST?
int dfs(int a,int b,v2d&v,v1d &vis){
    vis[a]=1;
    if(a==b)return 1;
    for(int i=0;i<v[a].size();i++){
        if(vis[v[a][i]]==0){
            int k=dfs(v[a][i],b,v,vis);
            if(k)return k;
        }
    }
    return 0;
}

FLOOD FILL
void floodfill(char k,char p,v1s &v,int n,int m,int a,int b){
    if(a<0||b<0||a+1>n||b+1>m)return;
    if(v[a][b]!=p)return;
    t++;
    v[a][b]=k;
    floodfill(k,p,v,n,m,a-1,b);
    floodfill(k,p,v,n,m,a,b-1);
    floodfill(k,p,v,n,m,a,b+1);
    floodfill(k,p,v,n,m,a+1,b);
}
KMP
v1d kmp;
bool prefix_function(string s){
    int n=s.length();
    kmp.pb(0);
    for(int i=1;i<n;i++){
        int j=kmp[i-1];
        while(j>0&&s[j]!=s[i])
            j=kmp[j-1];
        if(s[i]==s[j])
            j++;
        kmp.pb(j);
    }
}





INVERSION COUNTING
int CImergesort(v1d &v,int a,int b){
    if(a>=b)return 0;
    int m=(a+b)/2;
    int z=mergesort(v,a,m)+mergesort(v,m+1,b);
    int i=a,j=m+1;
    v1d aux;
    while(1){
        if(i==m+1){
            while(j!=b+1){
                aux.pb(v[j++]);
            }
                break;
        }
        if(j==b+1){
            while(i!=m+1){
                aux.pb(v[i++]);
            }
                break;
        }
        if(v[i]<=v[j]){aux.pb(v[i++]);}
        else {aux.pb(v[j++]);z+=m-i+1;}
    }int p=0;
    for(int x=a;x<=b;x++){
        v[x]=aux[p++];
    }
    return z;
}
