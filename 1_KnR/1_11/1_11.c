#include <stdio.h>

#define INWORD 0
#define OUTWORD 1


int main () {

    int c, nl, nw, nc, state; 
    state = OUTWORD;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n') 
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t') 
            state = OUTWORD;
        else if (state == OUTWORD) {
            state = INWORD;
            ++nw;
        }
    }
    printf("%d %d %d\n", nl, nw, nc);

    return 0;

}
