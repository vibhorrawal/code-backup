#include<bits/stdc++.h>
using namespace std;
int n, k;
char vote[1000000];

long long int solve(){

	long long int counter = 0, sum = 0;
	
	if(k == -1){
		// cout<<"this"<<endl;
		for (int i = 0; i < n; ++i)
		{
			if(vote[i] == 'B')
			sum = ((sum % 1000000007) + (static_cast<long long int>(pow(2,i+1)) % 1000000007)) % 1000000007;
		}
		return sum % 1000000007;
	}
	// cout<<"Debug: ";
	for (int i = n-1; i >= 0; --i)
	{
		if(vote[i] == 'B')
			counter++;
		else
			counter--;

		if(counter < 0) counter = 0;

		if (counter == k + 1)
		{
			sum = ((sum % 1000000007) + (static_cast<long long int>(pow(2,i+1)) % 1000000007)) % 1000000007;
			counter -= 2;
		}
	}
	// cout<<endl;
	return sum % 1000000007;
}
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	for (int i = 0; i < t; ++i){
		cin>>n>>k;
		// cout<<n<<' '<<k<<endl;
		cin>>vote;
		cout<<"Case #"<<i+1<<": "<<solve()<<endl;
	}
	return 0;
}