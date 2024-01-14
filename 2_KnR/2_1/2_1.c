#include <stdio.h>
#include <limits.h>

/* char, short, int, long, signed, unsigned */

int main () {
    // Chars
    printf("CHAR_MAX is: %i\n", CHAR_MAX);
    printf("CHAR_MIN is: %i\n", CHAR_MIN);

    // Short
    printf("SHORT_MAX is: %d\n", SHRT_MAX);
    printf("SHORT_MIN is: %d\n", SHRT_MIN);
    
    // Int - Signed
    printf("INT_MAX is: %i\n", INT_MAX);
    printf("INT_MIN s: %i\n", INT_MIN);

    // Long
    printf("LONG_MAX s: %ld\n", LONG_MAX);
    printf("LONG_MIN is: %ld\n", LONG_MIN);

    // Unsigned
    printf("USIGNED MAX is: %u\n", UINT_MAX);
    printf("USIGNED MIN is: %u\n", 0);

    return 0;

}
