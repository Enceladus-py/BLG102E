#include <stdio.h>

int main(){

	//getting input
	int size,range;
	scanf("%d",&size);
	int list[size];
	scanf("%d",&range);
	double answers[2*size];

	int input;
	for(int i=0;i<size;i++){
		scanf("%d",&input);
		list[i]=input;
	}

	int sum=0;
	for(int i=0;i<size;i++){
		sum +=list[i];
		answers[i] = sum/((double)i+1);
	}
	
	sum=0;
	for(int i=0;i<size;i++){
		sum+=list[i];
		if(i<range-1){
			answers[i+size] = 0;
		}
		else if(i==range-1){
			answers[i+size] = sum/((double)range);
		}
		else if(i!=size-1){
			sum-=list[i-range];
			answers[i+size] = sum/((double)range);
		}
		else{
			sum-=list[i-range];
			answers[i+size] = sum/((double)range);
		}
	}

	for(int i=0;i<2*size;i++){
		printf("%.3f ",answers[i]);
	}
	return 0;
}