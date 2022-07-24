/**
 * @file recursvive_v_iterative_factiorial.c
 * @author Robert Tartarotti
 * @brief Recursive v. Iterative Factorial
 * @date 2022-07-22
 */

#include <stdio.h>

/* long aloows it to work for up to 20 */

long int factorial(int n)
{
    long f = 1;
    int i;

    for (i = 1; i <= n; i++)
        f = f * i;
    return f;
} 

long int recursive_factorial(int n)
{
    if (n == 1)
        return 1;
    else
        return(recursive_factorial(n-1) * n);
}

int main(void)
{
    int how_many = 0, i;
    printf("I want table of fatorial up to n:");

    scanf("%d", &how_many);
    printf("\n factorials\n");
    
    for (i = 1; i <= how_many; i++)
        printf("\n%d\t %ld\n", i, factorial(i));
    printf("\n\n");
    for (i = 1; i <= how_many; i++)
        printf("\n%d\t %ld\n", i, recursive_factorial(i));
    printf("\n\n");
    return 0;
}