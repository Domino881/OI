#include<cstdio>
int A[100000], B[100000];
int q, lA, lB,k;

bool decrease(int *T, int l){
	if(T[l]!=0){
		T[l]--;
		return true;
	}
	while(T[l]==0 && l>=0){
		T[l]=9; l--;
	}
	if(l<0){
		//for(int i=0;i<lB;i++)T[i]=0;
		return false;
	}
	T[l]--;
	return true;
}
int count_diff(int *T1, int *T2){
	int r=0;
	for(int i=0;i<lB;i++){
		if(T1[i]!=T2[i])r++;
	}
	return r;
}

bool check(){
	int kkk=k+1;
	while(kkk!=k){
		if(!decrease(B,lB-1))return false;
		kkk = count_diff(A,B);
	}
	return kkk==k;
}

int main(){

	scanf("%d", &q);
	  while(q--){
	    scanf("\n");
	    char x;
	    int i=0;
	    do{
	      scanf("%c", &x);
	      A[i++]=x-'0';
	    }while(x!=' ');
	
	    lA = i-1;
	    i=0;
	    do{
	      scanf("%c", &x);
	      B[i++]=x-'0';
	    }while(x!=' ');
	    lB = i-1;
	
	    scanf("%d", &k);

			if(check()){
				for(int i=0;i<lB;i++)printf("%d", B[i]);
			}
			else printf("-1");
			printf("\n");
	  }
}
