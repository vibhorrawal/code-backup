#include<iostream>
using namespace std;
void lcs(char* x, char* y);
int len(char* c){
	int i;
	for ( i = 0; ; ++i)
	{
		if(c[i] == '\0')
			break;
	}
	return i;
}
int main(int argc, char const *argv[])
{
	char x[50];
	char y[50];
	scanf("%s",x);
	scanf("%s",y);
	lcs(x,y);
	return 0;
}
void lcs(char* x, char* y){
	int M = len(x)+1;
	int N = len(y)+1;
	
	char sign[N][M] = {0};
	int weight[N][M] = {0};
	for (int i = 1; i < N; ++i)
	{
		for (int j = 1; j < M; ++j)
		{
			if(x[j-1] == y[i-1])				
				sign[i][j] = 'd',weight[i][j] = weight[i-1][j-1] + 1;
			
			else if(weight[i-1][j] < weight[i][j-1])				
				weight[i][j] = weight[i][j-1], sign[i][j] = 'u';
			
			else	
				weight[i][j] = weight[i-1][j], sign[i][j] = 'l';
			
			
		}
	}
	// print(sign,weight,M,N);
	int i = N - 1, j = M - 1;
	int k = 0;
	char res[N];
	while(i > 0 && j > 0){
		if(sign[i][j] == 'd'){
			res[k++] = y[i-1];
			i--,j--;
		}
		else if(sign[i][j] == 'l')
			i--;
		else
			j--;		
	}
	k--;
	while(k >= 0)
		cout<<res[k--];
}