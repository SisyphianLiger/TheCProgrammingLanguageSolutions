#include <stdio.h>


int main () {

    float fahr, celesius;
    int start, step, max;

    start = 0;
    max = 300;
    step = 20;

    celesius = start;

    printf("   Celcius         Farenheit \n");
    printf("---------------------------------\n");

    while ( celesius <= max) {
        fahr = celesius / (5.0/9.0) + 32;
        printf("|     %3.0f      |     %6.1f     |\n",  celesius, fahr);
        printf("---------------------------------\n");
        celesius += step;
    }

}
