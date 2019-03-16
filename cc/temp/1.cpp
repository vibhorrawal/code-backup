#include<iostream>
#include<ctime>

using namespace std;
void delay(int number_of_seconds) 
{ 
    // Converting time into milli_seconds 
    int milli_seconds = 1000000 * number_of_seconds; // 6 zeroes
  
    // Stroing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not acheived 
    while (clock() < start_time + milli_seconds); 
} 
int main(){
	int n = 1000000001;
	// cout<<n;
	cout << "Print important information" << endl;
for (int i = 0; i < 2; i++)
{
  cout << "Processing file " << i << "\r" << flush;
  delay(1);
  // processing file
}
cout << endl; // Added to not overwrite the last status message.
cout<<"helloooooooooooooooooo\r"<<flush<<"ooooooooooooooo";
cout << "Print another important information" << endl;
}