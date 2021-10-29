#include<cstdio>
#include<cassert>
int q, L, k;
int A[100005], B[100005], pA[100005], pre[100005];

inline int mini(int a, int b){
	return a<b?a:b;
}

void gen_prefs(){
	for(int i=1;i<=L;i++){
		pre[i] = pre[i-1];
		if(pA[i] != B[i])pre[i]++;
	}
}

void fix(int *T, int idx, int &kk, bool change_idx){
	
	for(int i=1;i<idx;i++){
		printf("%d", B[i]);
		if(T[i] != B[i]){
			//T[i]=B[i]; 
			kk--;
		}
	}
	
	if(change_idx){
		if(T[idx] == B[idx]-1)printf("%d", T[idx]-1);//T[idx]--;
		else printf("%d", B[idx]-1);//T[idx] = B[idx]-1;
		kk--;
	}
	else printf("%d", T[idx]);	

	for(int i=idx+1;i<=L;i++){
		if(pA[i] == 9 && L-i+1>k){
			printf("9");
			continue;
		}
		else if(kk){
			printf("%d", pA[i]==9?8:9);//T[i] = pA[i]==9?8:9;
			kk--;
		}
		else printf("%d", T[i]);
	}
	assert(kk==0);
}

int bs(int *T, int x){
	int l=0,r=L+1;
	while(l+1!=r){
		int mid = (l+r)/2;
		if(T[mid] <= x)l=mid;
		else r=mid;
	}
	return r;
}

bool check(){
	int not_further = bs(pre, k);
	for(int i=mini(L, not_further);i>=1;i--){
		if(B[i]==0)continue;

		if(pA[i] == B[i]-1){ // jest o jeden mniejszy
			if(pre[i-1] <= k && L-i >= k-pre[i-1]){
				fix(A, i, k, false);
				return true;
			}
			else if(pA[i]!=0 && pre[i-1]+1 <= k && L-i >= k-pre[i-1]-1){
				fix(A, i, k, true);
				return true;
			}
		}
		else if(pre[i-1]+1 <= k && L-i >= k-pre[i-1]-1){ // jest jakikolwiek, zmieniamy
			fix(A, i, k, true);
			return true;
		}
		else if(pA[i] < B[i]){ // jest mniejszy, nie zmieniamy
			if(pre[i-1] <= k && L-i >= k-pre[i-1]){
				fix(A, i, k, false);
				return true;
			}
		}
	}
	return false;
}

int main(){

	scanf("%d", &q);
	while(q--){
		scanf("\n");
		int i=1;
		char x;
		do{
			scanf("%c", &x);
			A[i++] = x-'0';
			pA[i-1]=A[i-1];
		}while(x!=' ');

		i=1;
		do{
			scanf("%c", &x);
			B[i++] = x-'0';
		}while(x!=' ');
		L=i-2;
		scanf("%d", &k);
		
		gen_prefs();
		if(check()){
		//	for(int i=1;i<=L;i++)
		//		printf("%d", A[i]);
		}
		else printf("-1");
		printf("\n");
	}

}
