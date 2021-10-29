#include<cstdio>
int q,k,K;
int lA, lB, first_md;
int A[1000], B[1000], pA[1000];

bool works(int a, int b){
	for(int i=a;i<=b;i++){
		if(B[i]>A[i])return true;
		else if(A[i]>B[i])return false;
	}
	return false;
}

bool check_zeros(){
	int i=0;
	while(B[i]==0){
		if(A[i]!=0){
			A[i]=0; k--;
		}
		i++;
	}
	first_md = i;
	if(k>lB-i || i==lB)
		return false;
	return true;
}
bool change_first(){
	A[first_md] = B[first_md]-1; k--;
	for(int i=first_md+1;i<lA && k;i++){
		A[i] = A[i]==9?8:9; k--;
	}
	if(k==0)return true;
	else return false;
} //////////////////////////////////////////////////////////////////ma byc mnieeeeejsze
bool dont_ch_first(){
	int must_do=0, can_do=lB-first_md-1, greater_eq=0;
	for(int i=first_md+1;i<lB && B[i]==0;i++){
		if(A[i]!=0)must_do++;
		if(A[i]==B[i])can_do--;
	}
	for(int i=first_md+1;i<lB;i++){
		if(A[i]>=B[i])greater_eq++;
	}
	
	int d = A[first_md]==B[first_md]?0:1;
	if(must_do > k || can_do < k || (k-d==0 && greater_eq))return false;

	if(A[first_md] != B[first_md]){
		A[first_md] = B[first_md]; k--;
	}

	for(int i=first_md+1;i<lB && k;i++){
		if(A[i]==B[i])continue;
		if(k==1){
			if(works(i+1, lB-1)){
				A[i]=B[i]; --k;
			}
			else if(B[i]!=0){
				A[i]=B[i]-1; --k;
				return true;
			}
			else return false;
		}
		else{
			A[i]=B[i]; k--;
		}
	}
	if(!k)return true;

	for(int i=lB-1;i>=0 && k;i--){
		else{
			A[i] = pA[i]==9?8:9;
			k--;
		}
	}

	if(!k)return true;
	else return false;
}

bool check(){
	if(!dont_ch_first()){
		for(int i=0;i<lA;i++)A[i]=pA[i];
		k=K;
		return change_first();
	}
	else return true;

//	return dont_ch_first();//dont_ch_first();
}

int main(){

	scanf("%d", &q);
	while(q--){
		scanf("\n");
		char x;
		int i=0;
		do{
			scanf("%c", &x);
break
			pA[i-1] = A[i-1];
		}while(x!=' ');
		
		lA = i-1;
		i=0;
		do{
			scanf("%c", &x);
			B[i++]=x-'0';
		}while(x!=' ');
		lB = i-1;

		scanf("%d", &k);
		K=k;
		if(!check_zeros() || !check())printf("-1");
		else{
			for(int j=0;j<lA;j++)printf("%d", A[j]);
		}
		printf("\n");
	}

}
