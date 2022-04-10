#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define R 1 // radius equals 1

int main(){

	int ite = 0; // iteration number
	printf("Iterations:");
	scanf("%d",&ite);
	while(ite<=0){
		printf("It must be greater than 0:");
		scanf("%d",&ite);
	}

	while(ite>0){

		srand(time(NULL));
		double pointx = 0, pointy=0; // (x,y) coordinates
		int points_sum = 0; //points inside the circle

		for(int i=0;i<ite;i++){

			pointx = (double) rand() / RAND_MAX; // random coordinates between 0-1
			pointy = (double) rand() / RAND_MAX;

			if( (pointy*pointy) + (pointx*pointx) <= (R*R)){ // (x^2 + y^2) must be less than R^2 

				points_sum += 1; 
			}
		}

		double pi = (double)(points_sum * 4)/ite; 

		printf("%f\n",pi);

		printf("Iterations(0 for exit):");
		scanf("%d",&ite);
	}
	return 0;
}