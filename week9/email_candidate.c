#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define randnum(min, max) ((rand() % (int) (((max) + 1) - (min))) + (min))

void f1(char *name,char *surname,char *year){

	char* s = malloc(100*sizeof(char));
	int i,y;

	for(i=0;i<1;i++){
		*(s+i) = *(name+i);
	}
	for(i=1,y=0;y<strlen(surname);y++){
		*(s+i) = *(surname+y);
		i++;
	}
	for(i=strlen(surname)+1,y=strlen(year)-2;y<strlen(year);y++){

		*(s+i)=*(year+y);
		i++;
	}

	char* temp="@itu.edu.tr";
	for(i=strlen(surname)+3,y=0;y<strlen(temp);y++){
		*(s+i) = *(temp+y);
		i++;
	}

	printf("Email Candidate 1: %s\n",s);

	//free(s);free(temp);
}

void f2(char *name,char *surname,char *year){

	char *s = malloc(sizeof(char)*100);
	int i,y;

	for(i=0;i<2;i++){
		*(s+i) = *(name+i);
	}

	for(i=2,y=0;y<2;y++){
		*(s+i) = *(surname+y);
		i++;
	}

	for(i=4;i<8;i++){
		*(s+i) = randnum(48,57);
	}

	char* temp="@itu.edu.tr";
	for(i=8,y=0;y<strlen(temp);y++){
		*(s+i) = *(temp+y);
		i++;
	}

	printf("Email Candidate 2: %s\n",s);
	//free(s);free(temp);
}

void f3(char *name,char *surname,char *year){
	
	char *s = malloc(sizeof(char)*100);
	int i,y;

	for(i=0;i<strlen(surname);i++){
		*(s+i) = *(surname+i);
	}

	for(i=strlen(surname),y=0;y<strlen(name);y++){
		*(s+i) = *(name+y);
		i++;
	}

	for(i=strlen(name)+strlen(surname),y=0;y<strlen(year);y++){
		*(s+i) = *(year+y);
		i++;
	}

	char* temp="@itu.edu.tr";
	for(i=strlen(name)+strlen(surname)+strlen(year),y=0;y<strlen(temp);y++){
		*(s+i) = *(temp+y);
		i++;
	}

	printf("Email Candidate 3: %s\n",s);
	//free(s);free(temp);
}

int main(){

	srand(time(0));

	char* name,*surname,*year; 
	name = malloc(100*sizeof(char));
	surname = malloc(100*sizeof(char));
	year = malloc(100*sizeof(char));

	printf("Enter Your Name:");
	scanf("%s",name);
	printf("Enter Your Surname:");
	scanf("%s",surname);
	printf("Enter Your Birthyear:");
	scanf("%s",year);

	f1(name,surname,year);
	f2(name,surname,year);
	f3(name,surname,year);

	free(name);free(surname);free(year);
	
	return 0;
}