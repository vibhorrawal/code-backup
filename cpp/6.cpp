// SPOJ PRIME1
#include<iostream>
#include<math.h>
using namespace std;


void createSieve(char s[],int m);
void markAdaptedSieve(char bigS[],int p,int min,char s[],int m);

int main()
{		
	// test
	// char s[10],bigS[20];
	// createSieve(s,10);
	// markAdaptedSieve(bigS,20,80,s,10);
	// exit(0);

	int n,m,p;
	cin>>n;
	int min[n],max[n];

	for (int i = 0; i < n; ++i)
	{
		cin>>min[i]>>max[i];
	}

	for (int i = 0; i < n; ++i)
	{
		m = sqrt(max[i]);
		p = max[i] - min[i];
		char s[m+1],bigS[p+1];
		createSieve(s,m+1);
		markAdaptedSieve(bigS,p+1,min[i],s,m+1);
		// printPrimes(bigS,p);
		cout<<endl;
	}

	
	return 0;
}

void createSieve(char s[],int m)
{
	s[0] = s[1] = 2;
	s[2] = 1;
	for (int i = 3; i < m; ++i)
	{
		for (int j = 2; j <= i/2; ++j)
		{	
			// 1 for prime and 2 for composite
			//cout<<i<<' '<<j<<endl;
			if(i % j == 0){
				s[i] = 2;
				break;
			}

		}
		if(s[i] != 2)
				s[i] = 1;
	}

	// cout<<"Sieve: \n";
	// for (int i = 0; i < m; ++i)
	// {	
	// 	if ( s[i] == 1)
	// 	cout<<i<<endl;
	// }
	// cout<<"end"<<endl;
}

void markAdaptedSieve(char bigS[],int p,int min,char s[],int m)
{
	// s[m] is the array with prime numbers when i = 1
	for (int i = 0; i < p; ++i)
	{
		// bigS[i] is currently accessed
		for (int j = 0; j<m; ++j)
		{
			if ( s[j] == 1)
			{
				// cout<<"in loop: "<<j<<' '<<i<<' '<<i+min<<endl;
				// iterating primes from s[j] OR SIMPLY j is a prime
				if ( (i + min) % j == 0 && j != (i+min))
				{

					//composite number
					bigS[i] = 2;
					break;
				}
			}
		}
		if( bigS[i] != 2 )
			bigS[i] = 1;
	}
	if (min == 1)
		bigS[0] = 2; 
	if (min == 0)	
		bigS[0] = bigS[1] = 2;

	for (int i = 0; i < p; ++i)
	{	
		if ( bigS[i] == 1)
		cout<<i+min<<endl;
	}
}