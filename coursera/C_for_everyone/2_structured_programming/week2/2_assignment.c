/**
 * @file 2_assignment.c
 * @author Robert Tartarotti
 * @brief Next day
 * @version 1.0.0
 * @date 2023-09-18
 * 
 * Option 1 (General)
 * Write enumerated types that supports dates—such as december 12.
 * Then add a function that produces a next day.  So nextday(date)
 * of december 12 is december 13. Also write a function printdate(date)
 * that prints a date legibly.The function can assume that February has 28
 * days and it most know how many days are in each month. Use a struct with
 * two members; one is the month and the second  is the day of the month—an int (or short).
 * 
 * Solution proposal:
 * Input Month and day (February 28, March 14, October 31, and  December 31)
 * Split month and day
 * Check if the day is the last of the month, if yes, increase month and return day 1.
 * Else, increase the day.
 */

#include<stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum month_days {jan_d = 31, feb_d = 28, mar_d = 31, apr_d = 30, may_d = 31, jun_d = 30,
            jul_d = 31, aug_d = 31, sep_d = 30, oct_d = 31, nov_d = 30, dec_d = 31} month_days;

typedef enum month{ jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec} month;

typedef struct date{
    month m;
    int d;
    } date;

/**
 * @brief Convert input char array to enum month and max quantity of days in the month for 2023
 */
void month_char_to_int(char * str_month, int* month_id, int* max_days)
{
    if (!strcmp(str_month, "January") || !strcmp(str_month, "january")) {
        *month_id = jan;
        *max_days = jan_d;
    } else if (!strcmp(str_month, "February") || !strcmp(str_month, "february")) {
        *month_id = feb;
        *max_days = feb_d;
    } else if (!strcmp(str_month, "March") || !strcmp(str_month, "march")) {
        *month_id = mar;
        *max_days = mar_d;
    } else if (!strcmp(str_month, "April") || !strcmp(str_month, "april")) {
        *month_id = apr;
        *max_days = apr_d;
    } else if (!strcmp(str_month, "May") || !strcmp(str_month, "may")) {
        *month_id = may;
        *max_days = may_d;
    } else if (!strcmp(str_month, "June") || !strcmp(str_month, "june")) {
        *month_id = jun;
        *max_days = jun_d;
    } else if (!strcmp(str_month, "July") || !strcmp(str_month, "july")) {
        *month_id = jul;
        *max_days = jul_d;
    } else if (!strcmp(str_month, "August") || !strcmp(str_month, "august")) {
        *month_id = aug;
        *max_days = aug_d;
    } else if (!strcmp(str_month, "September") || !strcmp(str_month, "september")) {
        *month_id = sep;
        *max_days = sep_d;
    } else if (!strcmp(str_month, "October") || !strcmp(str_month, "october")) {
        *month_id = oct;
        *max_days = oct_d;
    } else if (!strcmp(str_month, "November") || !strcmp(str_month, "november")) {
        *month_id = nov;
        *max_days = nov_d;
    } else if (!strcmp(str_month, "December") || !strcmp(str_month, "december")) {
        *month_id = dec;
        *max_days = dec_d;
    }
}


/**
 * @brief Get the next day
 */
date *nextday(char * input_date) {
    int month_id, max_days;
    date *date_data;
    date_data = (date *)malloc(sizeof(date));
    char * split_month = strtok(input_date, " ");
    month_char_to_int(split_month, &month_id, &max_days);
    int int_day = atoi(strtok(NULL, " "));
    if (int_day == max_days){
        date_data->m = month_id + 1;
        date_data->d = 1;
    } else if (int_day > max_days){
        printf("\n Invalid input argument \n");
        exit(1);
    } else {
        date_data->m = month_id;
        date_data->d = int_day + 1;
    }
    return date_data;
}

/**
 * @brief Print the month
 */
void print_month(enum month m)
{
    switch (m)
    {
    case jan: printf(" January "); break;
    case feb: printf(" February "); break;
    case mar: printf(" March "); break;
    case apr: printf(" April "); break;
    case may: printf(" May "); break;
    case jun: printf(" June "); break;
    case jul: printf(" July "); break;
    case aug: printf(" August "); break;
    case sep: printf(" September "); break;
    case oct: printf(" October "); break;
    case nov: printf(" November "); break;
    case dec: printf(" December "); break;
    default:
        printf("\n Invalid input argument \n");
        exit(1);
    }
}

/**
 * @brief Print the next day
 */
void print_next_day(date *date_data)
{
    printf("\nNext day: ");
    print_month(date_data -> m);
    printf(" %d\n", date_data -> d);
}

int main()
{
    printf("Please, insert the month and day (Ex: February 28): \n");
    char input_date[30];
    fgets(input_date, 30, stdin);
    printf("Current day: %s", input_date);
    date *date_data = nextday(input_date);
    print_next_day(date_data);
    return 0;
}




