/*Problem

The decimal numeral system is composed of ten digits, which we represent as "0123456789" (the digits in a system are written from lowest to highest). Imagine you have discovered an alien numeral system composed of some number of digits, which may or may not be the same as those used in decimal. For example, if the alien numeral system were represented as "oF8", then the numbers one through ten would be (F, 8, Fo, FF, F8, 8o, 8F, 88, Foo, FoF). We would like to be able to work with numbers in arbitrary alien systems. More generally, we want to be able to convert an arbitrary number that's written in one alien system into a second alien system.

Input

The first line of input gives the number of cases, N. N test cases follow. Each case is a line formatted as

alien_number source_language target_language
Each language will be represented by a list of its digits, ordered from lowest to highest value. No digit will be repeated in any representation, all digits in the alien number will be present in the source language, and the first digit of the alien number will not be the lowest valued digit of the source language (in other words, the alien numbers have no leading zeroes). Each digit will either be a number 0-9, an uppercase or lowercase letter, or one of the following symbols !"#$%&'()*+,-./:;<=>?@[\]^_`{|}~

Output

For each test case, output one line containing "Case #x: " followed by the alien number translated from the source language to the target language.

Limits

1 ≤ N ≤ 100.

Small dataset

1 ≤ num digits in alien_number ≤ 4,
2 ≤ num digits in source_language ≤ 16,
2 ≤ num digits in target_language ≤ 16.

Large dataset

1 ≤ alien_number (in decimal) ≤ 1000000000,
2 ≤ num digits in source_language ≤ 94,
2 ≤ num digits in target_language ≤ 94.

Sample


Input:
4
9 0123456789 oF8 		
Foo oF8 0123456789
13 0123456789abcdef 01
CODE O!CDE? A?JM!.

OUTPUT:
Case #1: Foo
Case #2: 9
Case #3: 10011
Case #4: JAM!
*/
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000

int val(char c){
	c = toupper(c);
if(c >= '0' && c <= '9')
	return (int)c - '0';
else
	return (int)c - 'A' + 10;
}

int toDeci(char *str, int base){
	int len = strlen(str);
	int num = 0;
	int power = 1;

	for (int i = len - 1; i >= 0; --i)
	{
		// if(val(str[i]) >= base){
		// 	cout<<"Invalid Request"<<endl;
		// 	return -1;
		// }

		num += (str[i]) * power;
		power *= base;
	}
	return num;
}
void convert(char newString[], char str[], char source_lang[]){
	int len = strlen(str);
	for (int i = 0; i < len; ++i)
	{
		for(int j = 0; strlen(source_lang); j++){
			if(str[i] == source_lang[j]){
				newString[i] = j;
				break;
			}
		}
	}
	newString[len] = '\0';
}
char reVal(int num){
	 if (num >= 0 && num <= 9) 
        return (char)(num + '0'); 
    else
        return (char)(num - 10 + 'A'); 
}
void strev(char *str) 
{ 
    int len = strlen(str); 
    int i; 
    char temp;
    for (i = 0; i < len/2; i++) 
    { 
        temp = str[i]; 
        str[i] = str[len-i-1]; 
        str[len-i-1] = temp; 
    } 
} 
void fromDeci(char res[], int base, int num){
	int index = 0;
	while(num>0){
		res[index++] = (num % base);
		num /= base;
	}
	res[index] = '\0';
	strev(res);
}
void convertBack(char result[], char str[], char target_lang[]){
	int len = strlen(str);
	int val;
	char ch[2] = {'a','\0'};
	for (int i = 0; i < len; ++i)
	{
		val = str[i];
		// val = toDeci(ch,len);
		result[i] = target_lang[val];
	}
	result[len] = '\0';
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		char source_lang[MAX];
		char target_lang[MAX];
		char str[MAX];
		char newString[MAX];
		char res[MAX];
		char result[MAX];

		cin>>str>>source_lang>>target_lang;
		int base = strlen(source_lang);
		convert(newString, str, source_lang);

		fromDeci(res,strlen(target_lang), toDeci(newString,base));
		 cout<<res;
		convertBack(result, res, target_lang);
		cout<<"Case #"<<i+1<<": "<<result<<endl;
	}
	return 0;
}