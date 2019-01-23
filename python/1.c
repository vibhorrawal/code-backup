#include <stdio.h>

int main(void) {
    int T,N,i,j,k,sum=0;
    scanf("%d",&T);
    while(T)
    {
        scanf("%d",&N);
        int A[N];
        for(k=0;k<N;k++)
        {
            scanf("%d",&A[k]);
        }
        sum=1+A[1];
        for(i=2;i<=N;i++)
        {
            if(sum>=N)
                break;
            for(j=1;j<=sum;j++)
            {
                sum=sum+A[j];

            }

        }
        printf("%d",i-1);
       T--;
    }


	return 0;
}