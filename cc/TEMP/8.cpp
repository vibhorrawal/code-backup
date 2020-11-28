#include<iostream>
using namespace std;
void NO()
{
	cout<<"NO";
	exit(1);
}

int main(){
	int n,k,count,j2,j3,step = 1,flag = 0;
	cin>>n>>k;
	j2 = n;
	j3 = k;
	int a[n];
	int color[5001][k];
	int s[n];

	cout<<"\nStep1 : "<<n<<k<<"\n";
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}

	cout<<"\nStep2 : "<<n<<k<<"\n";
	for (int i = 0; i < 5001; ++i)
	{
		for (int j = 0; i < k; ++j)
		{
			color[i][j] = 0;
		}
	}
	n = j2;
	k = j3;
	cout<<"\nStep3 : "<<n<<k<<"\n";
	for (int i = 0; i < n; ++i)
	{	
		cout<<"\nStep 4: "<<k<<"\n";
		if(i<k){
			//color[a[i]] = i+1;
			color[a[i]][i+1] = 1;
			s[i] = i+1;
		}
		else{	
			for (int j = 0; j < k; ++j)
			{
				j2 = j;
				if(color[a[i]][j] == 0)
				{
					color[a[i]][j] = 1;
					s[i] = j;
					break;
				}	
					
			}
		
		if(j2 == k)
			NO();
			}
	}
		
	cout<<"YES\n";

	for (int i = 0; i < n; ++i)
		{
			// count = a[i];
			cout<<s[i]<<' ';
		}
		
	
return 0;
}

