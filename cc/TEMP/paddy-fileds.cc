#include<bits/stdc++.h>
using namespace std;
long int solve(bool field[], int n);
int count_pos(bool field[], int n, int k);
int main(int argc, char const *argv[])
{
	int n, k, temp;
	cin>>n;
	bool field[n] = {0};
	cin>>k;
	for (int i = 0; i < k; ++i)
	{
		cin>>temp;
		field[temp] = true;
	}

	cout<<solve(field, n)<<endl;	
	return 0;
}
int count_pos(bool field[], int n, int k){
	int count = 0;
	for (int i = 0; i < n-1; ++i)
	{
		if(field[i] == true && field[i+1] == false)
			count++;
	}
	if(field[0] == false && field[1])
		count++;
	if(field[n-2] == field[n-2] == false && field[n-1] == true)
		count++;
	// cout<<':'<<count<<endl;
	int pos = -1;
	for (int i = 0; i < n; ++i)
	{
		if(!field[i]){
			pos = i;
			break;
		}
	}
	if(pos == -1 || count == 0)
		return 1;
	field[pos] = true;
	return count;
}
long int solve(bool field[], int n){
	int mod = 1000000007;
	long int count = 1;
	for (int i = 0; i < n; ++i)
	{
		count = (count % mod * count_pos(field,n,i) % mod) % mod;
	}
	return count % mod; 
}