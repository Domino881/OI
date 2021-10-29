#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#define pb push_back
using namespace std;
int n,z,licz;
long long X, dp[100005];
vector<pair<int,int> > holes;

inline int mini(int a, int b){ return a<b?a:b; }

bool comp(pair<int,int> a, pair<int,int> b){
	if(a.first==b.first)return a.second<b.second;
	return a.first>b.first;
}


int main(){

	scanf("%d %lld %d", &n, &X, &z);
	for(int i=0;i<n;i++){
		int k; scanf("%d", &k);
		for(int j=0;j<k;j++){
			long long x; scanf("%lld", &x); holes.pb({x,i});
		}
	}
	sort(holes.begin(),holes.end(),comp);
	for(auto x : holes){
		if(x.second == n-1){
			dp[x.second]++;
		}
		else{
			int dp1 = mini(dp[x.second+1], dp[x.second]+1);
			dp[x.second]=dp1; dp[x.second+1]=dp1;
		}
	}
	while(z--){
		int p; scanf("%d", &p);
		printf("%lld\n", dp[p-1]);
	}
}
