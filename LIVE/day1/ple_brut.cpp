//Dominik Kuczyński
//domino881@gmail.com sio2:KapitanDomo
//zadanie PLE - dzień pierwszy oi28
#include<cstdio>
int n;
long long tab[300],best[400],suma,minn=1e10;

inline long long mini(long long a, long long b){
	return a<b?a:b;
}

bool check(long long x, long long l){
	long long licz=0;
	for(int i=0;i<n;i++){
		if(x==0)break;
		if(tab[i]<=x){x-=tab[i];licz++;}
	}
	return l==licz;
}


int main(){

	scanf("%d", &n); 
	for(int i=0;i<40;i++){
		best[i]=1e18-55;
	}
	for(int i=0;i<n;i++){
		scanf("%lld", &tab[i]);
		suma+=tab[i];
		minn=mini(minn,tab[i]);
	}
	if(n>22){
		for(int i=1;i<=n;i++){
			long long l=minn, r=suma;
			while(l+1<r){
				long long mid = (l+r)/2;
				if(check(mid, i))r=mid;
				else l=mid;
			}
			printf("%lld ", r);
		}
		return 0;
	}
	for(int maska=0;maska<(1<<21);maska++){
		long long licz=0, res=0;
		for(int i=0;i<=20;i++){
			if(tab[i] && 1<<i & maska){
				licz++; res+=tab[i];
			}
		}
		long long x=res,l=0;
		for(int i=0;i<n;i++){
			if(x==0)break;
			if(tab[i]<=x){x-=tab[i]; l++;}
		}
		if(l==licz)best[licz]=mini(best[licz],res);
	}
	for(int i=0;i<n;i++)printf("%lld ", best[i+1]);

}
