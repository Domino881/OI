#include<cstdio>
int n, tab[105][105];
int dp[105][105];

int main(){

	scanf("%d", &n);
	for(int i=1;i<=n;i++){
		scanf("\n");
		for(int j=1;j<=n;j++){
			char tmp;
			scanf("%c", &tmp);
			tab[i][j] = tmp=='.'?1:0;
		}
	}
	dp[1][1]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(tab[i][j]){
				dp[i][j] += dp[i-1][j]+dp[i][j-1];
			}
		}
	}
	printf("%d\n", dp[n][n]);

}
