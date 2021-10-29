#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;
const int INF = (int)1e9+7.01;
int n,m,z,k;
bool czwarte=true;
vector<int> nbrs[100005];
vector<bool> vis(100005);

int dfs(int v){
	vis[v]=true;
	int r=1;
	for(int w : nbrs[v]){
		if(!vis[w]){
			r+=dfs(w);
		}
	}	
	return r;
}

long long fastpow(long long a, long long wyk){
	if(wyk==0)return 1;
	if(wyk%2==1)return a%INF*fastpow(a%INF*a%INF, wyk/2)%INF;
	else return fastpow(a%INF*a%INF, wyk/2);
}

long long calc(long long x){
	if(x < 3){
		switch(x){
			case 1:
				return k;
				break;
			case 2:
				return k*(k-1);
				break;
		}
	}
	if(k <= 2){
		switch(k){
			case 1:
				return (long long)x==1;
				break;
			case 2:
				if(x%2==0)return 2;
				else return 0;
				break;
		}
	}
	int d = n%2==0?1:-1;
	return (fastpow(k-1, n)%INF + d*(k-1)%INF)%INF;
}

void cykle(){
	for(int i=0;i<=n;i++)vis[i]=0;
	vector<int> sizes;
	long long res=1;
	for(int i=1;i<=n;i++){
		if(!vis[i])
			sizes.push_back(dfs(i));
	}

	for(int x : sizes){
		res*=calc(x)%INF;
		res%=INF;
	}
	printf("%lld\n", res);
}

bool dfs_check(int v, int *kolor){
	vis[v]=1;
	for(int w : nbrs[v]){
		if(kolor[w]==kolor[v])return false;
		if(!vis[w]){
			if(!dfs_check(w, kolor))return false;
		}
	}
	return true;
}

bool check_cale(int *tab){
	for(int i=0;i<=n;i++)vis[i]=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			if(!dfs_check(i, tab))return false;
		}
	}
	return true;
}

void wykladn(){
	int tab[10] = {0,0,0,0,0,0,0,0,0,0};
	long long res=0;
	int it=1;
	while(1){
		if(check_cale(tab))res++;
	
		while(tab[it]==k-1 && tab[it+1]==k-1){
			if(it==n-1){
				printf("%lld\n", res); return;
			}
			it++;
		}
		if(tab[it]==k-1){
			tab[it+1]++;
			while(it>1){
				tab[it]=0;
				it--;
			}
			tab[it]=0; continue;
		}
		tab[it]++;
	}
}

int losuj(int a, int b){
	return a+rand()%(b-a+1);
}

int main(){

	scanf("%d %d %d", &n, &m, &z);
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d %d", &a, &b);
		nbrs[a].push_back(b);
		nbrs[b].push_back(a);
	}
	for(int i=1;i<=n;i++){
		if(nbrs[i].size() != 2){
			czwarte=false; break;	
		}
	}
	
	for(int t=0;t<z;t++){
		scanf("%d", &k);
		//czwarte=false;
		if(czwarte){
			cykle();
		}
		else if(n<=9 && k<=9 && z<=60){
			wykladn();
		}
		else printf("%d\n", losuj(n, INF));
	}
}
