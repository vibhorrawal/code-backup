// pemutation of string
#include<bits/stdc++.h>
using namespace std;

void permutation(string str, string prefix){
	if(str.length() == 0){
		cout<<"---"<<prefix<<endl<<endl;
	}
	else{
		for (int i = 0; i < str.length(); ++i)
		{
			string rem = str.substr(0, i) + str.substr(i+1);
			cout<<"rem: "<<rem<<endl;
			cout<<"prefix + str[i]: "<<(prefix + str[i])<<endl;
			permutation(rem, prefix + str[i]);
		}
	}
}
asdf
int main(int argc, char const *argv[])
{
	permutation("abcd","");
	return 0;
}
/*
OUTPUT:
*/
