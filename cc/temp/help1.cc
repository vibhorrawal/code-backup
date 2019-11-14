#include<stdio.h>
#include<string.h>
#include "iostream"
const bool DEBUG = true;
using namespace std;
int main(){
	//Inputting the key and creating the matrix
	char key [25];
	int count[26]={0} , i = 0 , x ;
	int p,q;
	printf("ENTER KEY (in lower case):\n");
	scanf("%s" , key);
	//Counting the number of times each letter appears in key
	while(key[i] != '\0'){
	x = key[i] - 'a';
    count[x]++;
    i++;
	}
	// As i=j
	count[8] = count[8] + count[9];
	count[9]=count[8];
    i = 0,p=0,q=0;
    //Filling key in matrix minus duplicates
    char matrix[5][5];
     	while(p<=4){
	    	while(q<=4){
	    		if(key[i]=='\0'){
		    		break;
		    	}
	    		x = key[i]-'a';
	    		if(count[x]==1){
	    		matrix[p][q]=key[i];
	    		q++;}
	    		i++;
	    	}
	    	if(key[i]=='\0'){
	    		break;
	    	}
	    	q=0;
	    	p++;
	    }
	    //Filling rest of the letters alphabeticallly
			if(DEBUG){ cout << "key: " <<key<< endl; };
	    int y =97;
        while(p<=4){
        	while(q<=4){
	        	char u = y;
	        	x = u - 'a';
	        	if(count[x]!=1){
	        		matrix[p][q] = u;
					q++;
	        	}
	        	if(u == 'i'){
	        		y+=2;
	        	}
				else{
				y++;
				}

	        }
	        q=0;
	        p++;
        }
        p=0;
        q=0;
        //Printing the matrix
    while(p<=4){
    	while(q<=4){
	    	printf("%c",matrix[p][q]);
	    	printf("  ");
	    	q++;
	    }

	    p++;
	    q=0;
	    printf("\n");
    }
		if(DEBUG){ for (int i = 0; i < 5; i++) {
		  for (int j = 0; j < 5; j++) {
		    cout << " " << matrix[i][j];
		  }
			cout << endl;
		} };
    // Inputting the encrypted text
    i=0;
    p=0 ;
    q=0;
    int r=0;
    int s=0;
    char encrypted [1000] = {0};
    printf("ENTER ENCRYPTED TEXT(in lower case):\n");
    scanf("%s",encrypted);
    while(encrypted[i]!='\0'&& encrypted[i+1]!='\0'){
    	if(encrypted[i]=='\0'){
	    	i +=1;
	    	printf(" ");
	    }
			if(DEBUG){ cout << "message: "<<encrypted << endl; };
	    //No problems until now
	    //Finding letters of text in the matrix , two at a time
	    //Problems with some pairs
    	while(p<=4){

			while(q<=4){
				if(DEBUG){ cout << "p:" <<p<<":q "<<q<<"\n"; };

	    	if((int)(encrypted[i]) == (int)(matrix[p][q]) ){
	    		break;
	    	}
	    	q++;
	    }

    	if((int)(encrypted[i])== (int)(matrix[p][q])){
				if(DEBUG){ cout << "code went here lol" << endl; };
	    	break;
	    }
	    q=0;
			if(DEBUG){ cout << "code went here" << endl; };
    	p++;
    }

    	while(r<=4){

			while(s<=4){
	    	if((int)encrypted[i+1]==(int)matrix[r][s]){
	    		break;
	    	}
	    	s++;
	    }
    	if((int)encrypted[i+1]==(int)matrix[r][s]){
	    	break;
	    }
	    s=0;
    	r++;
    }
    printf("%d %d %d %d",p,q,r,s);
    //Decrypting
   if(p==r){
    	if(q==0){
	    	q=5;
	    }
    	printf("%c" , matrix[p][q-1]);
   		if(s==0){
	    	s=5;
	    }
    	printf("%c" , matrix[r][s-1]);
    }
  else if(q==s){
    	if(p==0){
	    	p=5;
	    }
    	printf("%c" , matrix[p-1][q]);
   		if(r==0){
	    	r=5;
	    }
    	printf("%c" , matrix[r-1][s]);
    }
    else{
    printf("%c", matrix[p][s]);
	printf("%c", matrix[r][q]);
    }

    i+=2;
    }




return 0 ;
}
