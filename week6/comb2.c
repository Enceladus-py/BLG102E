#include <stdio.h>

int comb(int n1,int n2){

	float result = 1;

	for(int i1=n1,i2=n2;i2>0;i1--){

		result = result * (i1/(float) i2);
		i2--;	
	}

	return result;
}

int main(){

	int n1,n2;

	scanf("%d %d",&n1,&n2);
	printf("%d",comb(n1,n2));

	return 0;
}