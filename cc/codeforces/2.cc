// https://codeforces.com/contest/1187/problem/B
#include<bits/stdc++.h>
using namespace std;
long long int sz;
long long int n;
long long int solve(char s[], char name[]){
	// name = tolower(name);
	// std::transform(name.begin(), name.end(), name.begin(), ::tolower);
	long long int ans = -1;
	bool incl[strlen(name)] = {0};
	long long int it = 0;
	int flag;
	while(1){
		flag = 0;
		for (int i = 0; i < strlen(name); ++i)
		{
			if(!incl[i] && s[it] == name[i]){
				incl[i] = true;
				break;
			}
		}
		it++;

		for (int i = 0; i < strlen(name); ++i)
			if(incl[i])
				flag++;
		if(flag == strlen(name)) break;
		
	}
	return it;
}
int main(int argc, char const *argv[])
{
	cin>>sz;
	char s[sz];
	cin>>s;
	cin>>n;
	while(n--){
		char name[sz];
		cin>>name;
		cout<<solve(s, name)<<endl;
	}
	return 0;
}