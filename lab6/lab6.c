#include <stdio.h>


/*--part1--*/ 

// function equivalent of 2*x^2-3, matrix index value rule mentioned in assignment
int get_valid_int(int x){
	return 2 * x * x - 3;
}

// returns average of sum of values in matrix at matrix[i][j] where i+j is even
float average_finder(int length, int width){
	float average;	// average of index values
	float sum = 0;	// sum of index values
	int sum_num = 0;// number of index values that are summed
	printf("Average Finder\n\n");

	int index_value;// index value in the array
	int i, j, n = 1;// coords in matrix and n for valid index value calculation
	printf("Matrix:\n");	// calculate and print matrix and sum valid values
	for(i = 0; i < length; ++i){
		for(j = 0; j < width; ++j){
			index_value = get_valid_int(n);	// get index value
			printf("%d\t", index_value);	// print it
			
			if(n % 2){	// if i+j is even (n is odd when it happens, so equivalent)
				sum += index_value;	// add to the sum
				++sum_num;		// increase number of numbers added to sum
			}

			++n;	// next value index
		}
		printf("\n");
	}

	average = sum / sum_num;	// calculate the average

	return average;
}


/*--part2--*/

// combines two strings (e.g "abcdefg"+"1234"="a1b2c3d4efg") 
void intervew(const char * s1, const char * s2, char * s3){
	int i_s1, i_s2, i_s3;	// indexes for strings s1, s2, and s3 respectively
	for(i_s1 = 0, i_s2 = 0, i_s3 = 0; s1[i_s1] != 0 || s2[i_s2] != 0;){
		if(s1[i_s1] != 0) s3[i_s3++] = s1[i_s1++]; // if not end of the string then add to s3, also gets to next index of both
		if(s2[i_s2] != 0) s3[i_s3++] = s2[i_s2++]; // same as above but for second string
	}	
	s3[i_s3] = 0;// set the end of result string
}


int main(){
	/*--part1--*/
	printf("\nResult = %.1f\n\n\n", average_finder(3, 5));// average of a matrix with size 3x5
	printf("\nResult = %.1f\n\n\n", average_finder(4, 9));// average of a matrix with size 4x9
	
	
	/*--part2--*/
	char result[300];	// result array
	char user_input1[150], user_input2[150];	// inputs

	printf("Enter first string:\n");
	scanf("%s", user_input1);
	printf("Enter second string:\n");
	scanf("%s", user_input2);
	
	intervew(user_input1, user_input2, result);
	
	printf("\nResult string:\n%s\n", result);

	return 0;
}
