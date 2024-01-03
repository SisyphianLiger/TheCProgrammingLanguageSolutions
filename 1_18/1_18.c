#include <stdio.h>

#define MAXLINE 1000
#define END     0

/*
 * print all input lines that are longer than 80
 */
int get_line(char s[], int limit);
void copy (char to[], char from[]);

int main () {

    int len;
    char output[MAXLINE];
    char input[MAXLINE];
    
    while ((len = get_line(input, MAXLINE)) > END) {
        
        // Delete entirely blank lines
        if (len == 1)
            continue;

        copy(output, input); 
        printf("%s\n",output);
    }


    return 0;

}

int get_line(char s[], int lim) {
    int c, i, j;

    j = 0;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
        if (i < lim-3 && c != '\t'){
            s[j] = c;
            ++j;
        }
    if (c == ' ') {
        ++j;
    }

    if (c == '\n'){
        s[j] = c;
        ++j;
        ++i;
    }
    s[j] = '\0';
    return i;
}

void copy (char to[], char from[]){
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
