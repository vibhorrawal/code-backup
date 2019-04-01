#include <stdio.h>
int main(int argc, char const *argv[])
{
	
	int i = 0, number = 0;
	while(argc-1 && argv[1][i] ){
		number = number * 10 + argv[1][i++] - '0';
	}
	printf("%d\n", number);
	return 0;
}