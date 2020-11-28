#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int* a;
	a = new int[5];
	a[4] = 10;
	int at[5] = {0,1,2,3,4};
	int bt[5];
	memcpy(bt,at,sizeof(at));
	cout<<bt[0]--<<at[0]<<bt[4]<<endl;
	cout<<(sizeof(a)/sizeof(a[0]));
	cout<<endl<<sizeof(at[0]);
	return 0;
}