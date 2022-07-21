/* The distance of a marathon in yards
    by Robert Tartarotti
    July, 14 ,2022
*/

#include <stdio.h>

int main(void)
{
    int miles = 26, yards = 385;
    double kilometers;

    printf("Please enter the miles as an integer: ");
    scanf("%d", &miles);
    printf("Please enter the yards as an integer: ");
    scanf("%d", &yards);

    kilometers = 1.609 * (miles + yards / 1760.0);
    printf("\nA marathon is %lf kilometers. \n\n", kilometers);
    return 0;
}