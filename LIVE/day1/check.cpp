#include<cstdio>
long long n, tab[500005],licz;

int main(){

	scanf("%lld", &n);
	for(int i=0;i<n;i++){
		scanf("%lld", &tab[i]);
	}
	for(int i=0;i<n;i++){
		long long x;
		scanf("%lld", &x);
		licz=0;
		for(int j=0;j<n;j++){
			if(x==0)break;
			if(tab[j] <= x)x-=tab[j],licz++;
		}
		if(licz>i+1){
			printf("failed on %d, backpack %lld too big\n", i+1,licz-i-1);
			return 1;
		}
		if(licz<i+1){
			printf("failed on %d, backpack %lld too small\n", i+1,i+1-licz);
			return 1;
		}
	}
	return 0;
}
