#include<bits/stdc++.h>
using namespace std;
int compare(const void *a, const void *b)
{
	int *p1 = (int *)a, *p2 = (int *)b;
	return (*p2 - *p1);
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	for (int j = 0; j < t; ++j)
	{
		int n;
		cin>>n;
		int man[n], woman[n];
		for (int i = 0; i < n; ++i)
			cin>>man[i];
		for (int i = 0; i < n; ++i)
			cin>>woman[i];
		qsort(man,n,sizeof(int),compare);
		qsort(woman,n,sizeof(int),compare);
		
		int sum = 0;
		for (int i = 0; i < n; ++i)
			sum += man[i] * woman[i];
		cout<<sum<<endl;
	}
	return 0;
}