#include <stdio.h>
#include <stdlib.h>
#define CANDIDATE_NUMBER 4

typedef struct {
    char letter;
    int votes;
    float percent;
}Candidate;

int toString(char a[], int size); // converts string to integer
float compare_floats(float n1, float n2); // finds the difference between floats
void read_file(FILE* src, Candidate* candidates); // reads the votes from file and calculates each candidates votes
void find_winner(Candidate* candidates); // determines the winner


int main(int argc, char* argv[]){

    if(argc!=2){
        printf("Inputs are not correct!\n");
        return 1;
    }

    FILE* src = fopen(argv[1],"r");
    if(src==NULL){
        printf("File can't opened.\n");
        return 1;
    }

    Candidate* candidates = NULL;
    for(int i=0;i<CANDIDATE_NUMBER;i++){
        candidates = realloc(candidates,sizeof(Candidate)*(i+1));
        (candidates+i)->letter = i+65; // ASCII values. 65 = 'A'
        (candidates+i)->votes = 0; // initial values are 0
        (candidates+i)->percent = 0; 
    }

    read_file(src, candidates);
    find_winner(candidates);
    free(candidates);
    candidates = NULL;
    src = NULL; // free(src) in read_file function
    
    return 0;
}

int toString(char a[], int size) {
  int c,offset=0, n=0;

  for (c = offset; c<size; c++) {
    n = n * 10 + a[c] - '0';
  }

  return n;
}

float compare_floats(float n1, float n2){

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

void read_file(FILE* src, Candidate* candidates){

    int size = 0,space_count=0; // size for the string, in each while loop it increases by 1 until it reaches space
    char s, *str = NULL;

    do{ 
        s = fgetc(src);

        if(feof(src)){ // end of file
            candidates[space_count].votes += toString(str,size); 
            fclose(src);
            break;
        }

        else if(s=='\n'){ 
            candidates[space_count].votes += toString(str,size); 
            space_count = 0;
            size = 0;
        }

        else if(s==' ' || s=='\t'){

            candidates[space_count].votes += toString(str,size); 
            space_count++;
            size=0;

            while((s=fgetc(src))){
                if(s!=' ' && s!='\t'){
                    str = realloc(str,sizeof(char)*(size+1));
                    *(str+size) = s;
                    size++;
                    break;
                }
            }            
        }

        else if(s!=' '){
            str = realloc(str,sizeof(char)*(size+1));
            *(str+size) = s;
            size++;
        }

    }while(1);   

    free(str);
    str = NULL;
}

void find_winner(Candidate* candidates){
    
    float sum_votes = 0;

    for(int i=0;i<CANDIDATE_NUMBER;i++){
        sum_votes += candidates[i].votes;
    }

    float fmax[2]={0,0},smax[2]={0,0}; //first and second max numbers in the case of all percents<50

    for(int i=0;i<CANDIDATE_NUMBER;i++){
        candidates[i].percent = (candidates[i].votes/sum_votes)*100;

        if(candidates[i].percent>50){ // winner found, function ends
            printf("Winner: %c\n",candidates[i].letter);
            return;
        }

        if(fmax[0]<candidates[i].percent){ // fmax = new max number and smax is the old max
            smax[0] = fmax[0];
            smax[1] = fmax[1];
            fmax[0] = candidates[i].percent;
            fmax[1] = i;
        }

        else if(smax[0]<candidates[i].percent){ // smax is changed to a bigger number
            smax[0] = candidates[i].percent;
            smax[1] = i;
        }
    }

    // (int) for convert float to int
    printf("Second round: %c and %c\n",candidates[(int)fmax[1]].letter,candidates[(int)smax[1]].letter); 

}