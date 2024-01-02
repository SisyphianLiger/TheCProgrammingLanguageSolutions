#include <stdio.h>

#define MAXLINE 1000
#define MINMUM  20

/*
 * print all input lines that are longer than 80
 */
int get_line(char s[], int limit);
void copy (char to[], char from[]);

int main () {

    int max; 
    int len;
    char output[MAXLINE];
    char input[MAXLINE];

    max = 0;    
    while ((len = get_line(input, MAXLINE)) > 0) {
        
        if( len > max && len > MINMUM) {
            max = len;
            copy(output, input);
            printf("Current Max %d, output: %s\n", max, input);
        } 
    }

    if (max > 0) 
        printf("Final: Max %d, output %s\n", max, output);

    return 0;

}

int get_line(char s[], int lim)
{
    int c, i;

    for (i = 0; (c = getchar()) != EOF && c != '\n' && i < lim - 1; ++i)
            s[i] = c;
        
    if (c == '\n'){
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}

void copy (char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
