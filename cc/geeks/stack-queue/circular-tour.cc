// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

int tour(petrolPump [],int );

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        cout<<tour(p,n)<<endl;
    }
}
// } Driver Code Ends


/*
The structure of petrolPump is
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
int tour(petrolPump p[],int n)
{
   //Your code here
   int start = 0;
   int end = start + 1;
   int energy = p[0].petrol - p[0].distance;
   while(end != start || energy < 0){
     while(energy < 0 && start != end){
       energy -= p[start].petrol - p[start].distance;
       start = (start + 1) % n;
       if(start == 0)
          return -1;
     }
     energy += p[end].petrol - p[end].distance;
     end = (end + 1) % n;
   }
   return start;
}
