// q1
/*This problem statement differs from that of Leapfrog Ch. 2 in only one spot, highlighted in bold below.

A colony of frogs peacefully resides in a pond. The colony is led by a single Alpha Frog, and also includes 0 or more Beta Frogs. In order to be a good leader, the Alpha Frog diligently studies the high art of fractions every day.

There are N lilypads in a row on the pond's surface, numbered 1 to N from left to right, each of which is large enough to fit at most one frog at a time. Today, the Alpha Frog finds itself on the leftmost lilypad, and must leap its way to the rightmost lilypad before it can begin its fractions practice.

The initial state of each lilypad i is described by a character Li, which is one of the following:

"A": Occupied by the Alpha Frog (it's guaranteed that Li = "A" if and only if i = 1)
"B": Occupied by a Beta Frog
".": Unoccupied
At each point in time, one of the following things may occur:

1) The Alpha Frog may leap over one or more lilypads immediately to its right which are occupied by Beta Frogs, and land on the next unoccupied lilypad past them, if such a lilypad exists. The Alpha Frog must leap over at least one Beta Frog; it may not just leap to an adjacent lilypad. Note that, unlike in Leapfrog Ch. 2, the Alpha Frog may only leap to its right.

2) Any Beta Frog may leap to the next lilypad to either its left or right, if such a lilypad exists and is unoccupied.

Assuming the frogs all cooperate, determine whether or not it's possible for the Alpha Frog to ever reach the rightmost lilypad and begin its daily fractions practice.

Input
Input begins with an integer T, the number of days on which the Alpha Frog studies fractions. For each day, there is a single line containing the length-N string L.

Output
For the ith day, print a line containing "Case #i: " followed by a single character: "Y" if the Alpha Frog can reach the rightmost lilypad, or "N" otherwise.

Constraints
1 ≤ T ≤ 500 
2 ≤ N ≤ 5,000 
Explanation of Sample
In the first case, the Alpha Frog can't leap anywhere.

In the second case, the Alpha Frog can leap over the Beta Frog to reach the rightmost lilypad.

In the third case, neither the Alpha Frog nor either of the Beta Frogs can leap anywhere.

In the fourth case, if the first Beta Frog leaps one lilypad to the left, and then the second Beta Frog also leaps one lilypad to the left, then the Alpha Frog can leap over both of them to reach the rightmost lilypad.*/
#include<bits/stdc++.h>
using namespace std;
int l;
char lilly[5000];

int find_empty_from(int pos){
	for (int i = pos; i < l; ++i)
	{
		if(lilly[i] == '.')
			return i;
	}
	return -1;
}
bool no_frog_in_between(int pos, int newpos){
	bool flag = true;
	for (int i = pos+1; i < newpos; ++i)
	{
		if(lilly[i] == 'B')
			flag = false;
	}
	return flag;
}
int re_adjust(int pos, int newpos){
	
}
char check(){
	l = 0;
	while(1){
		if(lilly[l++] == '\0')
			break;
	}
	l--;
	// cout<<l;
	// cout<<':'<<find_empty_from(1)<<':';
	int pos = 0;
	int newpos;// = find_empty_from(0);
	while(pos == l-1){
		newpos = find_empty_from(pos);
		if(newpos == -1 || no_frog_in_between(pos,newpos))
			newpos = re_adjust(pos,newpos);

		if(newpos == -1)
			return 'N';
	}

	return 'Y';
}
int main(int argc, char const *argv[])
{
	int k;
	cin>>k;
	for (int i = 0; i < k; ++i)
	{
		// char lilly[5000];
		cin>>lilly;
		// cout<<"Case #"<<i+1<<": "<<check()<<endl;
		cout<<no_frog_in_between(1,5);
	}
	return 0;
}
