#include<bits/stdc++.h>
using namespace std;
#define LIMIT 100
void chartoint(char ca[], int ia[]){
	int i = 0, j = 0;
	while(ca[i] != '\0'){
		// ia[LIMIT -1 - i++] = c - '0';
		i++;
	}
	i--;
	while(i >= 0){
		ia[j] = ca[i] - '0';
		i--;
		j++;
	}
}
void add(int res[], int a[], int b[]){
	// char res[LIMIT] = {0};
	int temp, carry = 0;
	for (int i = 0; i < 100; ++i)
	{
		temp = a[i] + b[i] + carry;
		res[i] = temp % 10;
		carry = temp / 10;
	}
	
}
void divideby2(int res[], int arr[]){
	int index = 99;
	int n;
	while(!arr[index])
		index--;

	n = arr[index];
	// cout<<":"<<n<<':'<<index<<endl;
	while(index >= 0){
		
		if(n < 2){
			n = n*10 + arr[index-1];
			res[index] = 0;
			index--;
			continue;
		}
		else{
			res[index] = n / 2;
			if(n & 1) //odd
				arr[index-1] += 10;
			index--;
			n = arr[index];
			}

		if(index == -1)
			break;			
	}
}
void subtract(int res[], int a[], int b[]){
	int d, c = 0;
	for (int i = 0; i < 100; ++i)
	{
		// c = 0;
		d = a[i] - c - b[i];
		if(d < 0){
			d += 10;
			c = 1;
		}
		else
			c = 0;
		res[i] = d;
	}
}
void display(int* x){
	int i = 99;
	while(!x[i])
		i--;
	if(i < 0){
		cout<<0<<endl;
		return;
	}
	while(i>=0)
		cout<<x[i--];
	cout<<endl;
}
void check(int x[], int y[]){
	bool flag = false;
	for (int i = 1; i < 99; ++i)
	{
		if(x[i] != 0)
			flag = true;
		if(y[i] != 0)
			flag = true;
	}
	if(0 != y[0] || x[0] != 1)
		flag = true;
	if(flag)
		display(x),display(y);
}
void countApples(char t[], char d[]){
	/* 	x + y = total
		x - y = diff
		2x = total + diff
		2y = total - diff
	*/
	// cout<<"here";
	int total[LIMIT] = {0};
	int diff[LIMIT] = {0};
	int temp[LIMIT] = {0};
	chartoint(t,total);
	chartoint(d,diff);
	// cout<<"Total: "; display(total); cout<<"Diff :";display(diff);
	int tpd[LIMIT] = {0};
	int tmd[LIMIT] = {0};
	add(tpd, total, diff);
	subtract(tmd, total, diff);
	// cout<<"Addition: ";display(tpd); cout<<"Subtraction: ";display(tmd);
	int x[LIMIT] = {0};
	int y[LIMIT] = {0};

	divideby2(x,tpd);
	divideby2(y,tmd);
	// cout<<"Divby2 add:";display(x); cout<<"Divby2 sub:";display(y);
	// display(x);
	// display(y);
	check(x,y);	
}
int main(int argc, char const *argv[])
{
	char t[LIMIT];
	char d[LIMIT];
	for (int i = 0; i < INT_MAX - 1; ++i)
	{
		// scanf("%c", t);
		// scanf("%c", d);
		// cin.getline(t, 100);
		// cin.getline(d, 100);
		cin>>t;
		cin>>d;
		// cout<<"called";
		countApples(t,d);
		if(0 == INT_MAX % (INT_MAX/10))
			fprintf(stderr, "10 percent done\n");
	}
	
	// cin>>t;
	// // cin>>d;
	// // cout<<"called";
	// //countApples(t,d)
	// int x[LIMIT] = {0};
	// int y[LIMIT] = {0};
	// chartoint(t,x);
	// chartoint(d,y);
	// int res[LIMIT] = {0};
	// divideby2(res,x);
	// // for (int i = 99; i >= 0; --i)
	// // {
	// // 	cout<<x[i]<<' ';
	// // }cout<<endl;
	// display(res);
return 0;
}	