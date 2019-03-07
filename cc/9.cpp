#include<iostream>
#include<math.h>
using namespace std;
#include <ctime>
time_t t = time(NULL);
clock_t start = clock(); // start = clock();
void print_clock(){
	// fprintf(stderr, "------------------------------------------\n Clock ticks: %ld \t Time elapsed: %lds\n------------------------------------------\n\a", clock() - start, time(NULL) - t);
	fprintf(stderr, "----------------------------------------------------------------------------\n Clock ticks: %ld\t Time taken on CPU: %.3fs\t Time elapsed: %lds\n----------------------------------------------------------------------------\n\a", clock() - start, ((double)clock() - start)/ CLOCKS_PER_SEC, time(NULL) - t);
}
int main()
{
int n,x;
cin>>n;
x = 0;
printf("You have %d item%s.\n", n, n==1 ? "" : "s");
// cout<<x<<endl;exit(1);
n = n%4;
if(n == 0)
cout<<0;
if(n==1)
cout<<1;
if(n==2)
cout<<1;
if(n==3)
printf("1\n");

print_clock();
return 0;
}