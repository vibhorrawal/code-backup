#include<stdio.h>

int main()
{
    int T,N,i,j,l,index,m,K,largest,count,o;
    count=0;
    int sumsq,sum;
    scanf("%d",&T);
    while(T)
    {
        scanf("%d %d",&N,&K);
        int arr[N],array[N];

        for(i=0;i<N;i++)
        {
            scanf("%d",&arr[i]);
        }
        for(o=0;o<N;o++)
        {
            array[o]=arr[o];
        }

        for(j=0;j<K;j++)
        {
            largest = arr[0];

            for(l=1;l<N;l++)
            {
                if (largest < arr[l])
                largest = arr[l];
                index=l;
                array[index]=1;

            }
            sumsq=sum=0;
            for(m=0;m<N;m++)
            {

                sumsq=sumsq+(array[m]*array[m]);
                sum=sum+array[m];
            }
            if(sumsq<=sum)
            {
                count ++ ;
            }



        }
        if(count>0)
        {
            printf("YES");

        }
        else
            printf("NO");

        T-- ;
    }

}