/**
 * @file 4_assert_math.c
 * @author Robert Tartarotti
 * @brief Use asserts with math
 * @version 0.1
 * @date 2022-08-09
 */

#include <assert.h>
#include <stdio.h>

int main()
{
    double x, y;
    while ( 1)
    {
        printf("Read in 2 floats: \n");
        scanf("%lf %lf", &x, &y);
        assert(y != 0);
        printf("when divided x/y = %lf\n", x/y);
    }
    return 0;
}