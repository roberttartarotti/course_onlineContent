/*
    Logical operators and short circuit evaluation
    Robert Tartarotti
    July 21, 2022
*/

#include <stdio.h>
int main()
{
    int outside, weather;
    printf("\nEnther if outside 1 true 0 false:");
    scanf("%d", &outside);
    printf("\nEnter if rain 1 true 0 false:");
    scanf("%d", &weather);
    if (outside && weather)
        printf("\nPlease use an umbrella.\n");
    else
        printf("\nDress normally.\n\n");
    return 0;
}