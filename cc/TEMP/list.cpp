//list.cpp
//demonstrates push_front(), front(), pop_front()
#include <iostream>
#include <list>
using namespace std;
int main()
{
list<int> ilist;
ilist.push_back(30);
ilist.push_back(40); //push items on back
ilist.push_front(20);
ilist.push_front(10); //push items on front

int size = ilist.size(); //number of items
for(int j=0; j<size; j++)
{
cout << ilist.front() << ‘ ‘; //read item from front
ilist.pop_front();
}
cout << endl;
return 0;
}
