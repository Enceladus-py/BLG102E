#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 
int* dynamicArray(int n, int queries_rows, int queries_columns, int** queries, int* result_count) {
/*
Your function should:
    1) Create a 2-D array whose columns are appendable (dynamic)
    2) Create a 1-D dynamic array which will be used for storing the lastAnswer variables
    3) Handle 2 types of queries and fills in the aforementioned 2-D and 1-D arrays, based on the instructions
    4) Return the 1-D array and its size in the result_count variable
    5) Deletes the redundant variables which are created dynamically (by using malloc functions)
*/	
	int** dynamic_array = malloc(n * sizeof(int*));
	int* lens = malloc(n*sizeof(int));

	for(int i=0;i<n;i++){
		*(dynamic_array+i) = malloc(sizeof(int));
		*(lens+i) = 0;
	}

	int* answers = malloc(sizeof(int));
	int lastAnswer = 0;
	int a=0;

	for(int i=0;i<queries_rows;i++){
		if(queries[i][0]==1){
			int index = (queries[i][1]^lastAnswer)%n;
			*(*(dynamic_array+index)+lens[index]) = queries[i][2];
			lens[index]++;
			*(dynamic_array+index) = realloc(*(dynamic_array+index),sizeof(int)*(lens[index]+1));
		}
		else if(queries[i][0]==2){
			int index = (queries[i][1]^lastAnswer)%n;
			lastAnswer = dynamic_array[index][queries[i][2]%lens[index]];
			*(answers+a) = lastAnswer;
			answers = realloc(answers,sizeof(int)*(a+2));
			*(dynamic_array+index) = realloc(*(dynamic_array+index),sizeof(int)*(lens[index]+1));
			a++;

		}
	}

	free(lens);
	for(int i=0;i<n;i++){
		free(dynamic_array[i]);
	}
	
	*(result_count) = a;
	return answers;

}

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    
    int** queries = malloc(q * sizeof(int*));
    
    for (int i = 0; i < q; i++) {
        *(queries + i) = malloc(3 * sizeof(int));
        scanf("%d %d %d", &queries[i][0], &queries[i][1], &queries[i][2]);
    }
    
    int result_count;
    int* result = dynamicArray(n, q, 3, queries, &result_count);
    
    for (int i = 0; i < result_count; i++){
        printf("%d", *(result + i));
        printf("\n");
    }
    
    free(result);
    result = NULL;
    return 0;
}

