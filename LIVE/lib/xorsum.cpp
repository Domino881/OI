#include<cstdio>
int n, q;
const int SIZE = 1<<17, LOG=21;
long long tree[LOG+5][SIZE*2];
long long lazy[SIZE*2];
const long long INF = 1000000009;

long long sum(int node){
	long long r=0;
	for(int i=0;i<=LOG;i++){
		r+=tree[i][node] * (1<<i);
	}
	return r;
}

inline long long mini(int a, int b){
	return a<b?a:b;
}

void propagate(int node, int l, int r){
	if(lazy[node] != 0){
		for(int i=0;i<=LOG;i++){
			if(lazy[node] & 1<<i){
				tree[i][node] = r-l+1-tree[i][node];
			}
		}

		if(l!=r){
			lazy[node*2] ^= lazy[node];
			lazy[node*2+1] ^= lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int a, int b, long long v, int node=1, int l=0, int r=SIZE-1){
	propagate(node, l, r);
	if(r<a || l>b)return;
	if(l>=a && r<=b){
		lazy[node] ^= v;
		propagate(node, l, r);
		return;
	}
	int mid = (l+r)/2;
	update(a,b,v,node*2,l,mid);
	update(a,b,v,node*2+1,mid+1,r);
	for(int i=0;i<=LOG;i++)tree[i][node] = tree[i][node*2]+tree[i][node*2+1];
}

long long query(int a, int b, int node=1, int l=0, int r=SIZE-1){
	propagate(node, l, r);
	if(r<a || l>b)return 0;
	if(l>=a && r<=b)return sum(node);
	int mid=(l+r)/2;
	return query(a,b,node*2,l,mid) +
  			 query(a,b,node*2+1,mid+1,r);
}

void build(){
	for(int i=SIZE-1;i>0;i--){
		for(int j=0;j<=LOG;j++)
			tree[j][i]=tree[j][i*2] + tree[j][i*2+1];
	}
}

int main(){

	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int x; scanf("%d", &x); update(i,i,x);	
	}
	//build();
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
