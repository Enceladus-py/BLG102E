#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
#define ARRAY_SIZE 10
 
void swap(int *first, int*second){
    int temp = *first;
    *first = *second;
    *second = temp;
}
 
void random_fill_array(int *arr){

    int i;
    for(i=0;i<ARRAY_SIZE;i++){
        *(arr+i) = rand() % 100;
    }
}
 
int main(){

    srand(time(0));

    int my_array[ARRAY_SIZE], prf,i;

    printf("RANDOM(1) OR INPUT(2):");
    scanf("%d",&prf);   

    if(prf==2){
        for(i=0; i<ARRAY_SIZE; i++)
	       scanf("%d",&my_array[i]);
    }
    else{
        for(i=0; i<ARRAY_SIZE; my_array[i++]=i);
        random_fill_array(my_array);
    }
    printf("ORIGINAL ARRAY: ");
    for (i = 0; i < ARRAY_SIZE; printf("%-5d", my_array[i++]));
    printf("\n");

    // Implement the swap op here.
    for(i=0; i<ARRAY_SIZE/2;i++){
        swap(my_array+i,my_array+ARRAY_SIZE-i-1);
    }
 
    printf("REVERSE ARRAY:  ");
    for (i = 0; i < ARRAY_SIZE; printf("%-5d", my_array[i++]));
    printf("\n");
 
    return EXIT_SUCCESS;
}
