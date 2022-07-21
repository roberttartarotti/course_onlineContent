/* Producing the volume of a sphere as a double
    Robert Tartarotti
    July 15, 2022
*/

#include<stdio.h>
#define PI 3.14159
int main(void)
{ 
    int radius;
    printf("Enter radius:");
    scanf("%d", &radius);
    printf("volume is : %lf \n\n", 4 *radius*radius*radius/3.0 );
    return 0;
}