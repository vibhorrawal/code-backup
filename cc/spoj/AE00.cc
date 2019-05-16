#include<bits/stdc++.h>
using namespace std;
int countRectangles(int n){
	int ans = 0;
// 	 length <= height
// or, length*length <= length*height
// or, length*length <= n
// or, length <= sqrt(n)
	for(int l = 1; l <= sqrt(n); l++)
		for(int b = l; l * b <= n; b++)
			ans++;
	return ans;	
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	cout<<countRectangles(n)<<endl;	
	return 0;
}