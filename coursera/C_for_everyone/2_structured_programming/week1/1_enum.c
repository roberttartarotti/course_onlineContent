/**
 * @file 1_enum.c
 * @author Robert Tartarotti
 * @brief Enumerated Types
 * @version 0.1
 * @date 2022-08-09
 */

#include<stdio.h>

enum day {sun, mon, tue, wed, thu, fri, sat}; //declare type
typedef enum day day;

void print_day(enum day d)
{
    switch (d)
    {
    case sun: printf(" sunday "); break;
    case mon: printf(" monday "); break;
    case tue: printf(" tuesday "); break;
    case wed: printf(" wednesday "); break;
    case thu: printf(" thursday "); break;
    case fri: printf(" friday "); break;
    case sat: printf(" saturday "); break;
    default: printf("%d is an error", d);
    }
}

enum day next_day(enum day d){
    return( d + 1 % 7 );
}

int main()
{
    enum day today = fri;
    print_day(today);
    printf("\n\n");
    print_day(7);
    printf("\n\n");
    print_day(next_day(today));
    printf("\n\n");
    return 0;
}
