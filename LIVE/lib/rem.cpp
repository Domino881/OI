#include<cstdio>
#include<vector>
using namespace std;
int n,q,licz;
const int MAXN = 100005;
vector<int> nbrs[MAXN];
int depth[MAXN], path[MAXN], num[MAXN], dad[MAXN], subtr[MAXN], heavy[MAXN];

void dfs1(int v){
	for(int w : nbrs[v]){
		if(w!=dad[v]){
			dad[w]=v;
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

struct Tree{
	const static int SIZE = 1<<17;
	long long tree[SIZE*2], lazy[SIZE*2];

	void propagate(int node, int lo, int hi){
		if(lazy[node]==-1)return;
		tree[node]=(hi-lo+1)*lazy[node];
		if(lo!=hi){
			lazy[node*2]=lazy[node];
			lazy[node*2+1]=lazy[node];
		}
		lazy[node]=-1;
	}

	void update(int l, int r, long long d, int node=1, int lo=0, int hi=SIZE-1){
		if(l>r)swap(l,r);
		propagate(node, lo, hi);
		if(hi<l || lo>r)return;
		if(lo>=l && hi<=r){
			lazy[node]=d;
			propagate(node, lo, hi);
			return;
		}
		int mid = (lo+hi)/2;
		update(l,r,d,node*2,lo,mid);
		update(l,r,d,node*2+1,mid+1,hi);
		tree[node] = tree[node*2]+tree[node*2+1];
	}
	
	long long query(int l, int r, int node=1, int lo=0, int hi=SIZE-1){
		if(l>r)swap(l,r);
		propagate(node, lo, hi);
		if(lo>r || hi<l)return 0;
		if(lo>=l && hi<=r)
			return tree[node];
		int mid = (lo+hi)/2;
		return query(l,r,node*2,lo,mid) +
						query(l,r,node*2+1,mid+1,hi);
	}
}Tree;

void hldupdate(int d, int s, long long val){
	if(d==s)return;
	if(depth[path[d]]<depth[path[s]])
		swap(s,d);

	if(path[d]==path[s]){
		if(depth[d]<depth[s])
			swap(d,s);
		Tree.update(num[d], num[s]+1, val);
		return;
	}
	
	int x = path[d];
	if(x!=d)Tree.update(num[d], num[x]+1, val);
	Tree.update(num[x], num[x], val);
	hldupdate(dad[x], s, val);
}

long long hldquery(int d, int s){
	if(d==s)return 0;
	if(depth[path[d]]<depth[path[s]])
		swap(d,s);

	if(path[d]==path[s]){
		if(depth[d]<depth[s])
			swap(d,s);
		return Tree.query(num[d],num[s]+1);
	}

	int x = path[d];
	long long res=0;
	if(x!=d)res+=Tree.query(num[d],num[x]+1);
	res+=Tree.query(num[x],num[x]);
	return res+hldquery(dad[x],s);
}

void prep(){
	for(int i=0;i<Tree.SIZE*2;i++){
		Tree.tree[i]=0; Tree.lazy[i]=-1;
	}
	dfs1(1); dfs2(1,1);
//	for(int i=Tree.SIZE;i>0;i--){
//		Tree.tree[i] = Tree.tree[i*2] + Tree.tree[i*2+1];
//	}
}

int main(){

	scanf("%d %d", &n, &q);
	for(int i=0;i<n-1;i++){
		int a,b; scanf("%d %d", &a, &b);
		nbrs[a].push_back(b);
		nbrs[b].push_back(a);
	}
	prep();

	while(q--){
		int op,a,b;
		scanf("%d %d %d", &op, &a, &b);
		if(op==3){
			printf("%lld\n", hldquery(a,b));
		}
		else{
			if(op==1)hldupdate(a,b,1);
			if(op==2)hldupdate(a,b,0);
		}
	}

}
