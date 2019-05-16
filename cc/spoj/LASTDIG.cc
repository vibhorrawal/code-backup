#include<bits/stdc++.h>
using namespace std;
int lastDigit(int a,unsigned int b){
	// here a^b % c where c is 10
	int ans = 1;

	while(b > 0){
		if(b % 2)
			ans =  (ans * a) % 10;

		b /= 2;
		a = (a * a) % 10;
	}
	return ans;
}
int main(int argc, char const *argv[])
{
	int a;
	unsigned int b;
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>a>>b;
		cout<<lastDigit(a,b)<<endl;
	}
	return 0;
}