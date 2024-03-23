#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse(char s[]);
void itoa(int n, char s[], int width);


/* 
 * Write a version of itoa that accepts 3 arguments, instead of two. The third
 * argument is a minimum field width; the converted number must be padded with 
 * blanks on the left if neccesary to make it wide enough.
 */

int main(int argc, char *argv[]) {
    
    int n3 = 60;
    char t3 [33];
    itoa(n3, t3, 8);
    printf("test 3 itoa is %s\n", t3);

    int n4 = 12;
    char t4 [33];
    itoa(n4, t4, 2);
    printf("test 4 itoa is %s\n", t4);
    return 0;
}


void itoa(int n, char s[], int width) {
    int i, sign, wcnt; 

    sign = n;
    i = 0;
    
    do {
        s[i++] = abs(n % 10) + '0';                      
        width--;
    } while (n /= 10);                                          

    while (width > 0){
        s[i++] = '0';
        width--;
    }

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
