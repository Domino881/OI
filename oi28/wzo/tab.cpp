#include<cstdio>
#include<utility>
#include<set>
using namespace std;
int n,m,q;
set<pair<int,int> > S;

int main(){

	scanf("%d %d %d", &n,&m,&q);
	while(q--){
		int x1,y1,x2,y2; scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		if((x1>1 && y1>1) && S.count({x1-1,y1-1}))S.erase({x1-1,y1-1});
		else if(x1>1 && y1>1)S.insert({x1-1,y1-1});

		if(S.count({x2,y2}))S.erase({x2,y2});
		else S.insert({x2,y2});

		if(x1>1 && S.count({x1-1,y2}))S.erase({x1-1,y2});
		else if(x1>1)S.insert({x1-1,y2});

		if(y1>1 && S.count({x2,y1-1}))S.erase({x2,y1-1});
		else if(y1>1)S.insert({x2,y1-1});
		
		printf("%lu\n",S.size());
	}

}
