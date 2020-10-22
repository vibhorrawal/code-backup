
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <string>
#include <map>
#include <list>
#include <stack>
#include <set>
#include <deque>

using namespace std;

#define OUTPUT freopen("myfile.txt","w",stdout);
#define INPUT freopen("in.in","r",stdin);
#define DEBUG(a) cout<<a<<endl;
#define PI acos(-1.0)
#define MAX 100005
#define MOD 1000000007
#define EPS 1e-9
#define BIGGER(a,b) (a>=b ? a : b)
#define SMALLER(a,b) (a<=b ? a : b)
#define getInt(a) scanf("%d",&a);
#define getLong(a) scanf("%lld",&a);
#define pb push_back
#define ppb pop_back
#define setBit(a,n) a|(1<<n)
#define setBitStatement(a,n) a|=1<<n;
#define resetBit(a,n) a&=~(1<<n);
#define checkBit(a,n) ((a&(1<<n))!=0)
#define toggleBit(a,n) a^=1<<n;
#define doubleingEqual(a,b) (fabs(a-b)<=EPS)
#define doubleingLess(a,b) ((b-a)>=EPS)
#define doubleingGreater(a,b) ((a-b)>=EPS)

#define INF 1000000000

int S[100005];
int D[100005];
int N;

double fn(double timee)
{
    double minn,maxx,tmp;

    minn = S[0]*timee + D[0]*1.0;
    maxx = S[0]*timee + D[0]*1.0;

    for(int i=1;i<N;i++)
    {
        tmp = S[i]*timee + (double)D[i];

        if(tmp-maxx>EPS)
        {
            maxx = tmp;
        }

        else if(minn-tmp>EPS)
        {
            minn = tmp;
        }
    }

    return maxx - minn;
}

inline double p(double t, int i){
  return S[i] * t + D[i];
}
double f(double t){
  double maxp = -1e9, minp = 1e9;
  for (int i = 0; i < N; i++) {
    double pi = p(t, i);
    maxp = max(pi, maxp);
    minp = min(pi, minp);
  }
  return maxp - minp;
}

double TernarySearch(double K)
{
    double l = 0.0;
    double r = K ;
    double m1,m2;
    double fn1,fn2;

    for(int iter=0;iter<200;iter++)
    {

        m1 = l + (r-l)/3.0;
        m2 = r - (r-l)/3.0;

        fn1 = fn(m1);
        fn2 = fn(m2);

        if(fn1>fn2)
        {
            l = m1 ;
        }

        else
        {
            r = m2;
        }

    }

    return SMALLER(fn(l),fn(r));
}

int main()
{
    // Bismillahir Rahmanir Rahim
    // Rabbi Zidni Ilma

    int i,k;
    double K;

    getInt(N)
    scanf("%d",&k);

    K = k*1.0;

    for(i=0;i<N;i++)
    {
        scanf("%d",&S[i]);
        scanf("%d",&D[i]);
    }
    printf("%lf\n",TernarySearch(K));
    // printf("%lf\n",ternary_search(0,K));

    return 0;
}
