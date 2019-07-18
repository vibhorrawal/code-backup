// vector.cpp
// demonstrates push_back(), operator[], size()
#include <iostream>
#include <vector>
using namespace std;
int main()
{
vector<int> v;
//create a vector of ints
v.push_back(10);
v.push_back(11);
v.push_back(12);
v.push_back(13); //put values at end of array
v[0] = 20;
v[3] = 23; //replace with new values
for(int j=0; j<v.size(); j++)
cout << v[j] << ‘ ‘;
cout << endl;
return 0;
}
