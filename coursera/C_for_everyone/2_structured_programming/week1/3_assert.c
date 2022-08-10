/**
 * @file 3_assert.c
 * @author Robert Tartarotti
 * @brief Use asserts
 * @version 0.1
 * @date 2022-08-09
 */


#define NDEBUG // goes before <assert.h>
#include <assert.h>
#include <stdio.h>
#include <ctype.h>

int main()
{
    assert(1);
    printf("For 1: \nMy program runs \n");
    assert(0);
    printf("For 0: \nMy program does not runs \n");
    return 0;
}
