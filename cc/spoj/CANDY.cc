#include<bits/stdc++.h>
using namespace std;
int candy(int in[], int n){
	int sum = 0;
	for (int i = 0; i < n; ++i)
		sum += in[i];
	int avg = sum/n;
	if(avg * n != sum) return -1;

	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		if((in[i] - avg) > 0)
			count += (in[i] - avg) ;
	}
	return count;
}
int main(int argc, char const *argv[])
{
	while(1)
	{
		int n;
		cin>>n;
		if(n == -1) return 0;
		int in[n];
		for (int i = 0; i < n; ++i)
				cin>>in[i];

		cout<<candy(in,n)<<endl;	
	}
	return 0;
}