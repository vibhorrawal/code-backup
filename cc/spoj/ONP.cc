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
	char c;
	stack<char> st;
	st.push('#');
	int length = exp.length();
	for (int i = 0; i < length; ++i)
	{
		// if operand
		if((exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= 'A' && exp[i] <='Z'))
			output += exp[i];
		// if '('
		else if(exp[i] == '(')
			st.push('(');
		// if ')' 
		else if(exp[i] == ')'){

			while(st.top() != '#' && st.top() != '('){
				 c = st.top();
				st.pop();
				output += c;
			}
			if(st.top() == '(')
				st.pop();
		}
		// if operator
		else{
			while(st.top() != '#' && precedence(exp[i]) <= precedence(st.top())){
				 c = st.top();
				st.pop();
				output += c;
			}
			st.push(exp[i]);
		}
	}
	// pop all remaining elements
	while(st.top() != '#'){
		 c = st.top();
		st.pop();
		output += c;
	}
	return output;
}
int main(int argc, char const *argv[])
{
	string exp;
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>exp;
		cout<<infixToPostfix(exp)<<endl;
	}
	return 0;
}