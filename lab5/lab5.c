#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*--------------------PART 1--------------------*/

/* @brief   Function equivalent of x^2 + 5
 * @param   x       Input to get result for
 * @param   result  Pointer to store result
 */
void expression0(int x, int *result);

/* @brief   Function equivalent of 2x + 1
 * @param   x       Input to get result for
 * @param   result  Pointer to store result
 */
void expression1(int x, int *result);

/* @brief   Function equivalent of x^2
 * @param   x       Input to get result for
 * @param   result  Pointer to store result
 */
void expression2(int x, int *result);

/* @brief   Calculates and returns the sum of function results from 0 to given value
 * @param   func    Function to get results for the sum
 * @param   sum     Pointer to store sum
 * @param   n       Upper limit for function input value
 */
void addition(void (*func)(int, int *), int *sum, int n);

/* @brief   Calculates three sum for three different functions with input range [0, n]
 * @param   sumArray    Array to store sum of the functions
 * @param   n           Upper limit for function input value
 */
void calculation(int *sumArray, int n);


/*--------------------PART 2--------------------*/
#define MATRIX_WIDTH  10    // Matrix width
#define MATRIX_HEIGHT 10    // Matrix height

/* @brief   Returns random integer between given bounds
 * @param   lower   Lower bound of the range, included
 * @param   upper   Upper bound of the range, excluded
 * @return          Random integer between given bounds
 */
int randomRange(int lower, int upper);

/* @brief   Fills given array with MATRIX_WIDTH width with random integers that are 2-digit
 * @param   array   The array that is filled randomly
 */
void createArray(int (*array)[MATRIX_WIDTH]);

/* @brief   Prints given array with MATRIX_WIDTH width
 * @param   array   The array that is printed
 */
void printMatrix(int (*array)[MATRIX_WIDTH]);

/* @brief   Let's user to examine elements of matrix
 * @param   array   The array that is examined
 */
void matrixExaminer(int (*array)[MATRIX_WIDTH]);


int main(){

    // PART 1 
    int sumRange;                   // Upper limit for sum (n)
    int sumArray[3] = {0, 0, 0};    // Array to store sums

    // Get upper limit
    printf("n: ");
    scanf("%d", &sumRange);

    calculation(sumArray, sumRange);    // Get the sums

    // Inform the user
    printf("Sum of expression0: %d\n", sumArray[0]);
    printf("Sum of expression1: %d\n", sumArray[1]);
    printf("Sum of expression2: %d\n", sumArray[2]);


    // PART 2
    srand(time(0)); // Set random seed

    int myMatrix[10][10];   // Matrix that will be filled with random integers

    createArray(myMatrix);      // Fill the matrix
    matrixExaminer(myMatrix);   // Let user to examine

    return 0;
}


/*--------------------PART 1--------------------*/

void expression0(int x, int *result){
    *result = x * x + 5;
}

void expression1(int x, int *result){
    *result = 2 * x + 1;
}

void expression2(int x, int *result){
    *result = x * x;
}

void addition(void (*func)(int, int *), int *sum, int n){
    int i;          // Iteration variable
    int funcResult; // Function result for one input
    
    for(i = 0; i <= n; ++i){
        func(i, &funcResult);   // Get result
        *sum += funcResult;     // Add result to sum
    }
}

void calculation(int *sumArray, int n){
    addition(expression0, sumArray + 0, n); // Calculate sum for first expression and store at sumArray[0]
    addition(expression1, sumArray + 1, n); // Calculate sum for second expression and store at sumArray[1]
    addition(expression2, sumArray + 2, n); // Calculate sum for third expression and store at sumArray[2]
}


/*--------------------PART 2--------------------*/

int randomRange(int lower, int upper){
    return rand() % (upper - lower) + lower;
}

void createArray(int (*array)[MATRIX_WIDTH]){
    int i, j;   // Iteration variables

    // For every row column position in array
    for(i = 0; i < MATRIX_HEIGHT; ++i){
        for(j = 0; j < MATRIX_WIDTH; ++j){
            array[i][j] = randomRange(10, 100); // Set to a random 2-digit integer
        }
    }
}

void printMatrix(int (*array)[MATRIX_WIDTH]){
    int i, j;   // Iteration variables

    // For every row column position in array
    for(i = 0; i < MATRIX_HEIGHT; ++i){
        for(j = 0; j < MATRIX_WIDTH; ++j){
            printf("%d ", array[i][j]); // Print value at position
        }
        printf("\n");   // Get to new line
    }
}

void matrixExaminer(int (*array)[MATRIX_WIDTH]){

    int userI, userJ;   // User row and column inputs

    // Print matrix
    printf("\n\nMatrix:\n\n");
    printMatrix(array);

    while(1){
        printf("\nWhich element of the matrix do you want to reach?\n");
        
        // Get desired row and column index
        printf("i: "); scanf("%d", &userI);
        printf("j: "); scanf("%d", &userJ);

        // Check if indexes are valid
        if(userI < MATRIX_HEIGHT && userI > -1 && userJ < MATRIX_WIDTH && userJ > -1)
            printf("%d. row %d. column of the matrix is %d\n", userI, userJ, array[userI][userJ]);  // Print the value if valid
        else{
            printf("Invalid input. Terminating...\n");  // Inform if not
            break;                                      // and terminate
        }

    }
}


