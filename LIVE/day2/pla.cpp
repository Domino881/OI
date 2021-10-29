//Dominik Kuczyński
//domino881@gmail.com sio2:KapitanDomo
//zadanie PLA - dzień drugi oi28
#include<cstdio>
#include<queue>
using namespace std;
long long n,X,z,tab[1000005],k;

inline int logg(long long x){
	int licz=0;
	while(x){x/=10;licz++;}
	return licz;
}

struct node{
	long long p,q,place;
	node(int p, int q, int place){
		this->p=p; this->q=q; this->place=place;
		while(this->q>1 && this->p%2==0 && this->place%2==0){
			this->q/=2; this->p/=2; this->place/=2;
		}
	}
};
struct comp{
	bool operator()(const node& x, const node& y){
		if(x.q > y.q){
			if(logg(x.p)+logg(x.q/y.q)<logg(y.p))return true;
			if(x.p*(x.q/y.q)==y.p)return x.place<y.place;
			return x.p*(x.q/y.q)<y.p;
		}
		if(y.q > x.q){
			if(logg(y.p)+logg(y.q/x.q)>logg(x.p))return true;
			if(y.p*(y.q/x.q)==x.p)return x.place<y.place;
			return y.p*(y.q/x.q)>x.p;
		}
		if(x.p==y.p)return x.place<y.place;
		return x.p<y.p;
	}
};
priority_queue<node, vector<node>, comp> Q;

int main(){

	scanf("%lld %lld %lld", &n, &X, &z);
	for(int i=0;i<n;i++){
		scanf("%lld", &tab[i]);
	}
	int start=0;
	for(int i=1;i<n;i++){
		start=tab[i-1];
		int gap = tab[i]-tab[i-1];
		Q.push(node(gap,1,start));
	}
	int prevk=0;
	while(z--){
		scanf("%lld", &k);
		k-=prevk;prevk=k-1;
		for(int i=0;i<k-1;i++){
			node best = Q.top();
			Q.pop();
			Q.push(node(best.p,best.q*2,best.place*2));
			Q.push(node(best.p,best.q*2,best.place*2+best.p));
		}
		node res = node(Q.top().p + Q.top().place*2, Q.top().q*2, 0);
		printf("%lld/%lld\n", res.p,res.q);
	}

}
