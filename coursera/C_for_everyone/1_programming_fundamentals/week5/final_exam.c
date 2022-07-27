#include <stdio.h>

int foobar(int* n){
     *n = *n +1;
     return *n;
}

int mystery(int p, int q){
     
    int r;
    if ((r = p % q) == 0)
        return q; 
    else return mystery(q, r);
}

int main(void)
{
    // int a = 3, b = 4, c = 0, d = '1';
    // int k = a - b * c;
    // printf("%d\n", k);

    // int a = 1, b = 2, c = 3;
    // int k =  b = a = c;
    // printf("%d\n", k);

    // int i = 0, j = 1, k = 2;
    // int z =  (i && (j = k)) || (k > j);
    // printf("%d\n", z);

    // int k = 6;
    // printf("foobar(k) = %d,",foobar(&k) );
    // printf(" k = %d\n", k);

    // printf("%d\n", mystery(2, 6));

    // printf("%d\n", mystery(7, 91));

    // int data[5] = {0 ,1, 2, 3, 4}, sum = 0 , i;

    // for (i = 0; i < 5 ; i++)
    //     sum = sum + data[i];
    // printf("%d\n", sum);

    int a[10] = {1,2,3,4,5,6,7,8,9,10}, i = 6 ;
    int *p = &a[0];
    printf("%d\n", *(p + i));

    return 0;
}