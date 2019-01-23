#include <iostream>

int main(){
	int n[16], m;
	cin>>m;

	for (int i = 0; i < 16; ++i)
	{
		n[i] = m % 2;
		m = m / 2;
	}

	for (int i = 0; i < 16; ++i)
	{
		cout<<n[i];
	}
}