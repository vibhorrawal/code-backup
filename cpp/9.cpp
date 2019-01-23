#include<iostream>
#include<math.h>
using namespace std;
int main()
{
int n,x;
cin>>n;
x = 0;
printf("You have %d items%s.\n", n, n==1 ? "" : "s");
cout<<x<<endl;exit(1);
n = n%4;
if(n == 0)
cout<<0;
if(n==1)
cout<<1;
if(n==2)
cout<<1;
if(n==3)
cout<<0;
return 0;
}