#include<bits/stdc++.h>
using namespace std;

int z_factorial(int num){
	int count = 0;
	while(num > 4){
		num /= 5;
		count += num;
	}
	return count;
}
int main(int argc, char const *argv[])
{
	
	int n,k;
	cin>>n;
	
	// cout<<mod(n,k);return 0;
	
	for (int i = 0; i < n; ++i)
	{
		cin>>k;
		cout<<z_factorial(k)<<endl;
	}
	
	return 0;
}
