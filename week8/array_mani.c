#include <stdio.h>

void manipulation(int size,int list[],int input,int opr[input][3]){

	for(int a=0;a<input;a++){
		for(int i=opr[a][0];i<opr[a][1];i++){
			list[i]+=opr[a][2];
		}
	}

	int highest = list[0];
	for(int i=1;i<size;i++){
		if(list[i]>highest){
			highest = list[i];
		}
	}

	printf("%d",highest);
	
}
int main(){

	int size,input;
	scanf("%d",&size);
	int numbers[size];
	for(int i=0;i<size;i++){
		numbers[i] = 0;
	}
	scanf("%d",&input);
	int queries[input][3];
	for(int i=0;i<input;i++){
		int i1,i2,i3;
		scanf("%d",&i1);
		scanf("%d",&i2);
		scanf("%d",&i3);
		queries[i][0]=i1;
		queries[i][1]=i2;
		queries[i][2]=i3;
	}

	manipulation(size,numbers,input,queries);
	return 0;
}