#include<cstdio>
#include<climits>
#include<algorithm>
#define jajco jajco
int n;
long long tab[200005], best=0;
const long long LOG=62;
long long maxlog=0;

inline long long maks(long long a, long long b){
	return a>b?a:b;
}

struct node{
	node* zero=nullptr;
	node* one=nullptr;
}node0;

void trie_insert(long long v){
	node* n = &node0;
	long long i=LOG;
	for(;!(v&((long long)1<<i));i--){
		if(n->zero == nullptr)
			n->zero = new node;
		n=n->zero;
	}
	for(;i>=0;i--){
		if(v&((long long)1<<i)){
			if(n->one == nullptr)
				n->one = new node;
			n=n->one;
		}
		else{
			if(n->zero == nullptr)
				n->zero= new node;
			n=n->zero;
		}
	}
}

long long mxor(long long v){
	node* n = &node0;
	long long licz = LOG;
	long long res=0;
	long long llog=0;
	while(n->zero != nullptr || n->one != nullptr){
		if(v&((long long)1<<licz)){
			if(n->zero!=nullptr){
				if(!llog)llog=licz;
				if(llog<maxlog)return -1;
				maxlog = llog;
				n=n->zero;
				res += (long long)1<<licz;
				licz--;
			}
			else{
				if(!llog && licz<=maxlog)return -1;
				n=n->one;
				licz--;
			}
		}
		else{
				if(n->one!=nullptr){
					if(!llog)llog=licz;
					if(llog<maxlog)return -1;
					maxlog = llog;	
					n=n->one;
					res += (long long)1<<licz;
					licz--;
				}
				else{
					if(!llog && licz<=maxlog)return -1;
					n=n->zero; licz--;
				}
		}
	}
	return res;
}

bool comp(long long a, long long b){
	return a>b;
}

int main(){

	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%lld", &tab[i]);
		trie_insert(tab[i]);
	}
	std::sort(tab, tab+n, comp);
	for(int i=0;i<n/* && (((long long)1<<maxlog)&tab[i])*/;i++){
		if((1<<maxlog) > tab[i])break;
		best = maks(best, mxor(tab[i]));
	}
	printf("%lld\n", best);
}
