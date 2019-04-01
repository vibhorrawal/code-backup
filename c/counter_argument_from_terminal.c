#include <stdio.h>
int main(int argc, char const *argv[])
{
	
	int i = 0, number = 0;
	while(argc-1 && argv[1][i] ){
		number = number * 10 + argv[1][i++] - '0';
	}
	for (int i = 0; i < number; ++i)
	{
		printf("%d\n", i+1);
	}
	return 0;
}