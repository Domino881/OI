#include<cstdio>
#include<climits>
#include<queue>
#include<vector>
using namespace std;
int n,m,k;
bool vis[1000005];
vector<int> nbrs[1000005];
int dist[1000005];
priority_queue<int> best;
int longest;
int l;

inline int mini(int a, int b){
	return a<b?a:b;
}

void dfs(int v, int d){
	vis[v]=true;
	for(int w : nbrs[v]){
		if(!vis[w])dfs(w, d+1);
	}
	if(d>longest)l=v, longest=d;
}

int main(){

	scanf("%d %d %d\n", &n, &m, &k);
	char odp[4];
	scanf("%c%c%c", &odp[0], &odp[1], &odp[2]);
	if(odp[0] == 'N')return 0;
	for(int i=0;i<n*m-1;i++){
		dist[i+1]=INT_MAX;
		int a1,a2,b1,b2;
		scanf("%d %d %d %d", &a1, &a2, &b1, &b2);
		if(a1>n || a2>m || b1>n || b2>m)return 1;
		nbrs[m*(a1-1)+a2].push_back(m*(b1-1)+b2);
		nbrs[m*(b1-1)+b2].push_back(m*(a1-1)+a2);
	}
	dfs(1,0);
	longest=0;
	for(int i=1;i<=n*m;i++)vis[i]=false;
	dfs(l,0);
	printf("longest=%d k=%d\n", longest, k);
	if(longest==k)return 0;
	return 1;
}
