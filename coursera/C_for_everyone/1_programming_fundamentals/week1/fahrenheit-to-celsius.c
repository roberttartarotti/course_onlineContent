/* Conversion of Fahrenheit to Celsius

    C = (F-32)/1.8

    Robert Tartarotti

    July, 14, 2022

*/

# include <stdio.h>

int main(void)
{
    int fahrenheit, celsius;

    printf("Please enter the fahrenheit as an integer: ");
    scanf("%d", &fahrenheit);
    celsius = (fahrenheit - 32)/1.8; //note conversion
    printf("\n %d fangreinheit is %d celsius.\n", fahrenheit, celsius);
    return 0;
}