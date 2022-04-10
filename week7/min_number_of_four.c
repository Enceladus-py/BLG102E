#include <stdio.h>
#include <stdlib.h>

int min_number_of_four(int n1,int n2,int n3,int n4){

	int array[] = {n1,n2,n3,n4};
	int smallest = n1;
	int y;

	for(y=0;y<3;y++){

		if (array[y]>array[y+1])
			smallest = array[y+1];
		else
			array[y+1]=smallest;

	}

	return smallest;
}

int main(){

	int n1,n2,n3,n4;

	printf("Enter the numbers\n");
	scanf("%d %d %d %d",&n1,&n2,&n3,&n4);
	printf("%d",min_number_of_four(n1,n2,n3,n4));

	return 0;
}