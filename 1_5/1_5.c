#include <stdio.h>

int main() {
    
    float fahr, celesius;
    int start, step, min;

    start = 300;
    min = 0;
    step = 20;

    fahr = start;

    printf("   Farenheit         Celcius \n");
    printf("---------------------------------\n");

    while ( fahr >= min) {
        celesius = (5.0/9.0) * (fahr - 32.0);
        printf("|     %3.0f      |     %6.1f     |\n", fahr, celesius);
        printf("---------------------------------\n");
        fahr -= step;
    }
}
