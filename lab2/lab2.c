#include <stdio.h>
#include <math.h>



const float PI = 3.14159f;


/* @brief Handles integer and complex number calculations
 */ 
void StandardCalculator();

/* @brief Handles perimeter and area calculations
 */ 
void AreaPerimeterCalculator();

/* @brief Handles temperature convertion calculations
 */ 
void TemperatureCalculator();

// @brief Handles integer addition and multiplication
void IntegerCalculator();

// @brief Handles complex number addition and multiplication
void ComplexCalculator();

// @brief Adds two given integers and returns the result
int IntegerAddition(int number1, int number2);

// @brief Multiplies two given integers and returns the result
int IntegerMultiplication(int number1, int number2);

// @brief Adds two given complex numbers and puts the result in given array
void ComplexAddition(const int complexNum1[2], const int complexNum2[2], int complexResult[2]);

// @brief Multiplies two given complex numbers and puts the result in given array
void ComplexMultiplication(const int complexNum1[2], const int complexNum2[2], int complexResult[2]);

// @brief Calculates perimeter of rectangle with given sides
float RectanglePerimeterCalculator(float side1, float side2);

// @brief Calculates area of rectangle with given sides
float RectangleAreaCalculator(float side1, float side2);

// @brief Calculates perimeter of triangle with given sides
float TrianglePerimeterCalculator(float side1, float side2, float side3);

// @brief Calculates area of triangle with given sides
float TriangleAreaCalculator(float side1, float side2, float side3);

// @brief Calculates perimeter of circle with given radius
float CirclePerimeterCalculator(float radius);

// @brief Calculates area of circle with given radius
float CircleAreaCalculator(float radius);

// @brief Converts fahrenheit temperature to kelvin
float FahrenheitToKelvin(float fahrenheitTemp);

// @brief Converts kelvin temperature to fahrenheit
float KelvinToFahrenheit(float kelvinTemp);


int main(){

    int userInput;

    do{
        printf("Enter the calculator type\n");
        printf("1. Standard Calculator\n");
        printf("2. Area&Perimeter Calculator\n");
        printf("3. Temperature Calculator\n");
        printf("-------------------------\n");

        scanf("%d", &userInput);
        
        // Execute corresponding functions to user's input
        if(userInput == 1) StandardCalculator();
        else if(userInput == 2) AreaPerimeterCalculator();
        else if(userInput == 3) TemperatureCalculator();

    }while(userInput); // Go on until user enters 0



    return 0;
}


void StandardCalculator(){
    
    int userInput;

    do{
        printf("Enter the number type\n");
        printf("1. Integer\n");
        printf("2. Complex\n");
        printf("----------------------\n");

        scanf("%d", &userInput);

        // Execute corresponding function to user's input
        if(userInput == 1) IntegerCalculator();
        else if(userInput == 2) ComplexCalculator();

    }while(userInput); // Go on until user enters 0
}

void AreaPerimeterCalculator(){

    int userInput;
    float calcInputs[3] = {0};  // An array to store user's inputs for calculations,
                                // more tidy than having three different variables 
                                // that are not used in every different input of the user's

    do{
        printf("Enter the shape type\n");
        printf("1. Rectangle\n");
        printf("2. Triangle\n");
        printf("3. Circle\n");
        printf("-----------------------\n");

        scanf("%d", &userInput);

        // if user wants to calculate rectangle
        if(userInput == 1){
            printf("Please enter two sides of rectangle\n");
            scanf("%f %f", calcInputs, calcInputs + 1); // get sides
            
            // Run the calculations and print them immediately since we don't need results after
            printf("Perimeter of Rectangle = %f\n", RectanglePerimeterCalculator(calcInputs[0], calcInputs[1]));
            printf("Area of Rectangle = %f\n", RectangleAreaCalculator(calcInputs[0], calcInputs[1]));
        }
        // if user wants to calculate triangle
        else if(userInput == 2){
            printf("Please enter three sides of triangle\n");
            scanf("%f %f %f", calcInputs, calcInputs + 1, calcInputs + 2); // get sides
            
            // Run the calculations and print them immediately since we don't need results after
            printf("Perimeter of Triangle = %f\n", TrianglePerimeterCalculator(calcInputs[0], calcInputs[1], calcInputs[2]));
            printf("Area of Triangle = %f\n", TriangleAreaCalculator(calcInputs[0], calcInputs[1], calcInputs[2]));
        }
        // if user wants to calculate circle
        else if(userInput == 3){
            printf("Please enter radius of circle\n");
            scanf("%f", calcInputs); // get radius
            
            // Run the calculations and print them immediately since we don't need results after
            printf("Perimeter of Circle = %f\n", CirclePerimeterCalculator(calcInputs[0]));
            printf("Area of Circle = %f\n", CircleAreaCalculator(calcInputs[0]));
        }

    }while(userInput);  // Go on until user enters 0
}

void TemperatureCalculator(){

    int userInput;
    float temperature;  // user's temperature input

    do{
        printf("Enter the calculation type\n");
        printf("1. Fahrenheit to Kelvin\n");
        printf("2. Kelvin to Fahrenheit\n");
        printf("--------------------------\n");

        scanf("%d", &userInput);

        // If user chooses fahrenheit to kelvin conversion
        if(userInput == 1){
            printf("Please enter temperature in Fahrenheit\n");
            scanf("%f", &temperature);

            // run the calculation and print immediately
            printf("Result = %f\n", FahrenheitToKelvin(temperature));
        }
        // If user chooses kelvin to fahrenheit conversion
        else if(userInput == 2){
            printf("Please enter temperature in Kelvin\n");
            scanf("%f", &temperature);
            
            // run the calculation and print immediately
            printf("Result = %f\n", KelvinToFahrenheit(temperature));
        }

    }while(userInput);  // go on until user enters 0
}

void IntegerCalculator(){

    int userInput;
    int number1, number2;   // two variables for two integer inputs from the user

    do{
        printf("Enter the calculation type\n");
        printf("1. Addition\n");
        printf("2. Multiplication\n");
        printf("----------------------\n");

        scanf("%d", &userInput);

        if(userInput == 1){
            printf("Please enter the first integer number:\n");
            scanf("%d", &number1);
            printf("Please enter the second integer number:\n");
            scanf("%d", &number2);

            // add the integers and print the result
            printf("Addition of the numbers = %d\n", IntegerAddition(number1, number2));
        }
        else if(userInput == 2){
            printf("Please enter the first integer number:\n");
            scanf("%d", &number1);
            printf("Please enter the second integer number:\n");
            scanf("%d", &number2);

            // multiply the integers and print the result
            printf("Multiplication of the numbers = %d\n", IntegerMultiplication(number1, number2));
        }

    }while(userInput);  // go on until user enters 0
}

void ComplexCalculator(){

    int userInput;

    // complex numbers are stored as real numbers as first element and imaginary part as second element
    // in two element sized arrays 
    int complexNum1[2] = {0};
    int complexNum2[2] = {0};
    int complexResult[2] = {0};

    do{
        printf("Enter the calculation type\n");
        printf("1. Addition\n");
        printf("2. Multiplication\n");
        printf("----------------------\n");

        scanf("%d", &userInput);

        // run addition or multiplication corresponding to user's input
        // again print results immediately since they are not needed afterwards
        if(userInput == 1){
            printf("Please enter the first complex number (real part first):\n");
            scanf("%d %d", complexNum1, complexNum1 + 1);
            printf("Please enter the second complex number (real part first):\n");
            scanf("%d %d", complexNum2, complexNum2 + 1);

            ComplexAddition(complexNum1, complexNum2, complexResult);

            printf("Addition of the numbers = %d + (%di)\n", complexResult[0], complexResult[1]);
        }
        else if(userInput == 2){
            printf("Please enter the first complex number (real part first):\n");
            scanf("%d %d", complexNum1, complexNum1 + 1);
            printf("Please enter the second complex number (real part first):\n");
            scanf("%d %d", complexNum2, complexNum2 + 1);

            ComplexMultiplication(complexNum1, complexNum2, complexResult);
            
            printf("Multiplication of the numbers = %d + (%di)\n", complexResult[0], complexResult[1]);
        }

    }while(userInput);  // go on until user enters 0
}


int IntegerAddition(int number1, int number2){
    return number1 + number2;
}

int IntegerMultiplication(int number1, int number2){
    return number1 * number2;
}

void ComplexAddition(const int complexNum1[2], const int complexNum2[2], int complexResult[2]){
    complexResult[0] = complexNum1[0] + complexNum2[0];
    complexResult[1] = complexNum1[1] + complexNum2[1];
}

void ComplexMultiplication(const int complexNum1[2], const int complexNum2[2], int complexResult[2]){
    complexResult[0] = complexNum1[0] * complexNum2[0] - complexNum1[1] * complexNum2[1];
    complexResult[1] = complexNum1[0] * complexNum2[1] + complexNum1[1] * complexNum2[0];
}


float RectanglePerimeterCalculator(float side1, float side2){
    return 2 * (side1 + side2);
}

float RectangleAreaCalculator(float side1, float side2){
    return side1 * side2;
}

float TrianglePerimeterCalculator(float side1, float side2, float side3){
    return side1 + side2 + side3;
}

float TriangleAreaCalculator(float side1, float side2, float side3){
    float s = (side1 + side2 + side3) / 2;
    return sqrt(s * (s - side1) * (s - side2) * (s - side3));
}

float CirclePerimeterCalculator(float radius){
    return 2 * PI * radius;
}

float CircleAreaCalculator(float radius){
    return PI * radius * radius;
}

float FahrenheitToKelvin(float fahrenheitTemp){
    return (5.0f/9.0f) * (fahrenheitTemp - 32) + 273.15;
}

float KelvinToFahrenheit(float kelvinTemp){
    return (9.0f/5.0f) * (kelvinTemp - 273.15) + 32;
}