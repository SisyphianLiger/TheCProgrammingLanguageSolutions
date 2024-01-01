#include <stdio.h>

#define INWORD 0
#define OUTWORD 1
#define MAXSPOT 9

int main () {
   
    int c, state, len; 
    int wlen[MAXSPOT]; 

    // Initialize Array
    for (int i = 0; i < MAXSPOT; i++) 
        wlen[i] = 0; 
    
    // Capture Data from char input
    while ((c = getchar()) != EOF) {
        
        
        if(c == ' ' || c == '\n' || c == '\t') {
            state = OUTWORD;
            
            if (len >= MAXSPOT) {
                wlen[MAXSPOT - 1]++;
                len = 0;
            } else {
                wlen[len]++;
                len = 0;
            }
        }

        state = INWORD;
        ++len;  
    }

    printf("\n");

    // Print out array for reference to captured Data
    for (int i = 0; i < MAXSPOT; i++) 
        printf("%i ", wlen[i]);

    printf("\n");
    printf("\n");
    printf("\n");

    // print vertical graph
    for (int y = MAXSPOT; 0 <=  y ; y--) {
        for(int x = 0; x <= MAXSPOT - 1; x++) {
            if (wlen[x] >= (y + 1) && y < MAXSPOT + 1) 
                printf("* ");
            else 
                printf("  ");
        }
        printf("\n");
    }            
   
    // Show x axis line
    for (int i = 0; i < MAXSPOT; i++) 
        printf("==");
    
    printf("\n");

    for (int i = 0; i < MAXSPOT; i++) 
        printf("%i ", i + 1);


    return 0;

}
