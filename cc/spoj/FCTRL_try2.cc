// c code
#include<stdio.h>

int z_factorial(int num){
	int count5 = 0;
	int m;
	for (int i = 2; i <= num; ++i)
	{
		m = i;
		
		while(1){
		if((m / 5 != 0) && (m % 5 == 0)){
			count5++;
			m = m / 5;
		
		}
		else
		 break;
		}
	}

		return count5;
}
int main(int argc, char const *argv[])
{
	
	int n,k;
	// cin>>n;
	scanf("%d", &n);
	// cout<<mod(n,k);return 0;
	
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &k);
		// cout<<z_factorial(k)<<endl;
		printf("%d\n", z_factorial(k));
	}
	
	return 0;
}
