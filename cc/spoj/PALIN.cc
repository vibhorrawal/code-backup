#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;
#define MAX 1000000

bool isPalindrome(string n){
	int len = n.length();
	bool flag = true;
	int start = 0;
	while(n[start++] == '0');start--;
	for (int i = start; i < len; ++i){
		if(n[i] != n[len - 1 - i]){
			flag = false;
			break;
		}
		// cout<<n[i];
	}
	return flag;	
	
}
string decrement(string n)
{
	int len = n.length();
	char digit;
	int carry = 0, i = len -1;
	do{
		digit = n[i];
		if(digit == '0'){
				n[i] = '9';
				carry = 1;
		}
		else{
			n[i] = n[i] - 1;
			carry = 0;
		}
	i--;	
	}while(carry);
	return n;
}
string increment(string n){
	int i = n.length()-1;
	int carry = 0;
	// if()
	n[i] += 1;
	do{
		n[i] += carry; 
		if(n[i] > '9'){
			n[i] = '0';
			carry = 1;
			if(!i){
				n = '1' + n;
				break;
			}
		}
		else 
			carry = 0;
		i--;
	}while(carry);
	return n;
}
string add(string a, string b){
	string res = a;
	int ia = a.length()-1;
	int ib = b.length()-1;
	int carry = 0, temp = 0, ir = ia;
	while(1){
		if(ib >= 0){
			temp = (a[ia] - '0') + (b[ib] - '0') + carry;
			if(temp/10){
				temp %= 10;
				carry = 1;
			}else carry = 0;

		}
		else{
			temp = (a[ia] - '0') + carry;
			if(temp/10){
				temp %= 10;
				carry = 1;
			}else carry = 0;	
		}
		if(ia)
			res[ir] = temp + '0';
		else{
			if(res[0] == '9'){
				res = to_string(carry) + res;
				res[1] = '0';
				break;
			}
			else
				res[0] += carry;
				break;
		}
		if((ib < 0 && (res[ir] == a[ia]) && !carry) || ir < 0)
			break;
		ia--,ib--,ir--;
	}
	return res;
}
void display(string n){
	int len = n.length();
	int start = 0;
	while(n[start++] == '0');start--;
	for (int i = start; i < len; ++i)
		cout<<n[i];

	if(start == len)
		cout<<n[len];
	cout<<endl;	
}
int check(string n){
	int len = n.length();
	if(len <= 2) return 1;
	int start = 0;
	while(n[start++] == '0');start--;
	int upper = n[start] - '0' , lower = n[len-1] - '0';
	if(upper > lower)
		return upper - lower;
	else if(upper == lower)
		return 10;
	else
		return (10 - lower + upper);
}
void findPalindrome(string n){
	string temp;
	n =	increment(n);
	while(1){
		// cout<<':';display(n);

		if(isPalindrome(n)){
			display(n);
			return;
		}
		else
		{
			int k =	check(n);
			n = add(n, to_string(k));
			// cout<<'#'<<k<<endl;
			// while(k--)
			// 	n = increment(n);
		}
	}
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	string k;
	// cin>>k;
	// cout<<add(k, to_string(n));
	// isPalindrome(k);
	while(n--){
		cin>>k;
		// k = increment(k);cout<<k<<endl;
		// cout<<check(k)<<endl;
		findPalindrome(k);
	}
	return 0;
}