#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
  int t;
  cin>>t;
  for(int c=1;c<=t;c++){
  	int n;
  	cin>>n;
  	string in, out;
  	cin>>in;
  	cin>>out;
  	vector<vector<char>> mat(n, vector<char>(n,'N'));
  	for(int i=0;i<n;i++)
  	for(int j=0;j<n;j++)
  		mat[i][j]='N';

  	for(int i=0;i<n;i++){
  		for(int j=0;j<n;j++){
  			if(i==j){
  				mat[i][j]='Y';
  				continue;
			}
  			if(in[j]=='Y' && out[i]=='Y' && j>0 && out[j-1]=='Y' &&mat[i][j-1]=='Y')
  				mat[i][j]='Y';
		}
		for(int j=n-1;j>=0;j--){
			if(in[j]=='Y' && out[i]=='Y' && j<n-1 && out[j+1]=='Y' && mat[i][j+1]=='Y')
				mat[i][j]='Y';
		}
	}
	cout<<"Case #"<<c<<":\n";
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cout<<mat[i][j];
		cout<<endl;
	}
	}



    return 0;
}
