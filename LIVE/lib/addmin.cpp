#include<cstdio>
int n, q;
const int SIZE = 1<<20;
long long tree[SIZE*2];
long long lazy[SIZE*2];
const long long INF = 1000000009;

inline long long mini(int a, int b){
	return a<b?a:b;
}

void propagate(int node, int l, int r){
	if(lazy[node] != 0){
		tree[node] += lazy[node];
		if(l!=r){
			lazy[node*2] += lazy[node];
			lazy[node*2+1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int l, int r, long long v, int node=1, int lo=0, int hi=SIZE-1){
	//jajco
	propagate(node, lo, hi);
	if(hi<l || lo>r)return;
	if(lo>=l && hi<=r){
		lazy[node] += v;
		propagate(node, lo, hi);
		return;
	}
	int mid = (lo+hi)/2;
	update(l,r,v,node*2,lo,mid);
	update(l,r,v,node*2+1,mid+1,hi);
	tree[node] = mini(tree[node*2],tree[node*2+1]);
}

//	fajna funkcja
//	ale fajsna
long long query(int a, int b, int node=1, int l=0, int r=SIZE-1){
	propagate(node, l, r);
	if(r<a || l>b)return INF;
	if(l>=a && r<=b)return tree[node];
	int mid=(l+r)/2;
	return mini(query(a,b,node*2,l,mid),
							query(a,b,node*2+1,mid+1,r));
}

void build(){
	for(int i=SIZE-1;i>0;i--){
		tree[i]=mini(tree[i*2],tree[i*2+1]);
	}
//	for(int i=0;i<SIZE*2;i++)lazy[i]=INF;
}

int main(){

	scanf("%d", &n);
	for(int i=0;i<n;i++)scanf("%lld", &tree[SIZE+i]);
	build();
	scanf("%d", &q);

	while(q--){
		char op[20];
		scanf("%s", op);
		if(op[0] == '1'){
			int a, b;
			scanf("%d %d", &a, &b);
			printf("%lld\n", query(a-1,b-1));
		}
		else{
			int a,b,val;
			scanf("%d %d %d", &a, &b, &val);
			update(a-1,b-1,val);
		}
	}
}
