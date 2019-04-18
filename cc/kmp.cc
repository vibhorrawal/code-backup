#include <bits/stdc++.h>
using namespace std;
void computeLPSarray(int lps[], int n, string pat){
	int len = 0;
	lps[0] =  0;
	int i = 1;

	while(i < n){
		if(pat[i] == pat[len])
			lps[i++] = ++len;

		else if(len)
			len = lps[len-1];
		else
			lps[i++] = 0;
	}
}
void kmp(string txt, string pat){
	int m = txt.length();
	int n = pat.length();
	int lps[n];
	computeLPSarray(lps,n,pat);
	int i=0, j=0;
	while(i<m){
		if(pat[j] == txt[i])
			i++,j++;
		if(j == n)
			printf("Found pattern at index %d ", i - j), j = lps[j-1];

		else if(i < m && pat[j]!= txt[i])
			if(j != 0)
				j = lps[j-1];
			else
				i++;

	}
}
int main(int argc, char const *argv[])
{
	string str;
	string pattern;
	cout<<"Enter template: ";
	getline(cin, str);
	cout<<"Enter pattern: ";
	getline(cin, pattern);
	kmp(str,pattern);
	return 0;
}
