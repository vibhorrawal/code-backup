#include<bits/stdc++.h>
using namespace std;
int precedence(char c){
	switch(c){
	case '^': return 3;
	case '*': case '/': return 2;
	case '+': case '-': return 1;
	default: return -1;
	}
}
string infixToPostfix(string exp){
	string output;
	stack<char> st;
	st.push('N');
	int length = exp.length();
	for (int i = 0; i < length; ++i)
	{
		if()
	}
}
int main(int argc, char const *argv[])
{
	string exp;
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>exp;
		cout<<infixToPostfix(exp);
	}
	return 0;
}