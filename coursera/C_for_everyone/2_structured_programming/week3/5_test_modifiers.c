/**
 * @file 5_test_modifiers.c
 * @author Robert Tartarotti
 * @brief Testmodifiers
 * @version 0.1
 * @date 2023-10-12
 */

#include<stdio.h>


int main() {
    double x = 0.123456789;
    printf("general printing Ideas\n\n");
    printf(" x is %-12.5e and %e and %10.5f and %10d\n\n", x, x, x, x);
    printf(" (int)x is %10d\n\n", (int)x);

    return 0;
}