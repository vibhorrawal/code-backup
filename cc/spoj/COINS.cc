#include<bits/stdc++.h>
using namespace std;
int bank(int n){
	int change = n/2 + n/3 + n/4;
	if(change>n) 
		return bank(change);
	return n;
	// if(change > n)
	// 	return change;
	// else
	// 	return n;
}

int main(int argc, char const *argv[])
{
	int n;
	int count = 0;
	while(cin>>n && count < 10){
		cout<<bank(n)<<endl;
		count++;
	}
	// cout<<endl;
	return 0;
}