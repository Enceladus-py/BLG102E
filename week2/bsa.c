#include <stdio.h>
#include <math.h>

int main(){
   
   double height=0, weight=0; 

   printf("Input Height(cm):"); //input for height in cm
   scanf("%lf",&height);

   printf("Input Weight(gr):"); //input for weight in gr
   scanf("%lf",&weight);

   double bsa = 0;
   bsa = 0.0003207 * pow(height,0.3) * pow(weight,(0.7285)-(0.0188*log10(weight))); //formula for calculating Body Surface Area

   printf("The BSA is: %.2lf\n",bsa);
}   