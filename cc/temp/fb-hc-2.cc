// q2 try 1
#include<bits/stdc++.h>
using namespace std;
int l;
char lilly[5000];
char check(){
	l = 0;
	while(1){
		if(lilly[l++] == '\0')
			break;
	}
	l--;
	int countB = 0, countdot = 0;
	for (int i = 1; i < l; ++i)
	{
		if(lilly[i] == 'B')
			countB++;
		else
			countdot++;
	}
	// cout<<countdot<<endl<<countB<<endl;
	if((countB > 1 && countdot) | (countdot == countB == 1)) 
		return 'Y';
	else
		return 'N';
}
int main(int argc, char const *argv[])
{
	int k;
	cin>>k;
	for (int i = 0; i < k; ++i)
	{
		cin>>lilly;
		cout<<"Case #"<<i+1<<": "<<check()<<endl;
	}
	return 0;
}