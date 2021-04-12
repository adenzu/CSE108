#include <stdio.h>



void russian_multiplication(unsigned int * multiplicand, unsigned int * multiplier);
void multiply_polynomials(double * a3, double * a2, double * a1, double * a0, double * b3, double * b2, double * b1, double b0);


int main(){
	// Some values for the multiplicand and multiplier in the russian multiplication
	unsigned int first = 37, second = 146;
	russian_multiplication(&first, &second);
	printf("= %u\nMultiplier = %u\n", first, second); // print the results

	// again some random values, for the polynomial multiplication
	double a = 1, b = 4, c = 5, d = 3, e = 6, f = 9, g = 3, h = 1;
	multiply_polynomials(&a, &b, &c, &d, &e, &f, &g, h);
	printf("%.2lfx^6 + %.2lfx^5 + %.2lfx^4 + %.2lfx^3 + %.2lfx^2 + %.2lfx + %.2lf\n", a, b, c, d, e, f, g); // print the results
	return 0;
}



void russian_multiplication(unsigned int * multiplicand, unsigned int * multiplier){
	unsigned int result = 0;	// result of the multiplication

	// parameters are modified in the process, so print before starting
	printf("%u * %u = ", *multiplicand, *multiplier);

	// loop
	while(1){
		// if multiplier value is odd
		if(*multiplier % 2){
			printf("%u ", *multiplicand);		// print added number
			if(*multiplier !=  1) printf("+ ");	// only print if multiplier value is not 1, we dont want + sign before =
			result += *multiplicand;		// add to the result
		}
		*multiplicand <<= 1;			// binary operator version of multiplying by 2
		// again check if multiplier value is 1 or not, if it's not 1 then proceed
		if(*multiplier != 1) *multiplier >>= 1;	// binary operator version of dividing by 2
		else break;	// if it's 1 then break the loop
	}

	// return result value through the multiplicand parameter
	*multiplicand = result;
}


void multiply_polynomials(double * a3, double * a2, double * a1, double * a0, double * b3, double * b2, double * b1, double b0){
	// new variables to store multiplication results of coefficients of polynomials
	// without altaring them in the process
	double x6 = 0, x5 = 0, x4 = 0, x3 = 0, x2 = 0, x1 = 0, x0 = 0;

	// just some regular polynomial coefficient multiplication
	x6 = *a3 * *b3;
	x5 = *a3 * *b2 + *a2 * *b3;
	x4 = *a3 * *b1 + *a2 * *b2 + *a1 * *b3;
	x3 = *a3 * b0  + *a2 * *b1 + *a1 * *b2 + *a0 * *b3;
	x2 = *a2 * b0  + *a1 * *b1 + *a0 * *b2;
	x1 = *a1 * b0  + *a0 * *b1;
	x0 = *a0 * b0;

	// return result coefficients through parameters
	*a3 = x6; *a2 = x5; *a1 = x4; *a0 = x3; *b3 = x2; *b2 = x1; *b1 = x0;

}
