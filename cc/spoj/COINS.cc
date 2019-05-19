#include<bits/stdc++.h>
using namespace std;
multimap<long int, long int> dict;

long int bank(long int n){
	auto itr = dict.find(n);
	if(itr->second)
		return itr->second;
	if(n <= 2)
		return n;
	long int change = bank(n/2) + bank(n/3) + bank(n/4);

	if(change>n){
		dict.insert({n,change}); 
		return change;
	}
	else{
		dict.insert({n,n});	
		return n;
	}
	// if(change > n)
	// 	return change;
	// else
	// 	return n;
}

 int main( int argc, char const *argv[])
{
	long int n;
	long int count = 0;
	while(cin>>n && count < 10){
		cout<<bank(n)<<endl;
		count++;
	}
	// cout<<endl;
	return 0;
}