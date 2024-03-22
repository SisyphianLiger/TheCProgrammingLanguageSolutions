#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * In a two's complement number represenation, our versions of itoa does not 
 * handle the largest negative number, that is, th e vaule of n equal to 
 * -(2^wordsize - 1). Explain why not. Modify it ot print that value correctly, 
 *  regardless of the machine which it runs.
 * */

void itoa(int n, char s[]);
void reverse(char s[]);
int main(int argc, char *argv[]) {

    int n3 = INT_MIN;
    char t3 [20];
    itoa(n3, t3);
    printf("test 3 itoa is %s\n", t3);


    return 0;
}

void itoa(int n, char s[]) {
    int i, sign; 

    sign = n;
    i = 0;
    do {
        s[i++] = abs(n % 10) + '0';                      /* Get Next Digit */
    } while (n /= 10);                                  /* delete it */
        
    if (sign < 0) 
        s[i++] = '-'; 
    
    s[i] = '\0';
    reverse(s);

}

void reverse(char s[]) {
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

