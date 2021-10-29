#include<cstdio>
#include<iostream>
#include<unistd.h>
const int MAXNM=20, MAXV=1e9-1;

int losuj(int a, int b){
	return (a+rand()%(b-a+1));
}

int main(int argc, char* argv[]){
	if(argc==1)srand(getpid());
	else srand(atoi(argv[1]));
		
	int n=losuj(1,MAXNM);
	printf("%d\n", n);
	
	for(int i=0;i<n;i++){
		printf("%d ", losuj(1,MAXV));
	}
}
