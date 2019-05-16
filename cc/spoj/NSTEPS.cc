#include<bits/stdc++.h>
using namespace std;
void steps(int x, int y)
{
	if(x == y){
		if(x%2 == 0)
			cout<<2*x<<endl;
		else
			cout<<2*x-1<<endl;
	}
	else if(x-y == 2){
		if(x%2 == 0)
			cout<<x+y<<endl;
		else
			cout<<x+y-1<<endl;
	}
	else
		cout<<"No Number\n";
}
int main(int argc, char const *argv[])
{
	int n,x,y;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>x>>y;
		steps(x,y);
	}
	
	return 0;
}