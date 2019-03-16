#include<iostream>
#include<math.h>
using namespace std;
void printprime(int min,int max,int *,int);
bool primecheck(int n);
int main()
{

	int n;
	cin>>n;
	int a[n],b[n],max;
	for(int i = 0; i < n ; i++)
	{
		cin>>a[i]>>b[i];
	}

	max = b[0];
	for (int i = 0; i < n; ++i)
	{
		if (b[i] > max)
			max = b[i];
	}

	int prime[max/2];
	int j = 0;
	for(int i = 2; i<=max ;i++)
	{
		if(primecheck(i)){
			prime[j] = i;
			j++;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		printprime(a[i],b[i],prime,j);
	}

	return 0;
}

bool primecheck(int n)
{
	for(int i = 2;i <= sqrt(n); i++)
	{
		if(n%i==0)
		{
			return false;
		}
	}
	return true;
}

void printprime(int min,int max,int prime[],int j)
{
	
	for (int i = 0; i < j; ++i)
	{
		if(prime[i]>= min && prime[i] <= max)
			cout<<prime[i]<<endl;
	}
	cout<<endl;
}