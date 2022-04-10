#include <stdio.h>

int main()
{

    float temperature = 0;
    char type;

    printf("Input a temperature:");
    scanf("%f %c", &temperature, &type);

    if ((type == 'C' && temperature == 0) || (type == 'F' && temperature == 32)) {

        printf("Water is solid.\n");
    } else if ((type == 'C' && temperature == 100) || (type == 'F' && temperature == 212)) {

        printf("Water is gaseous.\n");
    } else {

        printf("Water is liquid.\n");
    }

    return 0;
}