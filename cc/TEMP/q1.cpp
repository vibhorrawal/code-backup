#include<iostream>
#include<fstream>
using namespace std;

void finfichero(int n, string name)

{	string a;
    int i=0;
    ifstream ifs;
    ifs.open(name);
    
    while(true)
    { 
        if(ifs)
        {
            getline(ifs, a);
            i++;
        }
        else
            break;
    }
    i=i-1;
    ifs.close();
    ifs.open(name);
    for(int j=0;j<i;j++)
    {
    	getline(ifs, a);
        if(j>=i-n)
        {
            cout<<a<<"\n";
        }
    }
}

int main()
{
	string a;
	int n;
	
	cout<<"Enter name of the file: ";
	cin>>a;
	
	cout<<"Enter n: ";
	cin>>n;
	
    finfichero(n,a);
    return 0;
}	