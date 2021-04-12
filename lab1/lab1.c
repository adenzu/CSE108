/* 

The variable names that used in this file have no relation with the ones in the pdf file. 

<?> in the functions means something other than void, you should find the correct type for these functions.

*/

#include <stdio.h>


void trigonometry_calculation(int a, int b, int c)
{
	printf("sinx = %f\n", (float) a / c);
	printf("cosx = %f\n", (float) b / c);
	printf("tanx = %f\n", (float) a / b);
}

void trigonometry(int a, int b, int c)
{
    trigonometry_calculation(a, b, c);
    return;
}

// changed int return type to unsigned long because it was overflowing otherwise
unsigned long age_calculation(int x)
{
    unsigned long seconds_equivalent = x * 365 * 24 * 60 * 60;
    return seconds_equivalent;
}

void age(int x)
{
    printf("You are %lu seconds\n", age_calculation(x));
    return;
}


int main()
{

	int a, b, c;
	int userAge;;

	printf("Enter side lengths of a right triangle:\n");

	printf("a: ");
	scanf("%d", &a);
	printf("b: ");
	scanf("%d", &b);
	printf("c: ");
	scanf("%d", &c);

    trigonometry(a, b, c);


    printf("Your age: ");
    scanf("%d", &userAge);

    age(userAge);

    return 0;
}
