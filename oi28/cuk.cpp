#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>
#include<climits>
using namespace std;
long long tab[300004][4], tab1[300004][4];
int n;
//vector<pair<long long,int> > best_zero,best_one,best_two;
int best0,best1,best2;
long long zeros,ones,twos,res;
int bests[4][4];
vector<int> zeroisbest,oneisbest,twoisbest;

void fix_best(){
	long long score=LLONG_MAX;
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				for(int k=0;k<3;k++){
					if(bests[0][i] == bests[1][j] || bests[1][j] == bests[2][k] || bests[0][i] == bests[2][k])
						continue;
					if(tab1[bests[0][i]][0] + tab1[bests[1][j]][1] + tab1[bests[2][k]][2] < score){
						best0=i; best1=j; best2=k;
						score = tab1[bests[0][i]][0] + tab1[bests[1][j]][1] + tab1[bests[2][k]][2]; 
					}
				}
			}
		}
	if(zeros==0)best0=-1;
	if(ones==0)best1=-1;
	if(twos==0)best2=-1;
}

void place(int num, int i){
	if(bests[num][0]==-1 || tab1[i][num] <= tab1[bests[num][0]][num]){
		bests[num][2]=bests[num][1];
		bests[num][1]=bests[num][0];
		bests[num][0]=i;
	}
	else if(bests[num][1]==-1 || tab1[i][num] <= tab1[bests[num][1]][num]){
		bests[num][2]=bests[num][1];
		bests[num][1]=i;
	}
	else if(bests[num][2]==-1 || tab1[i][num] <= tab1[bests[num][2]][num]){
		bests[num][2]=i;
	}
	else return;
}

inline long long mini(long long a, long long b){
	return a<b?a:b;
}
inline long long mini(long long a, long long b, long long c){
	return mini(a, mini(b,c));
}

int main(){

	scanf("%d", &n);
	for(int i=0;i<=3;i++){
		for(int j=0;j<=3;j++){
			bests[i][j]=-1;
		}
	}

	for(int i=0;i<n;i++){
		scanf("%lld %lld %lld", &tab[i][0], &tab[i][1], &tab[i][2]);
		tab1[i][0]=tab[i][1]+tab[i][2];
		tab1[i][1]=tab[i][0]+tab[i][2];
		tab1[i][2]=tab[i][0]+tab[i][1];
		int best_cost=mini(tab1[i][0], tab1[i][1], tab1[i][2]);
		res+=best_cost;
		tab1[i][0]-=best_cost; tab1[i][1]-=best_cost; tab1[i][2]-=best_cost;
		if(mini(tab1[i][0], tab1[i][1], tab1[i][2]) == tab1[i][0])zeroisbest.push_back(i);
		if(mini(tab1[i][0], tab1[i][1], tab1[i][2]) == tab1[i][1])oneisbest.push_back(i);
		if(mini(tab1[i][0], tab1[i][1], tab1[i][2]) == tab1[i][2])twoisbest.push_back(i);

		zeros+=tab[i][0]; ones+=tab[i][1]; twos+=tab[i][2];
		place(0, i);place(1, i);place(2, i);
	}

	fix_best();
	//printf("best1=%lld %d\n", tab1[bests[0][best0]][0],bests[0][best0]);{{{
	//printf("best2=%lld %d\n", tab1[bests[1][best1]][1],bests[1][best1]);
	//printf("best3=%lld %d\n", tab1[bests[2][best2]][2],bests[2][best2]);
	//printf("%d\n", best0.second+best1.second+best2.second);
	//long long res=0,oldres=0;
	//for(int i=0;i<n;i++){
		//if(i==bests[0][best0])res+=tab[i][1]+tab[i][2];
		//else if(i==bests[1][best1])res+=tab[i][0]+tab[i][2];
		//else if(i==bests[2][best2])res+=tab[i][1]+tab[i][0];
		//else res+=mini(tab[i][0]+tab[i][1],tab[i][1]+tab[i][2],tab[i][0]+tab[i][2]);
		////printf("%lld\n", res-oldres);
		//oldres=res;
	//}}}}
	if(best0!=-1)res+=tab1[bests[0][best0]][0];
	if(best1!=-1)res+=tab1[bests[1][best1]][1];
	if(best2!=-1)res+=tab1[bests[2][best2]][2];
	printf("%lld\n", res);
}

