#include <stdio.h>


void farenheit_to_celsius(int start, int step, int limit);

int main() {
    
    farenheit_to_celsius(0, 20, 300);

    return 0;
}

void farenheit_to_celsius(int start, int step, int limit) {

    float fahr, celesius;
    fahr = start;

    printf("   Farenheit         Celcius \n");
    printf("---------------------------------\n");

    while ( fahr <= limit) {
        celesius = (5.0/9.0) * (fahr - 32.0);
        printf("|     %3.0f      |     %6.1f     |\n", fahr, celesius);
        printf("---------------------------------\n");
        fahr += step;
    }
}
