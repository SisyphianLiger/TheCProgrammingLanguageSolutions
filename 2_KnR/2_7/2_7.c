#include <stdio.h>


int invert(int x, int p, int n);
int main() {

    int res = invert(8, 2, 0);
    printf("result of 8, 2 0 is 12\n Answer: %i \n", res);
    int res1 = invert(8, 3, 1);
    printf("result of 8, 3, 1 is 4\n Answer: %i \n", res1);
    int res2 = invert(8, 2, 2);
    printf("result of 8, 2, 2 is 7\n Answer: %i \n", res2);
    int res3 = invert(8, 3, 0);
    printf("result of 8, 3, 0 is 0\n Answer: %i \n", res3);
    return 0;
}

int invert(int x, int p, int n) {


    // find pos p of y
    int mask = 1;
    mask <<= p; 
    int cnt = 0;
    while( cnt < n){
        mask = mask | (mask >> 1);
        cnt++;
    }
    // return x with n bits      
    return x ^ mask;
}
