#include<iostream>
#include<string>
using namespace std;

class TimeFormatMistake
{

};

string time(string a)
{
	string timestring=a;
	
	int i = timestring.find(':');
	int hrs = stoi(timestring.substr(0,i));
	int mins = stoi(timestring.substr(i+1));
	
	if( i!=2 || mins>60 || mins<0 || hrs<0 || hrs>24 )
	{
		throw TimeFormatMistake();
	}
	
	if(hrs>12)
	{
		hrs-=12;
		timestring=to_string(hrs)+":"+to_string(mins)+" pm";
	}
	else
	{
		timestring=a+" am";
	}
	return timestring;
}



int main()
{
	string a;
	char opt='y';
	
	while(opt=='y'||opt=='Y')
	{
		try
		{
			cout<<"Enter time in 24-hour notation: ";
			cin>>a;
			
			string t = time(a);
			cout<<"That is the same as "<<t<<endl;
			
			cout<<"Again?(y/n): ";
			cin>>opt;
		}
		catch(TimeFormatMistake)
		{
			cout<<"There is no such time as "<<a<<endl;
			cout<<"Try Again:"<<endl;
		}
    }
    
    return 0;
}