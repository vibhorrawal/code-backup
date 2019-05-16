#include<bits/stdc++.h>
using namespace std;
int numberOfSquares(int x){
	if(!x)
		exit(0);
	int sum = 0;
	for (int i = 1; i <= x; ++i)
	{
		sum += i*i;
	}
	return sum;
}
int main(int argc, char const *argv[])
{
	int x = 1;
	while(x){
		cin>>x;
		cout<<numberOfSquares(x)<<endl;
	}
	return 0;
}