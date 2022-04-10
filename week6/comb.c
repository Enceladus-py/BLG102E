#include <stdio.h>

int fact(int n){

    int sum = 1;

    for(int i=1;i<=n;i++){

        sum = sum * i;  
    }

    return sum;
}

int main(){

    int n1,n2,comb;

    scanf("%d %d",&n1,&n2);

    comb = fact(n1) / (fact(n2) * fact(n1-n2));
    printf("%d",comb);

    return 0;

}

