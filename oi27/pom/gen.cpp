#include<cstdio>
#include<iostream>
#include<unistd.h>
using namespace std;
const int MAXQ=50, MAXN=8;

int losuj(int a, int b){
	return a+rand()%(b-a+1);
}
void swap(long long &a, long long &b){
	long long x=a;
	a=b;
	b=x;
}

long long power(long long p, long long w){
	if(w==0)return 1;
	if(w%2==1)return power(p,w-1)*p;
	if(w%2==0)return power(p*p,w/2);
}

int main(){
	srand(getpid());

	int q = 100;//losuj(1,MAXQ);

	cout<<q<<"\n";
	while(q--){
		for(int i=0;i<100000;i++)printf("9");
		printf(" ");
		for(int i=0;i<100000;i++)printf("2");
		printf(" %d\n", 100-q);
		//unsigned l = losuj(1,MAXN);
		//long long a=0,b=0;
		//for(unsigned i=0;i<l;i++)
		//	a+=losuj(0,9)*power(10,i), b+=losuj(0,9)*power(10,i);
		//if(a<b)swap(a,b);
	//	string aa = to_string(a);
	//	string bb = to_string(b);
	//	while(aa.size()<l){
	//		aa='0'+aa;
	//	}
	//	while(bb.size()<l){
	//		bb='0'+bb;
	//	}
	//	cout<<aa<<" "<<bb<<" "<<losuj(0,l)<<"\n";
	}
}
