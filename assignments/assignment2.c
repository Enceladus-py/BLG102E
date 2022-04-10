#include <stdio.h>
#include <stdlib.h> //for abs() function
#include <math.h> //for pow() function

void layout(int rows, int seats, int *aisles, int num_of_aisles); // prints the layout for the plane
int* reservation(int rows, int seats, int input); // reserves seats according to given rules
double dist(int s1y, int s1x, int s2y, int s2x); // calculates distance and scores for the seats
int seats_reload(int rows, int seats); // if seats are just reserved ('+'), this function will turn them to already reserved ('X')
double compare_doubles(double n1, double n2); // compares two double numbers (abs function can be used with integers)

int all_seats[99][20]; // 2d array for the seats
double scores[99][20]; // 2d array for the seat scores
int max_i_j[2] = {0,0}; // x-y coordinates of the seat with the max score
int aisles[5]; // array for storing aisles placements 

int main(){

	int rows,seats,num_of_aisles,input,all_seats_reserved=0;

	printf("Number of rows:");
	scanf("%d",&rows);
	printf("Number of seats per row:");
	scanf("%d",&seats);
	printf("Number of aisles:");
	scanf("%d",&num_of_aisles);

	for(int i=0;i<5;i++){
		aisles[i] = 100; //put aisles in the end by default
	}

	for(int i=0;i<99;i++){
		for(int j=0;j<20;j++){
			all_seats[i][j] = 0; // 0-> - , 1-> X , 2-> +
			scores[i][j] = 0; // all scores are 0 at the beginning 
		}
	}


	for(int i=0;i<num_of_aisles;i++){

		printf("Add aisle %d after seat:",(i+1));
		scanf("%d",&aisles[i]); 
	}
	printf("\n");

	while(input!=-1){
		
		if(max_i_j[0]!=100 && max_i_j[1]!=100){
			layout(rows,seats,aisles,num_of_aisles);
		}

		all_seats_reserved = seats_reload(rows,seats); // '+' seats will turn into 'X', returns 1 if all seats reserved

		printf("\n");
		printf("The number of people in the reservation\n");
		printf(" (0: print current reservations, -1: exit):");
		scanf("%d",&input);

		if(input==-1) { break; }
		else if(input==0) { continue; }

		else{

			while(all_seats_reserved==1){
				printf("\nNo available seats for the requested reservation!\n");
				printf("\n");
				printf("The number of people in reservation\n");
				printf(" (0: print current reservations, -1: exit):");
				scanf("%d",&input);
				if(input==0) {break;}
				else if(input==-1) {return 0;}
			}

			int* max_i_j = reservation(rows,seats,input);

			if(max_i_j[0]==100 && max_i_j[1]==100){ // input is bigger than number of seats in a row
				printf("\nNo available seats for the requested reservation!\n");
			}

			
			else{
			
			
				printf("Reserved seats: ");

				for(int n=0;n<input;n++){
					printf("%d%c ",*(max_i_j)+1,*(max_i_j+1)+65+n); // prints letters according to ascii values
				}
				printf("\n");
				printf("\n");
			
			}
		}
	}

	return 0;
}

void layout(int rows, int seats, int *aisles, int num_of_aisles){

	//According to ASCII standards, 65 = 'A', 66 = 'B' ...

	for(int i=0;i<seats;i++){

		if(i==0) { printf("   %c",(i+65));}
		else {printf("  %c",(i+65));}
	

		for(int k=0;k<num_of_aisles;k++){

			if(aisles[k] - 1  == i){
				printf("  |   |");
				break;
			}
		}
	}

	printf(" \n");

	for(int x=0;x<rows;x++){

		if (x<9){printf("%d  ",x+1);}
		else{printf("%d ",x+1);}

		for(int i=0;i<seats;i++){

			if(all_seats[x][i]==0){
				printf("-  ");
			}

			else if(all_seats[x][i]==1){
				printf("X  ");
			}

			else if(all_seats[x][i]==2){
				printf("+  ");
			}

			for(int k=0;k<num_of_aisles;k++){

				if(aisles[k] - 1  == i){
					printf("|   |  ");
					break;
				}
			}
		}
		printf(" \n");
	}
}

double dist(int s1y, int s1x, int s2y, int s2x){

	// s1y, s1x are the x-y coordinates of the empty seats
	// s2y, s2x are the x-y coordinates of the reserved seats

	int temp1=0,temp2=0; 

	if(all_seats[s2y][s2x]==1){

		for(int i=0;i<5;i++){ // aisles are equivalent to one seat space
			if(aisles[i]<=s1x){
				temp1++;
			}
			if(aisles[i]<=s2x){
				temp2++;
			}
		}

		s1x += temp1;
		s2x += temp2;

		double distance = abs(s1y-s2y) + (abs(s1x-s2x)/2.0);
	
		if (distance!=0){
			double new_distance = (100 - pow(100,1/distance));
			if((s1y==2 && s1x==6) || (s1y==3 && s1x==0)) {
			}
			return new_distance;
		}
		return distance;
	}

	return 0;
}

int seats_reload(int rows, int seats){

	int rsv = 0;

	for(int i=0;i<rows;i++){
		for(int j=0;j<seats;j++){
			if(all_seats[i][j]==2){
				all_seats[i][j]=1;
			}	
			if(all_seats[i][j]==1){
				rsv++;
			}
		}
	}

	if(rsv==(rows*seats)){
		return 1; // all seats reserved
	}

	return 0;
}

double compare_doubles(double n1, double n2){

	if(n1<n2){
		return n2-n1;
	}
	else if(n1>n2){
		return n1-n2;
	}
	else{
		return 0;
	}
}

int* reservation(int rows, int seats, int input){


	if(input==1){

		for(int r=0;r<rows;r++){
			for(int c=0;c<seats;c++){
					scores[r][c] = 0; // reset scores
				if(all_seats[r][c]==0){
					for(int i=0;i<rows;i++){
						for(int j=0;j<seats;j++){
							scores[r][c] += dist(r,c,i,j);
						}
					}	
				}
			}
		}

		double max_score = -99999; //scores may be less than 0, so it should be a small negative number

		for(int i=rows-1;i>=0;i--){
			for(int j=seats-1;j>=0;j--){
				if(max_score<=scores[i][j] && all_seats[i][j]==0){
					max_score = scores[i][j];
					max_i_j[0] = i;
					max_i_j[1] = j;
				}
			}
		}

		all_seats[max_i_j[0]][max_i_j[1]] = 2; // seat with the max score is now '+' (just reserved)
		
	}
	
	else if (input<=seats){

		int num=0,a=0;
		double blocks[(seats-input+1)*rows][4]; // max possible number of seat blocks 

		for(int i=0;i<(seats-input+1)*rows;i++){
			blocks[i][3] = 0; //number of aisles in the seat block
			blocks[i][2] = 0; //score
			blocks[i][1] = 0; //start point y coordinate
			blocks[i][0] = 0; //start point x coordinate
		}

		for(int i=0;i<rows;i++){
			for(int j=0;j<seats-input+1;j++){

				num=0;
				if(all_seats[i][j]==1){
					continue;
				}

				else if(all_seats[i][j]==0){

					for(int x=0;x<input;x++){
						if(all_seats[i][j+x]==0){
							num++;
						}
						else{
							break;
						}
					}

					if(num==input){ // a seat block is found

						blocks[a][0] = i;
						blocks[a][1] = j;

						for(int n=0;n<num;n++){
							for(int r=0;r<rows;r++){
								for(int c=0;c<seats;c++){
									blocks[a][2] += dist(blocks[a][0],blocks[a][1]+n,r,c);
								}
							}
						}
						a++;
					}
				}
			}
		}		

		if(a==0){ // no seat block is found
			max_i_j[0] = 100;
			max_i_j[1] = 100;
		}

		else{

			for(int i=0;i<a;i++){
				for(int x=0;x<5;x++){
					for(int j=1;j<input;j++){
						if(blocks[i][1]+j-1==aisles[x]-1 && blocks[i][1]+j==aisles[x]){
							blocks[i][3]++;
							break;
						}
					}
				}
			}

			double max_score = -99999; // scores may be less than 0, so it should be a small negative number
			int min_aisles = 5; // min possible aisles in a seat block

			for(int i=a-1;i>=0;i--){
				if(max_score<blocks[i][2]){
					max_score = blocks[i][2];
					max_i_j[0] = blocks[i][0];
					max_i_j[1] = blocks[i][1];
					min_aisles = blocks[i][3];
				}
				else if(compare_doubles(max_score,blocks[i][2])<0.001 && blocks[i][3]<=min_aisles){ 
					// exact equality is impossible between double numbers with fractions, 0.001 is a so small difference (nearly equal)
					max_score = blocks[i][2];
					max_i_j[0] = blocks[i][0];
					max_i_j[1] = blocks[i][1];
					min_aisles = blocks[i][3];
				}
			}

			for(int n=0;n<input;n++){
				all_seats[max_i_j[0]][max_i_j[1]+n] = 2; // seats are now reserved '+'
			}
		}
	}

	else{
		max_i_j[0] = 100; // 100 is a random value, it indicates that input is bigger than number of seats in a row
		max_i_j[1] = 100;
	}

	return max_i_j;
}
