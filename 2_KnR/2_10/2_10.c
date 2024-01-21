#include <stdio.h>


int lower(int c);
int main () {

    printf("C should be %c\n", lower('C'));
    printf("9 should be %i\n", lower(9));

    return 0;
}

int lower(int c) {
    return c >= 'A' && c <= 'Z' ? c += 'a' - 'A' : c;
}
