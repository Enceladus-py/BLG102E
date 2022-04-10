#include <stdio.h>

int main(){

	float temperature=0,alt=0,boil=100;
    char type;

	printf("Input a temperature:");
	scanf("%f %c",&temperature,&type);

	printf("Altitude(meters):");
	scanf("%f",&alt);
    
    boil = boil - (alt/300);

	if(type=='F'){

		boil = (boil*9/5) + 32;
	}

	if(temperature==0){

        printf("Water is solid.\n");
    }

    else if(temperature==boil){

       	printf("Water is gaseous.\n");
    }

    else{
            
        printf("Water is liquid.\n");
    }

    printf("temperature=%f boiling=%f\n",temperature,boil);

    return 0;
}