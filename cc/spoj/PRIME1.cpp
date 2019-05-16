#include<bits/stdc++.h>
using namespace std;
vector< long int> prime;
void simpleSieve( int n){
	bool primeSet[n+1];
	memset(primeSet ,true, sizeof(primeSet));

	for ( int p = 2; p*p <= n; p++)
	{
		if(primeSet[p]){
			for ( int i = p*p; i <= n; i += p)
				primeSet[i] = false;
		}
	}

	for ( int i = 2; i < n; ++i)
		if(primeSet[i]){
			prime.push_back(i);
			// cout<<':'<<i<<endl;
		}
}
void segmentedSieve( int m,  int n){
	 int limit = ceil(sqrt(n));
	if(limit>100000) limit = 100000;
	simpleSieve(limit);

	 int low = limit;
	 int high = limit * 2;
	 int lowerLimit;
	bool mark[limit]; 

	while(low < n)
	{
		if(high > n)
			high = n;


        memset(mark, true, sizeof(mark)); 

        for ( int i = 0; i < prime.size(); ++i)
        {
        	if(prime[i] == 0) continue;

        	lowerLimit = ceil((low*1.0)/prime[i]) * prime[i];
        	// if(lowerLimit < low) lowerLimit += prime[i];
        	for ( int j = lowerLimit; j < high; j += prime[i])
        		mark[j-low] = false;//,cout<<':'<<j<<endl;
        }

        for ( int i = low; i < high; ++i)
        	if(mark[i-low])
        		prime.push_back(i);

        low += limit;
        high += limit;	
	}
/*
	 int i = 0;
	while(prime[i] < m)
		i++;

	while(prime[i] <= n && prime[i] != 0)
		cout<<prime[i++]<<endl;

	prime.clear();
	*/
}

void SieveOfEratosthenes( int l,  int n);
int main(int argc, char const *argv[])
{
	 int n,j,k;
	cin>>n;
	for ( int i = 0; i < n; ++i)
	{
		cin>>j>>k;
		segmentedSieve(j,k);
		cout<<endl;
	}
	return 0;
}

void SieveOfEratosthenes( int l,  int n){
	bool prime[n+1];
	memset(prime ,true, sizeof(prime));

	for ( int p = 2; p*p <= n; p++)
	{
		if(prime[p]){
			for ( int i = p*p; i <= n; i += p)
				prime[i] = false;
		}
	}
	if(l<2) l = 2;
	for ( int p=l; p<=n; p++) 
       if (prime[p]) 
          cout << p <<endl;
     cout<<endl; 
}
