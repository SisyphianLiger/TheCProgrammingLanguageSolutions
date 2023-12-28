#include <stdio.h>


int main () {
    
    int c;
    int spaces = 0;
    while ((c = getchar()) != EOF) {
        
        if (c == 32 && spaces == 0){
            ++spaces;
            putchar(c);
            continue;
        } 
    
        if (c == 32 && spaces > 0)
            continue;

        spaces = 0;
        putchar(c);
    }
    printf("%i\n", c);

    return 0;
}
