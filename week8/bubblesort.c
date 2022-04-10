#include <stdio.h>

void sort(int input[],char n,int size){

	int list[size];
	for(int i=0;i<size;i++){
		list[i] = input[i];
	}

	if(n=='a'){
		for(int x=0;x<size-1;x++){

			for(int i=size-1;i>x;i--){

				if(list[i]<list[i-1]){
					
					int temp = list[i];
					list[i]=list[i-1];
					list[i-1]=temp;
				}

			}
		}
	}
	else if(n=='d'){
		for(int x=size-1;x>0;x--){

			for(int i=0;i<x;i++){

				if(list[i]<list[i+1]){
					
					int temp = list[i];
					list[i]=list[i+1];
					list[i+1]=temp;
				}
			}
		}
	}
	for(int i=0;i<size;i++){
		printf("%d ",list[i]);
	}
}

int main(){

	int size;
	printf("List size: ");
	scanf("%d",&size);
	int list[size];
	int input;
	printf("Numbers: ");
	for(int i=0;i<size;i++){
		scanf("%d",&input);
		list[i] = input;
	}

	//printf("Ascending: ");
	sort(list,'a',size);
	//printf("\n");	
	//printf("Descending: ");
	//sort(list,'d',size);	
	return 0;
}