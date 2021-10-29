#include<vector>
#include<utility>
#include<bitset>
#define pb push_back
using namespace std;
int n,m,z,licz;
vector<int> nbrs[100005];
vector<vector<int> > updates;
const int MAXN=100005, MAXM=150005, MAXM_FAST=10000;
int dad[MAXN], depth[MAXN], subtr[MAXN], heavy[MAXN],
	path[MAXN], num[MAXN];

inline void sswap(int &a, int &b){
	int tmp=a;
	a=b;
	b=tmp;
}
inline int mini(int a, int b){return a<b?a:b;}
inline int maks(int a, int b){return a>b?a:b;}

void print_bs(bitset<MAXM> x){
	for(int i=0;i<MAXM;i++)printf("%d", !!x[i]);
	printf("\n");
}

void dfs1(int v){
	for(int w : nbrs[v]){
		if(w!=dad[v]){
			dad[w] = v;
			depth[w]=depth[v]+1;

			dfs1(w);
			subtr[v]+=subtr[w];
			if(!heavy[v] || subtr[w]>subtr[heavy[v]])
				heavy[v]=w;
		}
	}
	subtr[v]++;
}

void dfs2(int v, int pathnum){
	path[v]=pathnum;
	num[v]=++licz;

	if(heavy[v])
		dfs2(heavy[v], pathnum);
	for(int w : nbrs[v]){
		if(w != heavy[v] && w != dad[v])
			dfs2(w,w);
	}
}

struct Sqrt{
	const static int SQRT=316;
	int tab[MAXN];
	bool faster=0;
	bitset<MAXM> bin_slow[SQRT+2];
	bitset<MAXM_FAST> bin_fast[SQRT+2];

	void update(int idx, int val){
		if(faster)update_fast(idx,val);
		else update_slow(idx,val);
	}
	void update_slow(int idx, int val){
		if(!tab[idx] || tab[idx]==val){tab[idx]=val; return;}
		tab[idx]=val;
		bin_slow[idx/SQRT]=bitset<MAXM>(0);
		for(int i=(idx/SQRT)*SQRT;i<(idx/SQRT+1)*SQRT;i++){
			if(tab[i])bin_slow[idx/SQRT][tab[i]]=1;
		}
	}
	void update_fast(int idx, int val){
		if(!tab[idx] || tab[idx]==val){tab[idx]=val; return;}
		tab[idx]=val;
		bin_fast[idx/SQRT]=bitset<MAXM_FAST>(0);
		for(int i=(idx/SQRT)*SQRT;i<(idx/SQRT+1)*SQRT;i++){
			if(tab[i])bin_fast[idx/SQRT][tab[i]]=1;
		}
	}

	bitset<MAXM> query_slow(int l, int r){
		if(r<l)sswap(l,r);
		bitset<MAXM> res(0);
		for(int i=l;i<mini(r+1,(l/SQRT+1)*SQRT);i++){
			if(tab[i])res[tab[i]]=1;
		}
		for(int i=l/SQRT+1;i<r/SQRT;i++){
			if(bin_slow[i]==0)continue;
			res|=bin_slow[i];
		}
		for(int i=maks(l,(r/SQRT)*SQRT);i<=r;i++){
			if(tab[i])res[tab[i]]=1;
		}
		return res;
	}
	bitset<MAXM_FAST> query_fast(int l, int r){
		if(r<l)sswap(l,r);
		bitset<MAXM_FAST> res(0);
		for(int i=l;i<mini(r+1,(l/SQRT+1)*SQRT);i++){
			if(tab[i])res[tab[i]]=1;
		}
		for(int i=l/SQRT+1;i<r/SQRT;i++){
			if(bin_fast[i]==0)continue;
			res|=bin_fast[i];
		}
		for(int i=maks(l,(r/SQRT)*SQRT);i<=r;i++){
			if(tab[i])res[tab[i]]=1;
		}
		return res;
	}
}Sqrt;

bitset<MAXM_FAST> hldquery_fast(int d, int s){
	if(d==s)return 0;
	if(depth[path[d]]<depth[path[s]])
		sswap(d,s);

	if(path[d]==path[s]){
		if(depth[d]<depth[s])
			sswap(d,s);
		return Sqrt.query_fast(num[d],num[s]+1);
	}

	int x = path[d];
	bitset<MAXM_FAST> res(0);
	if(x!=d){
		res|=Sqrt.query_fast(num[d],num[x]+1);
	}
	res|=Sqrt.query_fast(num[x],num[x]); 
	return res|hldquery_fast(dad[x], s);
}
bitset<MAXM> hldquery_slow(int d, int s){
	if(d==s)return 0;
	if(depth[path[d]]<depth[path[s]])
		sswap(d,s);

	if(path[d]==path[s]){
		if(depth[d]<depth[s])
			sswap(d,s);
		return Sqrt.query_slow(num[d],num[s]+1);
	}

	int x = path[d];
	bitset<MAXM> res(0);
	if(x!=d){
		res|=Sqrt.query_slow(num[d],num[x]+1);
	}
	res|=Sqrt.query_slow(num[x],num[x]); 
	return res|hldquery_slow(dad[x], s);
}


int main(){

	scanf("%d %d %d", &n,&m,&z);
	if(m<MAXM_FAST)Sqrt.faster=1;

	for(int i=0;i<n-1;i++){
		int a,b,c; scanf("%d %d %d", &a, &b, &c);
		updates.push_back({a,b,c});
		nbrs[a].pb(b);
		nbrs[b].pb(a);
	}
	dfs1(1); dfs2(1,1);
	for(auto x : updates){
		if(depth[x[0]]<depth[x[1]])sswap(x[0],x[1]);
		if(Sqrt.faster)
			Sqrt.bin_fast[num[x[0]]/Sqrt.SQRT][x[2]]=1;
		else
			Sqrt.bin_slow[num[x[0]]/Sqrt.SQRT][x[2]]=1;
		Sqrt.tab[num[x[0]]]=x[2];
	}
	if(n>2000 || z>2000){
		while(z--){
			char op; scanf("\n%c",&op);

			if(op=='Z'){
				int x; scanf("%d", &x);
				if(Sqrt.faster){
					bitset<MAXM_FAST> res=hldquery_fast(1, x);
					res[0]=0; 
					printf("%lu\n", res.count());
				}
				else{
					bitset<MAXM> res=hldquery_slow(1, x);
					res[0]=0; 
					printf("%lu\n", res.count());
				}
			}
			else{
				int i,c; scanf("%d %d", &i, &c);
				int a=updates[i-1][0], b=updates[i-1][1];
				if(depth[a]<depth[b])sswap(a,b);
				Sqrt.update(num[a], c);
			}
		}
	}
	else{
		while(z--){
			char op; scanf("\n%c",&op);
			if(op=='Z'){
				bitset<MAXM> res(0);
				int x; scanf("%d", &x);
				while(x!=dad[x]){res[Sqrt.tab[num[x]]]=1;x=dad[x];}
				res[0]=0;
				printf("%lu\n", res.count());
			}
			else{
				int i,c; scanf("%d %d", &i, &c);
				int a=updates[i-1][0], b=updates[i-1][1];
				if(depth[a]<depth[b])sswap(a,b);
				Sqrt.update(num[a], c);
			}
		}
	}
}

