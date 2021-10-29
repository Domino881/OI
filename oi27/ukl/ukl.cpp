#include<cstdio>
#include<utility>
#include<vector>
#include<bitset>
#define mp make_pair
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
using namespace std;
int n,m,k,trunk;
pair<int, int> start, last; //pierwszy i ostatni wierzcholek najdluzszej sciezki
bool visited[1002][1002];
bitset<4> graph[1002][1002]; //up, down, left, right
bool zamien=false;

bool primary_check(){
	if(m%2==0 && n%2==0){
		if(k<n+m-1)return false;
		if(k>n*m-1)return false;
	}
	//if(m%2==1){
	else{
		if(k<n+m-2)return false;
		if(k>n*m-1)return false;
	}
	return true;
}

void connect(pair<int, int> a, pair<int, int> b, int dir){
	int* af = &a.first, *as = &a.second;
	int* bf = &b.first, *bs = &b.second;
	switch(dir){
		case UP:
			graph[*af][*as][UP]=1;
			graph[*bf][*bs][DOWN]=1;
			break;
		case DOWN:
			graph[*af][*as][DOWN]=1;
			graph[*bf][*bs][UP]=1;
			break;
		case LEFT:
			graph[*af][*as][LEFT]=1;
			graph[*bf][*bs][RIGHT]=1;
			break;
		case RIGHT:
			graph[*af][*as][RIGHT]=1;
			graph[*bf][*bs][LEFT]=1;
			break;
	}
	visited[*af][*as]=true; visited[*bf][*bs]=true;
}
///naprawicececcc 2|m && 2!|n
bool step(pair<int, int> &v, int &licz){
//////////////////////LEWA///////////////////////
	if(v.second < trunk){//jesli to lewy
			if(v.first < n-1 && 
					!visited[v.first+1][v.second]){
				//jesli mozna w dol
				connect(v, mp(v.first+1, v.second), DOWN);
				v = mp(v.first+1, v.second);
				licz--;
				return true;
			}

			else if(v.first > 1 && 
							 !visited[v.first-1][v.second]){
				//jesli mozna w gore
				connect(v, mp(v.first-1, v.second), UP);
				v = mp(v.first-1, v.second);
				licz--;
				return true;
			}

			else if(v.first == 1 || 
							 v.first == n-1){
				//jesli treba w bok
				if(v.second == trunk-1)return false;
				
				connect(v, mp(v.first, v.second+1), RIGHT);
				v = mp(v.first, v.second+1);
				licz--;
				return true;
			}

			else return false;
	}

//////////////////////PRAWA/////////////////////////
	else if(v.second > trunk){
			//jesli po prawej
			if(v.first < n-2 && 
					!visited[v.first+1][v.second]){
				//jesli mozna w dol
				connect(v, mp(v.first+1, v.second), DOWN);
				v = mp(v.first+1, v.second);
				licz--;
				return true;
			}
			else if(v.first > 0 && 
							 !visited[v.first-1][v.second]){
				//jesli mozna w gore
				connect(v, mp(v.first-1, v.second), UP);
				v = mp(v.first-1, v.second);
				licz--;
				return true;
			}
			else if(v.first == 0 || 
							 v.first == n-2){
				//jesli treba w bok
				if(v.second == trunk+1)return false;
				
				connect(v, mp(v.first, v.second-1), LEFT);
				v = mp(v.first, v.second-1);
				licz--;
				return true;
			}
			else return false;
	}
///////////////////////////////////////////////////
	return false;
}

void fill_rest(){
	/*
	 *gorny lewy zawsze filluj
	 *pien zawse filluj
	 *dolny prawy zawsze filluj
	 *reszte filluj jesli nieodwiedzone
	*/
	for(int j=0;j<trunk;j++){//gorny lewy rzadek
			graph[0][j][RIGHT]=1;
			graph[0][j+1][LEFT]=1;
			visited[0][j]=true;
	}
	for(int i=0;i<n-1;i++){//pien
		graph[i][trunk][DOWN]=1;
		graph[i][trunk][UP]=1;
		visited[i][trunk]=true;
	}
	for(int j=trunk;j<m-1;j++){//dolny prawy rzadek
			graph[n-1][j][RIGHT]=1;
			graph[n-1][j+1][LEFT]=1;
			visited[n-1][j]=true;
			visited[n-1][j+1]=true;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(!visited[i][j]){
				if(j<trunk)connect(mp(i,j), mp(i,j+1), RIGHT);
				else connect(mp(i,j), mp(i,j-1), LEFT);
			}
		}
	}
}

void print_tree(){
	if(!zamien){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(graph[i][j][RIGHT])
					printf("%d %d %d %d\n", i+1,j+1,i+1,j+2);
				if(graph[i][j][DOWN])
					printf("%d %d %d %d\n", i+1,j+1,i+2,j+1);
			}
		}
	}
	else{
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(graph[i][j][RIGHT])
					printf("%d %d %d %d\n", j+1,i+1,j+2,i+1);
				if(graph[i][j][DOWN])
					printf("%d %d %d %d\n", j+1,i+1,j+1,i+2);
			}
		}
	}
}
void print_tree2(){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(graph[i][j][RIGHT] && graph[i][j][DOWN])printf("+");
			else if(graph[i][j][RIGHT])printf("-");
			else if(graph[i][j][DOWN])printf("|");
			else printf(".");
		}
		printf("\n");
	}
}

int main(){

	scanf("%d %d %d", &n, &m, &k);

	if(!primary_check()){
		printf("NIE\n"); return 0;
	}
	printf("TAK\n");
	if(m%2==0 && n%2==1){
		zamien=true;
		swap(n,m);
	}

	trunk = (m-1)/2; //pien choinki w floor(m/2)
	start = mp(0,0); last = mp(n-1,m-1);

	k-=n+m-2;	
	if(m%2==0 && n%2==0){
		if(!step(start, k))
			k--;
	}

	while(k){
		if(!step(start, k))break;
	}
	while(k){
		if(!step(last, k))break;
	}

	fill_rest(); // wypelnij nieodwiedzone standardowa choinka
	print_tree();
}
