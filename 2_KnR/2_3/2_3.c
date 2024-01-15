#include <stdio.h>

#define LOWERTODEC 87
#define UPPERTODEC 55
/* 
   
   Test String 1: "Hello"
   Hexadecimal Output: 48 65 6c 6c 6f

   Test String 2: "Boots"
   Hexadecimal Output: 42 6f 6f 74 73

   Test String 3: "Wizard"
   Hexadecimal Output: 57 69 7a 61 72 64

   Test String 4: "Bear"
   Hexadecimal Output: 42 65 61 72

   Test String 5: "Salmon"
   Hexadecimal Output: 53 61 6c 6d 6f 6e


   Accetable digits are 0 - 9 a - f and A - F

*/
int htoi(char s[]);

int main () {
   
    /*
        0x5 : 5
        0xA : 10
        0xf : 15
        0x10 : 16
        0xF0 : 240
     * */
    char s1[] = "0x5";
    char s2[] = "0xA";
    char s3[] = "0xFF";
    char s4[] = "0Xf";
    char s5[] = "0x10";
    char s6[] = "0xf0";
    char s7[] = "Ab";
    char s8[] = "9A";
    printf("Value 0x5 should be 5 and is %i\n", htoi(s1));
    printf("Value 0xA should be 10 and is %i\n", htoi(s2));
    printf("Value 0xFF should be 255 and is %i\n", htoi(s3));
    printf("Value 0xf should be 15 and is %i\n", htoi(s4));
    printf("Value 0x10 should be 16 and is %i\n", htoi(s5));
    printf("Value 0xf0 should be 240 and is %i\n", htoi(s6));
    printf("Value Ab should be 171 and is %i\n", htoi(s7));
    printf("Value 9A should be 154 and is %i\n", htoi(s8));
     
    return 0;
}

int htoi(char s[]){
  
    // Finding len to filter 0x issues
    int len = 0;
    while (s[len] != '\0') 
        len++; 
    

    int i, n, pow, pos;
    n = 0, pow = 1;

    for (i = len - 1; i >= 0; --i) {

        // Terminate when we hit an x
        if ( s[i] == 'x' || s[i] == 'X')
            break;


        // Check for numbers 
        if ( s[i] >= '0' && s[i] <= '9') {
            n = n + (s[i] - '0') * pow;
            pow *= 16;  
        }

        if (s[i] >= 'A' && s[i] <= 'F'){
            n = n +  (s[i] - UPPERTODEC) * pow;
            pow *= 16;  
        }

        if (s[i] >= 'a' && s[i] <= 'f'){ 
            n = n + (s[i] - LOWERTODEC) * pow;
            pow *= 16;  
        }

     
    }
    return n;
}

