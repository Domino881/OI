#include<cstdio>
int n,z;
int num1[300004], num2[300004];
const int SIZE=1<<18;
int tree_min[2*SIZE+2],tree_max[2*SIZE+2], lazy[2*SIZE+3];

inline int mini(int a, int b){
	return a<b?a:b;
}
inline int maks(int a, int b){
	return a>b?a:b;
}
inline int mod(int x, int m){
	while(x<0)x+=m;
	return x%m;
}

void propagate(int node){
	if(node <= SIZE){
		lazy[node*2]+=lazy[node];
		lazy[node*2+1]+=lazy[node];
	}
	tree_min[node]+=lazy[node];
	tree_max[node]+=lazy[node];
	lazy[node]=0;
}

void update(int l, int r, int d, int lo=0, int hi=SIZE-1, int node=1){
	propagate(node);
	if(lo>r || hi<l || r<l)return;
	if(lo>=l && hi<=r){
		lazy[node]+=d;
		propagate(node);
		return;
	}
	int mid = (lo+hi)/2;
	update(l,r,d,lo,mid,node*2);
	update(l,r,d,mid+1,hi,node*2+1);
	tree_min[node]=mini(tree_min[node*2], tree_min[node*2+1]);
	tree_max[node]=maks(tree_max[node*2], tree_max[node*2+1]);
}

int query_min(int l, int r, int lo=0, int hi=SIZE-1, int node=1){
	propagate(node);
	if(lo>r || hi<l || r<l)return 11;
	if(lo>=l && hi<=r)return tree_min[node];
	int mid=(lo+hi)/2;
	return mini(query_min(l,r,lo,mid,node*2), query_min(l,r,mid+1,hi,node*2+1));
}
int query_max(int l, int r, int lo=0, int hi=SIZE-1, int node=1){
	propagate(node);
	if(lo>r || hi<l || r<l)return -1;
	if(lo>=l && hi<=r)return tree_max[node];
	int mid=(lo+hi)/2;
	return maks(query_max(l,r,lo,mid,node*2), query_max(l,r,mid+1,hi,node*2+1));
}

void add(int i, int d){
	int qii=query_min(i,i);
	if(qii+d >= 0 && qii+d < 10)update(i,i,d);
	else if(qii+d<0){
		update(i,i,10+d);
		int l=i, r=SIZE-1;
		while(l+1!=r){
			int mid=(l+r)/2;
			if(mod(query_max(i+1,mid),10) == 0)l=mid;
			else r=mid;
		}
		//printf("found zeros on (%d, %d)\n", i+1,l);
		if(mod(query_max(i+1,r)==0,10))l=r;
		update(i+1,l,9);
		update(l+1,l+1,-1);
	}
	else{
		update(i,i,((d+qii)%10)-qii);
		int l=i,r=SIZE-1;
		while(l+1!=r){
			int mid=(l+r)/2;
			if(query_min(i+1,mid) == 9)l=mid;
			else r=mid;
		}
		if(mod(query_min(i+1,r)==9,10))l=r;
		//printf("updating +1 on (%d, %d)\n", i+1,l+1);
		update(i+1,l,-9);
		update(l+1, l+1, 1);
	}
}

int main(){

	scanf("%d %d\n", &n, &z);
	for(int i=1;i<n;i++){
		char tmp;
		scanf("%c", &tmp);
		num1[n-i]=tmp-'0';
		add(n-i,num1[n-i]);
	}
	scanf("\n");
	for(int i=1;i<n;i++){
		char tmp;
		scanf("%c", &tmp);
		num2[n-i]=tmp-'0';
		add(n-i,num2[n-i]);
	}

	while(z--){
		char op;
		scanf("\n%c", &op);
		if(op=='W'){
			int i,v; scanf("%d %d", &i, &v); 
			add(i, v-num1[i]);
			num1[i]=v;
		}
		else if(op=='Z'){
			int i,v; scanf("%d %d", &i, &v);
			add(i, v-num2[i]);
			num2[i]=v;
		}
		else{
			int i;
			scanf("%d", &i);
			printf("%d\n", query_min(i,i));
		}
	}

}

