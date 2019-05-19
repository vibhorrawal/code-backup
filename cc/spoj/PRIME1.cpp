// very slow code
#include<bits/stdc++.h>
using namespace std;
vector<unsigned long long int> prime;
void segmentedSieve( unsigned long long int m,  unsigned long long int n,bool print);
void simpleSieve( unsigned long long int n);
void SieveOfEratosthenes( unsigned long long int l,  unsigned long long int n);
//----------------------------------------------------------------------------------------------
int main(int argc, char const *argv[])
{
	 unsigned long long int n,j,k;
	cin>>n;
	segmentedSieve(2,32000,false);
	for ( unsigned long long int i = 0; i < n; ++i)
	{
		cin>>j>>k;
		segmentedSieve(j,k,true);
		cout<<endl;
	}
	return 0;
}
//----------------------------------------------------------------------------------------------
void simpleSieve( unsigned long long int n){
	bool primeSet[n+1];
	memset(primeSet ,true, sizeof(primeSet));

	for ( unsigned long long int p = 2; p*p <= n; p++)
	{
		if(primeSet[p]){
			for ( unsigned long long int i = p*p; i <= n; i += p)
				primeSet[i] = false;
		}
	}
	prime.push_back(2);
	for ( unsigned long long int i = 3; i < n; i += 2)
		if(primeSet[i]){
			prime.push_back(i);
			// cout<<':'<<i<<endl;
		}
}
void segmentedSieve( unsigned long long int m,  unsigned long long int n, bool print){
	 unsigned long long int limit = ceil(sqrt(n));
	if(limit>100)
		limit = 100;
	if(!prime.empty() && (prime.back() < limit))
		simpleSieve(limit);
	else if(prime.empty())
		simpleSieve(limit);

	 unsigned long long int low = limit;
	 unsigned long long int high = limit * 2;
	 unsigned long long int lowerLimit;
	bool mark[limit]; 

	while(low < n)
	{
		if(high > n)
			high = n;


        memset(mark, true, sizeof(mark)); 

        for ( unsigned long long int i = 0; i < prime.size(); ++i)
        {
        	if(prime[i] == 0) continue;

        	lowerLimit = ceil((low*1.0)/prime[i]) * prime[i];
        	// if(lowerLimit < low) lowerLimit += prime[i];
        	for ( unsigned long long int j = lowerLimit; j < high; j += prime[i])
        		mark[j-low] = false;//,cout<<':'<<j<<endl;
        }

        for ( unsigned long long int i = low; i < high; ++i)
        	if(mark[i-low])
        		prime.push_back(i);

        low += limit;
        high += limit;	
	}
	if(print){
	 unsigned long long int i = 0;
	while(prime[i] < m)
		i++;

	while(prime[i] <= n && prime[i] != 0)
		cout<<prime[i++]<<endl;
	}
	// prime.clear();
	
}
void SieveOfEratosthenes( unsigned long long int l,  unsigned long long int n){
	bool prime[n+1];
	memset(prime ,true, sizeof(prime));

	for ( unsigned long long int p = 2; p*p <= n; p++)
	{
		if(prime[p]){
			for ( unsigned long long int i = p*p; i <= n; i += p)
				prime[i] = false;
		}
	}
	if(l<2) l = 2;
	for ( unsigned long long int p=l; p<=n; p++) 
       if (prime[p]) 
          cout << p <<endl;
     cout<<endl; 
}
