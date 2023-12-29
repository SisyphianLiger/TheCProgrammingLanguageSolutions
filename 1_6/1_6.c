#include <stdio.h>


int main() {
    
    int c;
    c = getchar() != EOF;

    printf("Verifying c is 0 or 1: %i\n", c);
    
    int c1;
    c1 = getchar();
    printf("Verifying c1 is not 0 or 1: %i\n", c1);

    return 0;

}
