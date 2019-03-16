#include<iostream>
#include<math.h>
using namespace std;

void simpleSieve(char a[],int n);
void segmentedSieve(int min, int max, char a[], int n);
void primecheck(char a[], int n);
void primecheck(int min,char a[],int n ,char r[], int m);

int main()
{

	int n;
	cin>>n;
	//int m = sqrt(n);
	int a[n],b[n];
	//char an[m];
	for(int i = 0; i < n ; i++)
	{
		cin>>a[i]>>b[i];
	}

	for (int i = 0; i < n; ++i)
	{
		int m = sqrt(b[i]);
		char an[m];
		simpleSieve(an,m);

		segmentedSieve(a[i],b[i],simpleSieve(an,m),m);
	}

	return 0;
}

void simpleSieve(char a[],int n)
{
	// creating an array with just primenumbers = 1 and composite = 0
	primecheck(a,n);

}

void segmentedSieve(int min, int max, char a[], int n)
{
	// bigger array
	char r[max-min + 1];

	// performing algorithm
	primecheck(min,a,n,r,max-min+1);
	
	// printing primes
	for (int i = 0; i < max-min; ++i)
	{
		if(r[i] == 1)
			cout<<i<<endl;
	}
	cout<<endl;
}

void primecheck(char a[], int n)
{
	a[0] = 0;
	a[1] = 1;

	for (int i = 2; i < n; ++i)
	{
		for (int j = 2; j < i/2 + 1; ++j)
		{
			if( (i+1) % j == 0)
				a[i] = 0;
		}

	}

	//remaining primes
	for (int i = 0; i < n; ++i)
	{
		if(a[i] != 0)
			a[i] = 1;
	}

}

void primecheck(int min,char a[],int n ,char r[], int m)
{
	for (int i = 1; i < m; ++i)
	{
		for (int j = 1; j < n; ++j)
		{
			if( a[j-1] == 1 && ( (min + i) % j == 0 ))
				{
					r[i] = 0;
					break;
				}
		}
		if (r[i] != 0)
			r[i] = 1;
	}
}