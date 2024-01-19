#include <stdio.h>

int setbits(int x, int p, int n, int y);

int main () {

    int res = setbits(8, 1, 0, 3);
    printf("RES  10 ==> Answer: %i\n", res);
    int res1 = setbits(15, 2, 1, 2);
    printf("RES1 15 ==> Answer: %i\n", res1);
    int res2 = setbits(8, 3, 2, 7);
    printf("RES2 14 ==> Answer: %i\n", res2);
    int res3 = setbits(8, 0, 0, 2);
    printf("RES3 8 ==> Answer: %i\n", res3);
    int res4 = setbits(14, 1, 1, 1);
    printf("RES4 14 ==> Answer: %i\n", res4);

    return 0;
}

int setbits(int x, int p, int n, int y){

    // find pos p of y
    int mask = 1;
    mask <<= p;
    
    int cnt = 0;
    while( cnt < n){
        mask = mask | (mask >> 1);
        cnt++;
    }

    // bit mask shift to y
    mask &= y;

    // return x with n bits      
    return x | mask;
    // return x;
}
