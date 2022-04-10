#include<stdio.h>
#include<stdlib.h>

int main(){
    
    //6,28,33550336,8128

    int number = 0;

    do{
        int sum = 0;

        printf("Input a number greater than 0 to calculate, enter 0 for exit:");
        scanf("%d",&number);

        for(int i=1;i<number;i++){

            if(number%i == 0){

                sum += i;
            }

        }

        if(number != 0){

            if(sum == number){
                printf("It's a perfect number!\n");
            }
            else{
                printf("It's not a perfect number!\n");
            }
        }
    }
    while(number > 0);

    printf("Program finished!\n");

    return 0;
}
