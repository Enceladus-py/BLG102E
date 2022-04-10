#include <stdio.h>
#include <stdlib.h>

#define M_PI 3.14159265358979323846264338327950288

double rect_area(double x,double y){
	return x*y;
}
double rect_perim(double x, double y){
	return (2*x) + (2*y);
}
double circumference(double r){
	return 2*M_PI*r;
}
double circle_area(double r){
	return M_PI*r*r;
}
int main(){

	char input;
	printf("Enter the shape type, e.g., rectangle, square, or circle\n");
	scanf("%c",&input);

	if (input == 'r' || input == 's'){

		double side1=0,side2=0;
		if (input == 's'){
			printf("Enter the side length of the square\n");
			scanf("%lf",&side1);
			side2=side1;
		}
		else{
			printf("Enter the side lengths of the rectangle\n");
			scanf("%lf %lf",&side1,&side2);
		}
		
		printf("Perimeter: %lf\n",rect_perim(side1,side2));
		printf("Area: %lf\n",rect_area(side1,side2));
	} 

	else if (input == 'c'){

		double radius=0;
		printf("Enter the radius of the circle\n");
		scanf("%lf",&radius);
		printf("Circumference: %lf\n",circumference(radius));
		printf("Area: %lf\n",circle_area(radius));
	} 

	return 0;
}