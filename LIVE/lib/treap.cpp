#include<cstdio>
#include<utility>
#include<random>
using namespace std;
using namespace std;

struct treap{
	treap *left=nullptr, *right=nullptr;
	int k,rank,size=1;
	treap(int k=0): k(k), rank(rand()) {};
};

inline int tsize(treap *t){
	return !t? 0:t->size;
}
void tupdate(treap *t){
	t->size = tsize(t->left)+tsize(t->right)+1;
}

treap *merge(treap *a, treap *b){
	if(!a)return b;
	if(!b)return a;

	if(a->rank > b->rank){
		a->right = merge(a->right, b);
		tupdate(a);
		return a;
	}
	else{
		b->left = merge(a, b->left);
		tupdate(b);
		return b;
	}
}

pair<treap*, treap*> split(treap *t, int k){
	if(!t)return pair<treap*, treap*>(nullptr,nullptr);
	if(k<=tsize(t->left)){
		auto p = split(t->left, k);
		t->left = p.second;
		tupdate(t);
		return {p.first, t};
	}
	else{
		auto p = split(t->right, k-tsize(t->left)-1);
		t->right = p.first;
		tupdate(t);
		return {t, p.second};
	}
}

int main(){
	srand(6969);
	

}
