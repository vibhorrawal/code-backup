#include <bits/stdc++.h>
using namespace std;

class StringInput
{
public:
	char s[50];
	
};
int compareString(const void* a, const void* b){
	StringInput *s1 = (StringInput *)a, *s2 = (StringInput *)b;
	return strcmp(s1->s,s2->s);
}
int main(int argc, char const *argv[])
{
	int n; cin>>n; // no of inputs
	StringInput in[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>in[i].s;
		// scanf("%s",in[i].s);
	}

	qsort(in,n,sizeof(StringInput),compareString);
	for (int i = 0; i < n; ++i)
	{
		cout<<in[i].s<<endl;
	}
	return 0;
}