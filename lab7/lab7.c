#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*---part1---*/

/* @brief       Checks if given array of integers is palindrome or not
 * @param   a   Given array to be checked
 * @param   n   Length of the given array
 * @return      1 if given array is palindrome, 0 otherwise
 */
int check_palindrome(int a[], int n){
    if(n < 2)
        return 1;
    else
        return (a[0] == a[n-1]) && check_palindrome(a + 1, n - 2);
}


/*---part2---*/

/* @brief           Returns a random integer in given range
 * @param   lower   Lower bound of the range
 * @param   upper   Upper bound of the range
 * @return          Random integer in given range
 */
int random_int_range(int lower, int upper){
    return rand() % (upper - lower) + lower;
}

/* @brief           Fills given integer array with random integers
 * @param   lower   Lower bound of the range
 * @param   upper   Upper bound of the range
 * @param   arr     Array to be filled
 * @param   len     Length of the given array
 */
void random_int_array(int lower, int upper, int arr[], int len){
    while(len--) arr[len] = random_int_range(lower, upper);
}

/* @brief                   Searchs given integer in given integer array
 * @param   arr             Array to be filled
 * @param   input_number    The integer that is searched
 * @param   arr_len         Length of the given array
 * @return                  1 if searched integer is found, 0 otherwise
 */
int search_element(int arr[], int input_number, int arr_len){
    if(arr_len)
        return (arr[0] == input_number) || search_element(arr + 1, input_number, arr_len - 1);
    else 
        return 0;
}

/* @brief       Prints given array
 * @param   arr Array to be printed
 * @param   len Length of the given array
 */
void print_array(int arr[], int len){
    for(int i = 0; i < len; ++i) printf("%d ", arr[i]);
}


/*---part3---*/

/* @brief       Returns cosine value of given radian value
 * @param   n   Starting point of the iteration of calculation, has to be greater than 0
 * @param   x   Radian value
 * @return      Cosine value of given radian value
 */
float my_cos(int n, float x){
    if(n < 20)
        return 1 - ((x * x) / ((2 * n - 1) * (2 * n))) * my_cos(n + 1, x);
    else 
        return 1;
}

#include <math.h>
int main(){

    /*---part1---*/
    int user_input;                 // One input of user in each loop               
    int palindrome_test_array[50];  // User's array of inputs
    int array_len;                  // Number of inputs that are read

    printf("Enter set of integers to test them as an array if it's palindrome or not:\n(enter -1 to stop)\n");
    for(array_len = 0; array_len < 50; ++array_len){    // Read inputs until 50 of them are read
        scanf("%d", &user_input);                       // Read input
        if(user_input == -1) break;                     // Terminate the loop if it's -1
        palindrome_test_array[array_len] = user_input;  // Put it to the array to be checked otherwise
    }

    // Check the array and print corresponding information
    if(check_palindrome(palindrome_test_array, array_len))
        printf("Your input is a palindrome\n");
    else
        printf("Your input is not a palindrome");

    printf("\n\n");


    /*---part2---*/
    srand(time(0)); // To have original random numbers in each run

    // Array of integers that number is searched in, and number that is searched
    int random_int_array_pool[20], searched_number;

    random_int_array(0, 100, random_int_array_pool, 20);    // Fill the array randomly
    
    // Print the array for user to see
    print_array(random_int_array_pool, 20); 
    printf("\nEnter numbers to search in the array above of randomly generated integers:\n(enter -1 to stop)\n");
    while(1){

        scanf("%d", &searched_number);      // Get searched number
        if(searched_number == -1) break;    // Terminate the loop if it's -1

        // Print corresponding information about the searched number's state of being in the array or not
        printf("Number %d is ", searched_number);
        if(search_element(random_int_array_pool, searched_number, 20))
            printf("in the array.\n");
        else
            printf("not in the array.\n");
    }

    printf("\n\n");


    /*---part3---*/
    float radian_value; // User's input value that will be passed to cos

    // Get the radian value from the user
    printf("Enter a radian value to see it's cos value: ");
    scanf("%f", &radian_value);

    // Inform the user
    printf("Our method of cos calculation found: %f\n", my_cos(1, radian_value));
    printf("True value: %f\n", cos(radian_value));


    return 0;
}