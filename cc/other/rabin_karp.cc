#include <bits/stdc++.h>
#define D 256
#define PRIME 100000001
using namespace std;
int rabin_karp(string str, string pattern){
	// cout<<str.length()<<endl;
	int pat = 0,h = 1, st = 0;
	int m = str.length(), n = pattern.length();
	for (int i = 0; i < n; ++i)
	{
		pat = (D * pat + pattern[i]) % PRIME;
		st = (D * st + str[i]) % PRIME;
		h = h * D;
	}
	h = h / D;
	int j;
	for (int i = 0; i < m - n + 1; ++i)
	{
		if( pat == st){
			for (j = 0; j < n; ++j)
			{
				if(str[i+j] != pattern[j])
					break;
			}
			if(j == n) cout<<"Pattern found at "<<i<<endl;
		}

		if(i < m - n){
			st = (D*(st - str[i]*h) + str[n+i]) % PRIME;
			st = abs(st);
		}
	}
	// cout<<pat<<endl;
}
int main(int argc, char const *argv[])
{
	string str;
	string pattern;
	cout<<"Enter template: ";
	getline(cin, str);
	cout<<"Enter pattern: ";
	getline(cin, pattern);
	// cout<<"Pattern found at "<<rabin_karp(str,pattern)<<" index\n";
	rabin_karp(str,pattern);
	return 0;
}
