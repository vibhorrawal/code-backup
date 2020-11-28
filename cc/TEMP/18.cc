#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	unordered_set<int> s;
	s.insert(1);
	s.insert(10);
	auto i = s.find(100);
	cout<<*i<<endl;//<<s.find(2)<<endl<<s.find(10)<<endl<<s.end()<<endl;	
	return 0;
}