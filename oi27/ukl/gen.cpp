#include<cstdio>
#include<iostream>
#include<unistd.h>
const int MAXNM=500;

int losuj(int a, int b){
	return (a+rand()%(b-a+1));
}

int main(){
	srand(getpid());
		
	int n=losuj(1,MAXNM), m=losuj(1,MAXNM);

	int k = n*m-1;//losuj(n, n*m+n);
	printf("%d %d %d", n,m,k);
	
}
