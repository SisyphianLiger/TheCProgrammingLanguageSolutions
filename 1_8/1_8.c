#include <stdio.h>

int main () {

    int c, nline, tab, space; 
    c = getchar(); 
    nline = 0, tab = 0, space = 0;
    
    while((c = getchar()) != EOF) {

        if (c == '\n') 
            ++nline;
        if (c == '\t')
            ++tab;
        if (c == 32)
            ++space;
    }

    printf("The total number of blanks: %i\n", space);
    printf("The total number of new lines:  %i\n", nline);
    printf("The total number of tabs: %i\n", tab);


    return 0;
}
