#include<bits/stdc++.h>
using namespace std;
void candyCheck(int inp[], int n){
	// for (int i = 0; i < n; ++i)
	// 	cout<<inp[i]<<' ';
	// cout<<endl;
	int sum = 0;
	for (int i = 0; i < n; ++i)
		sum += inp[i];
	int avg = sum / n;
	if(avg * n == sum)
		cout<<"YES\n";
	else
		cout<<"NO\n";
}
int main(int argc, char const *argv[])
{
	unsigned long long int k,n,temp;
	unsigned long long int sum = 0;
	// char c[2];
	cin>>n;
	// int inp[10000];
	while(n--){
		cin>>k;
		for (unsigned long long int i = 0; i < k; ++i)
		{
			cin>>temp;
			sum = (sum%k + temp%k) % k;
		}
		if(!sum)
			cout<<"YES\n";
		else
			cout<<"NO\n";

	}
	return 0;
}