/* Give the sine of a value between 0 and 1 (non inclusive)
    Robert Tartarotti
    July 15, 2022
*/

#include <stdio.h>
#include <math.h>  /* When using math.h lib, compile with -lm option */

int main(void)
{
    double value, result; // Declaration of double variables

    /* 
    value: double that will receive the value from the user
    result: double that will receive the result of the sin using math.h
    */

    /* Get the input valie between 0 and 1 (non inclusive) */
    printf("\nEnter a value between 0 and 1 (non inclusive) in radians: ");
    scanf("%lf", &value); // Get the value from the user

    /* Avoid value that are not between 0 and 1 (non inclusive) */
    if (value < 0 || value >= 1) // If the value is not valid, exit
    {
        printf("\nThe value must be between 0 and 1 (non inclusive)\nexiting\n");
        return 1; // return 1 (error) and stop the software
    }

    /* If value is valid, continue and print it to the user */
    printf("\nThe value in rad is %lf\n", value);

    /* Get the result using math.h */
    result = sin(value); // Get the sin of the inserted value in rad
    printf("\nThe sine of %lf rad is %lf\n", value, result); // Show the result for the user
    return 0; // Return 0, i.e. code was successfully executed.
}