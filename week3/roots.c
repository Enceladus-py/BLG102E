#include <stdio.h>
#include <math.h>

int main()
{

    float a = 0, b = 0, c = 0;

    printf("Input for a, b and c:"); //coefficients
    scanf("%f %f %f", &a, &b, &c);

    float x1 = 0, x2 = 0;
    float dis = (b * b) - (4 * a * c); //discriminant

    x1 = (-b + sqrt(dis)) / 2 * a; //first root
    x2 = (-b - sqrt(dis)) / 2 * a; //second root

    if (dis > 0) {

        printf("Roots for the function: %.2f %.2f\n", x1, x2);
    } else if (dis == 0) {

        printf("Root for the function: %.2f\n", x1);
    } else {

        printf("This equation has no root.\n");
    }

    return 0;
}