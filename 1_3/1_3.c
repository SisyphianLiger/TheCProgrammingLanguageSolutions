#include <stdio.h>

int main() {
    
    float fahr, celesius;
    int start, step, max;

    start = 0;
    max = 300;
    step = 20;

    fahr = start;

    printf("   Farenheit         Celcius \n");
    printf("---------------------------------\n");

    while ( fahr <= max) {
        celesius = (5.0/9.0) * (fahr - 32.0);
        printf("|     %3.0f      |     %6.1f     |\n", fahr, celesius);
        printf("---------------------------------\n");
        fahr += step;
    }
}
