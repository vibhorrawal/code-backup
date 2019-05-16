#include<bits/stdc++.h>
using namespace std;
void decrypt(string s, int n){
	int m = ceil(s.length() * 1.0 / n);
	// cout<<m;
	char out[m][n];
	// int k = 0;
	
	// 	}
	int i = 0, j = 0, k = 0;
	while(k < m*n){
		out[i][j] = s[k++];//, cout<<out[i][j];;
		if(i%2)
			j--;//, cout<<"j--"<<endl;
		else
			j++;//, cout<<"j++"<<endl;

		if(j >= n){
			j--;//, cout<<"j--"<<endl;
			i++;//, cout<<"i++"<<endl;
		}
		if(j < 0){
			j++;//, cout<<"i++"<<endl;
			i++;//, cout<<"j++"<<endl;
		}
	}
	// cout<<"*******************"<<out[0][0]<<endl;
	// for (int l = 0; l < m; ++l)
	// 	for(int h = 0; h < n; ++h)
	// 		cout<<out[l][h];
	// 	cout<<endl;
	// int i = 0, j = 0;
	i = j = k = 0;	
	while(j < n){
		cout<<out[i][j];
		// k++;
		
		i++;
		if(i >= m){
			j++;
			i = 0;
		}
	}
	cout<<endl;
	
}
int main(int argc, char const *argv[])
{
	int n;
	string s;
	while(1){
		cin>>n;
		if(!n) return 0;
		cin>>s;
		// cout<<"here";
		decrypt(s,n);
	}
	return 0;
}