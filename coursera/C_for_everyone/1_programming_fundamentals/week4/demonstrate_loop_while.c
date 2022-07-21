/*
    Love you how much
    demonstrate loop with while
    Robert Tartarotti
    July 21, 2022
*/

#include <stdio.h>

void wrt_very(int count)
{
    while (count > 0)
    {
        printf("\n very");
        count--;
    }
    printf(" much.\n\n");
}

int main(void)
{
    int repeat = 0;
    printf("How strong is your love 1-10? :");
    scanf("%d", &repeat);
    printf("\nI love you very");
    wrt_very(repeat);
    return 0;    
}