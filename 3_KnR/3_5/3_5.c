#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*
 * Write the function itob(n,s,b) that conversts integer n, into a base b 
 * character representation in the string s. In particular, iotb(n,s,16) 
 * formats n as a hexadecimal integer in a.
 * 
 */


void itoa(int n, char s[]);

void itob(int n, char s[], int b);

void binary_converter(int n, char s[]);
void octal_converter(int n, char s[]);
void hexadecimal_converter(int n, char s[]);


void reverse(char s[]);


int main(int argc, char *argv[]) {

    // Binary Tests
    // char s1[33];
    // itob(INT_MIN, s1, 2); 
    // printf("Result %s\n", s1);
    //
    // char s2[33];
    // itob(INT_MAX, s2, 2); 
    // printf("Result %s\n", s2);

    // Octal Tests
    // char s3[33];
    // itob(INT_MIN, s3, 8); 
    // printf("Result %s\n", s3);
    //
    // char s4[33];
    // itob(INT_MAX, s4, 8); 
    // printf("Result %s\n", s4);

    // Hexidecimal Tests
    char s5[33];
    itob(INT_MIN, s5, 16); 
    printf("Result %s\n", s5);

    char s6[33];
    itob(INT_MAX, s6, 16); 
    printf("Result %s\n", s6);
    return 0;
}


void itob(int n, char s[], int b) {

    switch (b) {
        case 2:
            binary_converter(n, s); 
            break;
        case 8:
            octal_converter(n, s);
            break;
        case 16:
            hexadecimal_converter(n, s);
            break;
        default:
            printf("Incorrect Base Case please enter 2, 8, or 16");
            break;
    }
}



void binary_converter(int n, char s[]) {

    int i, sign; 

    sign = n;
    i = 0;
    do {
        // printf("n value is %i\n", abs(n % 2));
        s[i++] = abs(n % 2) + '0';                      /* Get Next Digit */
    } while (n /= 2);                                   /* delete it */
        
    if (sign > 0) 
        s[i++] = '0'; 
    
    s[i] = '\0';
    reverse(s);
}


void octal_converter(int n, char s[]) {

    int i; 

    i = 0;
    do {
        s[i++] = abs(n % 8) + '0';                      /* Get Next Digit */
    } while (n /= 8);                                   /* delete it */
        
    
    s[i] = '\0';
    reverse(s);
}


void hexadecimal_converter(int n, char s[]){

    int i; 

    i = 0;
    do {
        if (abs( n % 16) > 10)
                s[i++] = abs(n % 16) + '7';                      
        else 
                s[i++] = abs(n % 16) + '0';                      
        
    } while (n /= 16);                                   /* delete it */
        
    
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


