//Dominik Kuczyński
//domino881@gmail.com sio2:KapitanDomo
//zadanie ZDJ - dzień pierwszy oi28
#define pb push_back
#include<cstdio>
#include<vector>
using namespace std;
int n,m;
vector<int> nbrs[500005];

bool check(vector<int> tab){
	for(unsigned i=3;i<tab.size();i++){
		int myhat=tab[i];
		int bigger=0, smaller=0;
		for(int x : nbrs[i]){
			if(tab[x] > myhat)bigger++;
			else smaller++;
		}
		if(bigger!=smaller){return false;}
	}
	return true;
}

//kod funkcji permute zainspirowany
//www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
bool permute(vector<int> tab, int l, int r){
	if(l==r && check(tab)){
		printf("TAK\n");
		for(unsigned i=1;i<tab.size();i++)printf("%d ",tab[i]);
		return true;
	}
	for(int i=l;i<=r;i++){
		swap(tab[l], tab[i]);
		if(permute(tab,l+1,r))return true;
		swap(tab[l], tab[i]);
	}
	return false;
}

int main(){

	scanf("%d %d", &n, &m);
	for(int i=0;i<m;i++){
		int a,b; scanf("%d %d",&a,&b);
		nbrs[a].pb(b); nbrs[b].pb(a);
	}
	vector<int> tab; for(int i=0;i<=n;i++)tab.pb(i);
	if(!permute(tab,1,tab.size()-1)){
		printf("NIE\n");
	}

}
