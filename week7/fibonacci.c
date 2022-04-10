#include <stdio.h>

int fibonacci(int index){

	if (index == 1){
		return 0;
	}
	else if (index == 2){
		return 1;
	}

	else{
		int sum = fibonacci(index-1)+fibonacci(index-2);
		return sum;
	}
}

int main(){

	int input;
	printf("Enter the index of the Fibonacci series\n");
	scanf("%d",&input);
	printf("%d",fibonacci(input));

	return 0;
}