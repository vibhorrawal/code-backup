#include<bits/stdc++.h>
using namespace std;
void progression(int a, int b, int c){
	//if AP
	if(b-a == c-b)
		cout<<"AP "<<2*c-b<<endl;
	else // GP
		cout<<"GP "<<1.0*c/b*c<<endl;
}
int main(int argc, char const *argv[])
{
	int a,b,c = 1;
	while(1){
		cin>>a>>b>>c;
		// cout<<"here"<<a<<b<<c;
		if(b == 0 && a == 0 && c == 0) return 0;
		progression(a,b,c);
		// cout<<"low";
	}
	return 0;
}