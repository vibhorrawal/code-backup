#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const 
	*argv[])
{
	vector<long int> prime;
	prime.push_back(2);

	for (long int i = 3; i < 32000; i += 2)
		{				
			bool isPrime = true;
			int root = sqrt(i);
			for (vector<long int>::iterator p = prime.begin(); p != prime.end(); ++p)
			{
				if(*p > root)
					break;
				if(i % *p == 0){
					isPrime = false;
					break;
				}
				
			}
			if(isPrime)
					prime.push_back(i);
		}
	long int n, low, high;
	cin>>n;
	while(n--){
		cin>>low>>high;
		if(low < 2)
			low = 2;
		set<long int> notPrime;
		notPrime.clear();
		long int start;
		for (std::vector<long int>::iterator p = prime.begin(); p != prime.end(); ++p)
		{
			if(*p > sqrt(high))
				break;
			if(*p > low)
				start = (*p) * 2;
			else
				start = low + ( (*p - low % *p) % *p);
			for (long int i = start; i < high; i += *p)
				notPrime.insert(i);
		}
		for (long int i = low; i < high; ++i)
			if(!notPrime.count(i))
				cout<<i<<endl;
		cout<<endl;	
		
	}		
	return 0;
}