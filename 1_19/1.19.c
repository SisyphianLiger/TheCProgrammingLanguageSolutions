#include <stdio.h>

#define MAXLINE 1000
#define END     0

/*
 * print all input lines that are longer than 80
 */
int get_line(char s[], int limit);
void revcopy (char to[], char from[], int length);

int main () {

    int len;
    char output[MAXLINE];
    char input[MAXLINE];
    
    while ((len = get_line(input, MAXLINE)) > END) {
        

        revcopy(output, input, len); 
        printf("%s\n",output);
    }


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

void revcopy (char to[], char from[], int length){

    int i, j;

    i = length - 1;
    j = 0;
    while (i >= 0) {
        to[j] = from[i];
        --i;
        ++j;
    }    
}
