/* 
    Float abs value of sine
*/

#include<stdio.h>
#include<math.h> /* has  sin(), abs(), and fabs(), When using math.h lib, compile with -lm option */
int main(void)
{ 
double interval, sin_value;
int i;
for(i = 0; i <30; i++)
{
 interval = i/10.0;
 sin_value = sin(interval);
 printf("sin( %lf ) = %lf \t", interval, fabs(sin_value)); // use float abs
}
printf("\n+++++++\n");
return 0;
}