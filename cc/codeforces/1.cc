// https://codeforces.com/contest/1187/problem/A
#include<bits/stdc++.h>
using namespace std;

long long int n,s,t;
long long int solve(){
	// cout<<"Case ";
	long long int x = n - t;
	long long int y = n - s;
	// cout<<n<<' '<<s<<' '<<t<<endl;
	// cout<<"X "<<x<<endl;
	// cout<<"Y "<<y<<endl;
	if(x > y)
		return x + 1;
	else 
		return y + 1;
}
int main(int argc, char const *argv[])
{
	int tt;
	cin>>tt;
	while(tt--){
		cin>>n>>s>>t;
		cout<<solve()<<endl;
	}
	return 0;
}