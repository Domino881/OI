//Dominik Kuczyński
//domino881@gmail.com sio2:KapitanDomo
//zadanie PLE - dzień pierwszy oi28
#include<cstdio>
#include<algorithm>
#include<utility>
#include<vector>
using namespace std;
const long long MAXN=500006, INF=1e18-5;
int n;
long long tab[MAXN];
vector<bool> vis(MAXN);

inline long long mini(long long a, long long b){
	return a<b?a:b;
}

int main(){

	scanf("%d", &n);
	for(int i=1;i<=n;i++){
		scanf("%lld", &tab[i]);
	}
	
}
