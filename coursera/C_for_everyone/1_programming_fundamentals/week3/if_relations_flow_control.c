/*
    If and relations and flow of control
    Robert Tartarotti
    July 21, 2022
*/

#include <stdio.h>
int main()
{
    int speed;
    printf("\nEnther your speed as an integer:");
    scanf("%d", &speed);
    if (speed < 65)
        printf("\nNo speeding Ticket.\n");
    else
        printf("\nSpeeding Ticket.\n\n");
    return 0;
}