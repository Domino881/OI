#include<cstdio>
int q, L;
int A[100005], B[100005];

int main(){

	scanf("%d", &q);
	while(q--){
		scanf("\n");
		int i=0;
		do{
			char x;
			scanf("%c", &x);
			A[i++] = (int)x-'0';
			pA[i-1]=A[i-1];
		}while(x!='\n');

		i=0;
		do{
			char x;
			scanf("%c", &x);
			B[i++] = (int)x-'0';
		}while(x!='\n');
		L=i-1;

		DP();
		if()
	}

}
