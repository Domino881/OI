//Dominik Kuczyński
//domino881@gmail.com sio2:KapitanDomo
//zadanie SZA - dzień drugi oi28
#define pb push_back
#include<cstdio>
#include<vector>
#include<utility>
#include<string>
#include<iostream>
#include<map>
using namespace std;
const int MAXN=2004, LOGN=11;
int n,letters;
vector<pair<int, char> > nbrs[MAXN];
vector<bool> vis(MAXN),letter(40);
int jump[MAXN][LOGN+2], depth[MAXN];
char edge[MAXN];
map<string, vector<pair<int,int> > > M;

//lca korzystając z własnego starego kodu
void dfs(int v){
	vis[v]=true;
	for(auto w : nbrs[v]){
		if(!vis[w.first]){
			jump[w.first][0]=v; depth[w.first]=depth[v]+1;
			edge[w.first]=w.second;
			dfs(w.first);
		}
	}
}
void prep(){
	dfs(1);
	jump[0][0]=1; jump[1][0]=1;
	for(int i=1;i<=LOGN;i++){
		for(int j=1;j<MAXN;j++)
			jump[j][i]=jump[jump[j][i-1]][i-1];
	}
}
int lca(int a, int b){
	if(depth[a]<depth[b])swap(a,b);
	for(int i=LOGN;depth[a]>depth[b];i--){
		if(depth[a] - (1<<i) >= depth[b])
			a = jump[a][i];
	}
	if(a==b)return a;

	for(int i=LOGN;i>=0;i--){
		if(jump[a][i] != jump[b][i]){
			a = jump[a][i]; b = jump[b][i];
		}
	}
	return jump[b][0];
}
string reverse(string a){
	string r=a;
	for(unsigned i=0;i<r.size()/2;i++)
		swap(r[i],r[r.size()-1-i]);
	return r;
}

bool check(vector<pair<int,int> > v){
	for(int i=0;i<=n;i++)vis[i]=0;
	int licz=1;
	for(auto x : v){
		int i=x.first, j=x.second, lcaij=lca(i,j);
		while(i!=lcaij){
			if(!vis[i]){
				vis[i]=1; licz++;
			}
			i=jump[i][0];
		}
		while(j!=lcaij){
			if(!vis[j]){
				vis[j]=1; licz++;
			}
			j=jump[j][0];
		}
	}
	return licz==n;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin>>n;
	for(int i=0;i<n-1;i++){
		int a,b; char c;
		cin>>a>>b>>c;
		nbrs[a].pb({b,c});
		nbrs[b].pb({a,c});
		if(!letter[c-'A']){letter[c-'A']=1; letters++;}
	}
	prep();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int lcaij = lca(i,j);
			string path1 = "", path2 = "";

			int ii=i,jj=j,l=0;

			while(ii!=lcaij){
				path1=path1+edge[ii]; ii=jump[ii][0];
			}
			while(jj!=lcaij){
				path2=edge[jj]+path2; jj=jump[jj][0];
			}
			string path = path1+path2;
			string path_r = reverse(path);
			for(int k=0;k<30;k++)letter[k]=0;

			for(unsigned k=0;k<path.size();k++){
				if(!letter[path[k]-'A']){
					letter[path[k]-'A']=1; l++;
				}
			}

			if(l<letters)continue;
			if(!M.count(path) && !M.count(path_r)){
				M[path]={{i,j}};
				M[path_r]={{i,j}};
			}
			if(M.count(path))
				M.find(path)->second.pb({i,j});
			if(M.count(path_r))
				M.find(path_r)->second.pb({i,j});
			//cout<<i<<" "<<j<<" "<<path<<" "<<path_r<<"\n";
		}
	}
	vector<string> res;
	for(auto x : M){
		if(check(x.second))
			res.pb(x.first);
	}
	cout<<res.size()<<"\n";
	for(auto x : res)cout<<x<<"\n";

}
