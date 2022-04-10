#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    
    srand(time(NULL));

    int win = 0;
    int lose = 0;
    int loop = 0;

    while(loop<100000){

    	int dice1 = rand() % 6 + 1;
	    int dice2 = rand() % 6 + 1;
        int sum = dice1 + dice2;

		if ( sum == 7 || sum == 11){
			//printf("Player wins!\n");
			win++;
		}
	    
	    else if (sum == 2 ||sum == 3 ||sum == 12){
	    	//printf("Player loses!\n");
	    	lose++; //empty line
	    }

	    else{
	    	
    		int new_sum = 0;
	        
	 	    while(new_sum != 7 && new_sum != sum){

	 	    	dice1 = rand() % 6 + 1;
		        dice2 = rand() % 6 + 1;
	 	        new_sum = dice1 + dice2;

	 	        if (new_sum == sum){
	 	        	//printf("Player wins!\n");
	 	        	win++;
	 	        }

	 	    }

	 	    if(new_sum==7){
	 	    	lose++;
	 	    }

	    }

	    loop++;
    }

    printf("Probability of winning: %.2f\n",win/100000.0);
    printf("Probability of losing: %.2f\n",lose/100000.0);
    return 0;
}