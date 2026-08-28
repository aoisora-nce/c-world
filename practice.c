/* Author: Sarada
 * Code with Harry
 * Problem Practice Chapter 1/2/3
*/

#include <stdio.h>
#include <math.h>

int main() {
	// To check if a num is divisible by 97
	int num;
	printf("Enter a number: ");
	scanf("%d", &num);
	if (num % 97 == 0) {
		printf("The number %d is divisible by 97.", num);
	} else {
		printf("The number %d is not divisible by 97.\n\tQuotient=%d Remainder=%d \n", num, num/97, num%97);
	}
	// // ======= Area of a circle =======
	// int r;
	// printf("Enter radius of a circle (in m): ");
	// scanf("%d", &r);
	// printf("Area of a circle of radius %d is %.3f m².\n", r, M_PI*r*r);
	
	// // ======= Celcius to Fahrenheit =======
	// printf("\n");
	// float c, f;
	// printf("Enter temperature (in °C): ");
	// scanf("%f", &c);
	// f = (c*1.8)+32;
	// printf("%.2f °C is equals to %.2f °F. \n", c, f);
	
	// printf("ok %% \\ '' \"\"");
	
	return 0;
}
