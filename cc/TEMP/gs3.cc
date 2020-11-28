
int mini=0,minj=0;
int ss;
int mi=0;
mincost=0;
for(int i=0;i<N;i++)
{
  for(int j=0;j<M;j++)
  {
    if(costs[i][j]<costs[mini][minj])
    {
      mini=i;
      minj=j;
    }
  }
}
mincost=costs[mini][minj];
mi=mincost;
ss=costs[mini][minj];
for(int i=mini+1;i<N;i++)
{
  ss=ss+costs[i][minj];
  if(ss<mincost)
  {
    mincost=ss;
  }
}
if(mincost!=costs[mini][minj])
  mi+=mincost;
ss=costs[mini][minj];
for(int i=mini-1;i>=0;i--)
{
  ss=ss+costs[i][minj];
  if(ss<mincost)
  {
    mincost=ss;
  }
}
if(mincost!=costs[mini][minj])
  mi+=mincost;
ss=costs[mini][minj];
for(int i=minj+1;i<M;i++)
{
  ss=ss+costs[mini][i];
  if(ss<mincost)
  {
    mincost=ss;
  }
}
if(mincost!=costs[mini][minj])
  mi+=mincost;
ss=costs[mini][minj];
for(int i=minj-1;i>=0;i--)
{
  ss=ss+costs[i][minj];
  if(ss<mincost)
  {
    mincost=ss;
  }
}
if(mincost!=costs[mini][minj])
  mi+=mincost;
return mi;
