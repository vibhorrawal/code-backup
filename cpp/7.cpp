#include<iostream>
#include<math.h>
using namespace std;
bool xorf(int n1, int n2, int k, int x);
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	int army[m+1 +1];

	for (int i = 0; i < m+1; ++i)
	{
		cin>>army[i+1];
	} 
	int count = 0;
	for (int i = 0; i < m; ++i)
	{
		//cout<<"loop: "<<i<<endl;
		if(xorf(army[i+1],army[m+1],k,n)){
			count++;
			//cout<<count<<endl;
		}
	}
	cout<<count;
}

bool xorf(int n1, int n2, int k, int x)
{
	int m = n1 ^ n2;
	int n[1000],count=0;
	for (int i = 0; i < 1000; ++i)
	{
		n[i] = m % 2;
		m = m / 2;
		if(n[i] == 1)
			count++;
	}

    if(count <= k)  
    	return true;
    else return false;	  

}

