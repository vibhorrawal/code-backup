#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000000
int size = 1;
int *res;

void multiply(int M){
	int prod, carry = 0;
	for (int i = 0; i < size; ++i)
	{
		prod = res[i] * M + carry;
		// Store last digit of 'prod' in res[]   
        res[i] = prod % 10;   
  
        // Put rest in carry 
        carry  = prod/10; 
	}
	while(carry){
		res[size] = carry % 10;
		size++;
		carry /= 10;
	}
}


void factorial(int n){
	for (int i = 1; i <= n; ++i)
	{
		multiply(i);
	}

	for (int i = size-1; i>=0; --i)
		cout<<res[i];
	cout<<endl;
	
	size = 1;
	res[0] = 1;
}


int main(int argc, char const *argv[])
{
	res = new int[MAX];
	int n,k;
	cin>>n;
	res[0] = 1;
	
	for (int i = 0; i < n; ++i)
	{
		cin>>k;
		factorial(k);
	}
	
	return 0;
}
