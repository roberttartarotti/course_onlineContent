/*
    Function that prints a table of values for sine and cosine between (0, 1)
    Robert Tartarotti
    July 21, 2022
*/

#include<stdio.h>
#include<math.h> /* When using math.h lib, compile with -lm option */

/**
 * @brief Generate table of values for sine and cosine from 0 to 1 with step of 0.1. 
 * 
 * @return int 0 - Success
 */
int gen_table_values_sine_cosine(void)
{
    double interval, sin_value, cos_value; // double variables declaration
    // Inform about the table
    printf("Table of sine and cosine values for rad angles between 0 and 1");
    printf("\nAngle in rad\tSine\t\tCosine\n"); // Print the labels
    for(int i = 0; i <=10; i++)
    {
        interval = i/10.0; // Get the angle in rad
        sin_value = sin(interval); // Get the sin value for the angle
        cos_value = cos(interval); // Get the cosine value for the angle
        // print the angle in rad, sin value and cosine value
        printf("%lf\t%lf\t%lf\n", interval, sin_value, cos_value); 
    }
    return 0;
}

/**
 * @brief Main function
 * 
 * As it was required to create a function to generate the table,
 * the main will only call the function.
 * 
 * @return int 
 */
int main(void)
{
    return gen_table_values_sine_cosine();
}

/*
    Result:
    --------------------------------------------------------------
    Table of sine and cosine values for rad angles between 0 and 1
    Angle in rad    Sine            Cosine
    0.000000        0.000000        1.000000
    0.100000        0.099833        0.995004
    0.200000        0.198669        0.980067
    0.300000        0.295520        0.955336
    0.400000        0.389418        0.921061
    0.500000        0.479426        0.877583
    0.600000        0.564642        0.825336
    0.700000        0.644218        0.764842
    0.800000        0.717356        0.696707
    0.900000        0.783327        0.621610
    1.000000        0.841471        0.540302
    --------------------------------------------------------------
*/
