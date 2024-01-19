#include <limits.h>
#include <stdio.h>


int rightrot(int x, int n);

int main () {
    printf("Rotate 32 to 8 == Answer: %i\n", rightrot(32, 2));
    printf("Rotate 32 to 0 == Answer: %i\n", rightrot(32, 6));
    printf("Rotate 256 to 32 == Answer: %i\n", rightrot(256, 3));
    printf("Rotate INT_MAX to 0 == Answer: %i\n", rightrot(INT_MAX, 31));

    return 0;
}

int rightrot(int x, int n) {
    return x >> n;

}
