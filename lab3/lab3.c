#include <stdio.h>


/* @brief   Gets <num_inputs> number of inputs and calculates and prints maximum difference between consecutive input numbers
 * @param   num_inputs  Number of inputs that will be read.
 * @return              Maximum difference between consecutive input numbers
 */
int find_max_distance(int num_inputs);

/* @brief   Gets as many inputs until '-1' is entered, then calculates and prints average of odd numbers that are entered
 */
void find_odd_average();


int main(){
    find_max_distance(5);
    find_odd_average();
    return 0;
}


int find_max_distance(int num_inputs){

    int current_input = 0;      // Input that is processing in current iteration
    int previous_input = 0;     // Input from the previous iteration
    int max_difference = 0;     // Maximum difference between two consecutive numbers
    int current_difference = 0; // Calculated difference between current input and previous input, always positive

    // Inform the user
    printf("Please enter %d numbers:\n", num_inputs++);

    int i;  // Iteration variable
    for(i = 1; i < num_inputs; ++i){

        printf("%d : ", i);
        scanf("%d", &current_input);    // Get the input

        // Calculate the difference according to greatness of the input so that result is always positive
        // In short take the absolute of the difference
        current_difference = current_input > previous_input ? current_input - previous_input : previous_input - current_input;

        // Check if just now calculated difference is greater than the maximum until now, if so update
        max_difference = current_difference > max_difference ? current_difference : max_difference;

        // Set previous input
        previous_input = current_input;
    }

    // Inform the user about the result
    printf("Max distance between two consecutive nums: %d\n", max_difference);

    return max_difference;
}

void find_odd_average(){

    int sum = 0;            // Sum of odd numbers
    int number_of_odds = 0; // Number of odd numbers 

    // Inform user
    printf("Please enter positive numbers (enter -1 to stop entering):\n");

    int user_input; // User number input
    int i;          // Iteration variable
    
    // Doesn't have condition because -1 % 2 returns 1 (thus counts as odd) so have to check if input is -1
    // before checking if number is odd or not, in short took the condition and put in the loop block
    for(i = 1; ; ++i){

        printf("%d : ", i);
        scanf("%d", &user_input);   // Get the input number

        // Exit if -1 is entered
        if(user_input == -1)
            break;
        // If not check if number is odd, (2n + 1) % 2 = 1 => true 
        else if(user_input % 2){
            sum += user_input;  // Add the number to the sum 
            ++number_of_odds;   // Increase number of odds by one
        }
    }
    
    // Inform the user about the result
    printf("Average of odd numbers: %f\n", (float) sum / number_of_odds);
}