#include<bits/stdc++.h>
using namespace std;
void chartoint(char ca[], int ia[]){
	char c = ca[0];
	int i = 0;
	while(c != '\0'){
		ia[i++] = c - '0';
		c = ca[i];
	}
}
void add(int res[], int a[], int b[]){
	// char res[101] = {0};
	int temp, carry;
	for (int i = 0; i < 100; ++i)
	{
		temp = a[i] + b[i] + carry;
		res[i] = temp % 10;
		carry = temp / 10;
	}
	
}
void divideby2(int res[], int arr[]){
	int index = 100;
	int n;
	while(1)
		index--;

	n = arr[index];
	while(index >= 0){
		
		if(n < 2){
			n = n*10 + arr[--index];
		}

		res[index] = n / 2;
		if(n & 1) //odd
			arr[index-1] += 1;
	index--;
	if(index == -1)
		break;
	n = arr[index];		
	}
}
void subtract(int res[], int a[], int b[]){
	int d, c = 0;
	for (int i = 0; i < 100; ++i)
	{
		d = a[i] - c - b[i];
		if(d < 0){
			d += 10;
			c = 1;
		}
		res[i] = d;
	}
}
void countApples(char t[], char d[]){
	/* 	x + y = total
		x - y = diff
		2x = total + diff
		2y = total - diff
	*/
	cout<<"here";
	int total[101] = {0};
	int diff[101] = {0};
	int temp[101] = {0};
	chartoint(t,total);
	chartoint(d,diff);

	int tpd[101] = {0};
	int tmd[101] = {0};
	add(tpd, total, diff);
	subtract(tmd, total, diff);

	int x[101] = {0};
	int y[101] = {0};

	divideby2(x,tpd);
	divideby2(y,tmd);

	int i = 100, j = 100;
	while(!x[i])
		i--;
	while(!y[j])
		j--;
	while(i>=0)
		cout<<x[i--];
	cout<<endl;
	while(j>=0)
		cout<<y[j--];
	cout<<endl;
}
int main(int argc, char const *argv[])
{
	char t[101];
	char d[101];
	for (int i = 0; i < 10; ++i)
	{
		// scanf("%c", t);
		// scanf("%c", d);
		// cin.getline(t, 100);
		// cin.getline(d, 100);
		cin>>t;
		cin>>d;
		cout<<"called";
		countApples(t,d);
	}
	return 0;
}