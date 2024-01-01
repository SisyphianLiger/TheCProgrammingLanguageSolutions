#include <stdio.h>


#define PRINTABLECHAR 95
#define ASCIISTART 32

int main () {

    // Histogram of different characters and there input
    int c; 

    // We create an array of 94
    int printablechars[PRINTABLECHAR];

    // remember to initialize it lol
    for (int i = 0; i < PRINTABLECHAR; i++) {
        printablechars[i] = 0; 
    }
    // each char is a int representation 
    // so lets read the char and place i


    while ((c = getchar()) != EOF) {
        
        if(c < 32 || c > 126) 
            continue;


        printablechars[c - ASCIISTART]++;
    }

    for (int y = 0; y < PRINTABLECHAR; y++) 
        printf("%i ", printablechars[y]);
    

    for (int y = 0; y < PRINTABLECHAR + 1; y++) {
        for (int x = 0; x < PRINTABLECHAR + 2; x++) {
            if (x == 0) {
                printf("%c", ASCIISTART + y);
                continue;
            }
            if (x == 1) {
                printf(" : ");
                continue;
            }
            if (printablechars[y] >= x - 1)
                printf("*");
            else 
                printf(" ");
        } 
        printf("\n");
    }

}
