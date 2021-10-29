//Dominik Kuczyński
//domino881@gmail.com sio2:KapitanDomo
//zadanie pro - dzień próbny
#define pb push_back
#include<cstdio>
#include<vector>
#include<utility>
using namespace std;
const int N=100;
long long K;
vector<pair<int,int> > rows[N+4];
bool tab[N+4][N+4];

int main(){

	scanf("%lld", &K);
	int it=0, last_full_row=2;
	bool last_right=0;
	K*=2;

	while(K>=0){
	   	K/=2;
		if(K==0)break;
		if(K>1 && last_full_row>1)rows[it].pb({it-1,it+1});
		else if(K>1)rows[it].pb({it,it+1});

		if(K%2==1){
			if(last_full_row>1 && !last_right){
				rows[it].pb({it-1,N-1});
				last_full_row=0;
				last_right=0;
			}
			else if(!last_right){
				rows[it].pb({N-3,N-1});
				last_right=1;
			}
			else{
				rows[it-1].pb({N-7,N-4});
				last_right=0;
			}
		}
		else last_right=0;
		it++; last_full_row++;
	}

	for(int i=it+1;i<N;i++){
		tab[i][0]=1;
	}
	for(int i=0;i<N;i++){
		tab[i][N-1]=1; tab[N-1][i]=1;
	}

	for(int i=0;i<N;i++){
		for(auto x : rows[i]){
			for(int a=x.first;a<=x.second;a++)tab[i][a]=1;
		}
	}

	printf("%d\n",N);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			printf("%c",tab[i][j]?'.':'#');
		}
		printf("\n");
	}
}
