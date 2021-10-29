#include<cstdio>
#include<vector>
#include<cassert>
#include<utility>
#include<climits>
using namespace std;
const int LOGN = 15;
int n,m,cur=1,res,licz;
vector<pair<int,int> > nbrs[200005];
int jump[200005][LOGN+2], shortest[200005][LOGN+2], depth[200005];
vector<bool> vis(200005);

inline int mini(int a, int b){
	return a<b?a:b;
}

void dfs(int v){
	vis[v]=true;
	for(pair<int,int> w : nbrs[v]){
		if(!vis[w.first]){
			jump[w.first][0]=v;
			depth[w.first]=depth[v]+1;
			shortest[w.first][0] = w.second;
			dfs(w.first);
		}
	}
}

void prep(){
	dfs(1);
	jump[0][0]=1;
	jump[1][0]=1;
	shortest[1][0]=INT_MAX;
	for(int i=1;i<=LOGN;i++){
		for(int j=1;j<200005;j++){
			jump[j][i] = jump[jump[j][i-1]][i-1];
			shortest[j][i] = mini(shortest[j][i-1], shortest[jump[j][i-1]][i-1]);
		}
	}
}

int lca(int a, int b){
	if(depth[a]<depth[b])swap(a,b);
	int best=INT_MAX;

	for(int i=LOGN;depth[a]>depth[b];i--){
		if(depth[a] - (1<<i) >= depth[b]){
			best = mini(best, shortest[a][i]);
			a = jump[a][i];
		}
	}
	if(a==b)return best;

	for(int i=LOGN;i>=0;i--){
		if(jump[a][i] != jump[b][i]){
			best = mini(best, shortest[a][i]);
			best = mini(best, shortest[b][i]);
			a = jump[a][i];
			b = jump[b][i];
		}
	}
	best = mini(best, shortest[a][0]);
	return mini(best, shortest[b][0]);
}


int main(){

	int q;
	scanf("%d %d", &n, &q);
	for(int i=0;i<n-1;i++){
		int a,b,w; scanf("%d %d %d", &a, &b, &w);
		nbrs[a].push_back(make_pair(b,w));
		nbrs[b].push_back(make_pair(a,w));
	}
	prep();
	while(q--){
		int x,y; scanf("%d %d", &x, &y);
		printf("%d\n", lca(x,y));
	}
}
