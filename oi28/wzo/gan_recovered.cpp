#include<vector>
#include<utility>
#include<bitset>
#define pb push_back
using namespace std;
int n,m,z,licz;
vector<int> nbrs[100005];
vector<vector<int> > updates;
const int MAXN=100005, MAXZ=15;//0005;
int dad[MAXN], depth[MAXN], subtr[MAXN], heavy[MAXN],
	path[MAXN], num[MAXN];

inline void sswap(int &a, int &b){
	int tmp=a;
	a=b;
	b=tmp;
}
inline int mini(int a, int b){return a>b?a:b;}
inline int maks(int a, int b){return a<b?a:b;}

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
	const static int SQRT=3;
	int tab[MAXZ];
	bitset<MAXZ> bin[SQRT+2];

	void update(int l, int r, int val){
		//printf("[%d,%d]: %d -> %d  %d -> %d  %d -> %d\n",
				//l,r,l,(l/SQRT+1)*SQRT,l/SQRT+1,r/SQRT,(r/SQRT)*SQRT,r);
		for(int i=l;i<mini(r,(l/SQRT+1)*SQRT);i++){
			tab[i]=val;
		}
		for(int i=(l/SQRT)*SQRT;i<(l/SQRT+1)*SQRT;i++){
			if(tab[i])bin[l/SQRT][tab[i]]=1;
		}

		for(int i=l/SQRT+1;i<r/SQRT;i++){
			bin[i][val]=1;
		}

		for(int i=(r/SQRT)*SQRT;i<=r;i++){
			tab[i]=val;
		}
		for(int i=maks(l,(r/SQRT)*SQRT);i<(r/SQRT+1)*SQRT;i++){
			if(tab[i])bin[l/SQRT][tab[i]]=1;
		}
	}
	bitset<MAXZ> query(int l, int r){
		bitset<MAXZ> res(0);
		for(int i=l;i<mini(r,(l/SQRT+1)*SQRT);i++){
			if(tab[i])res[tab[i]]=1;
			printf(".");
		}
		for(int i=l/SQRT+1;i<r/SQRT;i++){
			res|=bin[i];
			printf(".");
		}
		for(int i=maks(l,(r/SQRT)*SQRT);i<=r;i++){
			if(tab[i])res[tab[i]]=1;
			printf(".");
		}
		return res;
	}
}Sqrt;

void hldupdate(int d, int s, int val){
	printf("[%d%d]",d,s);
	if(d==s)return;
	if(depth[path[d]]<depth[path[s]])
		sswap(s,d);

	if(path[d]==path[s]){
		if(depth[d]<depth[s])
			sswap(d,s);
		Sqrt.update(num[d], num[s]+1, val);
		return;
	}

	int x = path[d];
	if(x!=d)Sqrt.update(num[d], num[x]+1, val);
	Sqrt.update(num[x],num[x],val);
	hldupdate(dad[x],s,val);
}

bitset<MAXZ> hldquery(int d, int s){
	if(d==s)return 0;
	if(depth[path[d]]<depth[path[s]])
		sswap(d,s);

	if(path[d]==path[s]){
		if(depth[d]<depth[s])
			sswap(d,s);
		return Sqrt.query(num[d],num[s]+1);
	}

	int x = path[d];
	bitset<MAXZ> res(0);
	if(x!=d)res|=Sqrt.query(num[d],num[x]+1);
	res|=Sqrt.query(num[x],num[x]);
	return res|hldquery(dad[x], s);
}

int main(){

	scanf("%d %d %d", &n,&m,&z);
	for(int i=0;i<n-1;i++){
		int a,b,c; scanf("%d %d %d", &a, &b, &c);
		updates.push_back({a,b,c});
		nbrs[a].pb(b);
		nbrs[b].pb(a);
	}
	dfs1(1); dfs2(1,1);
	printf("done");
	for(auto x : updates){hldupdate(x[0],x[1],x[2]);}
	
	while(z--){
		char op; scanf("\n%c",&op);
		if(op=='Z'){
			int x; scanf("%d", &x);
			bitset<MAXZ> res=hldquery(1, x);
			res[0]=0; printf("%lu\n", res.count());
		}
		else{
			int i,c; scanf("%d %d", &i, &c);
			int a=updates[i-1][0], b=updates[i-1][1];
			if(depth[a]>depth[b])sswap(a,b);
			hldupdate(num[a], num[a], c);
		}
	}
}

