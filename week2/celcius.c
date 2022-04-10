#include <stdio.h>

int main() {
    
    float temp=0;

    printf("Input as Fahrenheit:");
    scanf("%f",&temp);

    temp = (float)5/9 * (temp-32);

    printf("Output as Celcius: %f\n",temp);
}