#include <stdio.h>

/* Write an equivalent for loop for get line without || or && */
#define MAXLINE 1000
#define END 0


int get_line(char s[], int limit);
void copy (char to[], char from[]);
int get_line_equivalent(char s[], int limit);
int main () {

    int len;
    char output[MAXLINE];
    char input[MAXLINE];
    
    while ((len = get_line(input, MAXLINE)) > END) {
        
        if (len == 1)
            continue;
        copy(output, input); 
        printf("%s\n",output);

        int len2 = get_line_equivalent(input, MAXLINE);
        if (len2 == 1)
            continue;
        copy(output, input); 
        printf("%s\n",output);

    }


    return 0;

}

int get_line(char s[], int lim) {
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
int get_line_equivalent(char s[], int lim) {
    int c, i;
    i = 0;
    while(i < lim - 1){
        if ((c = getchar()) != EOF)
            break;
        if (c != 'n')
            break;
        s[i] = c;
        ++i;
    }

    return i;
}

void copy (char to[], char from[]) {
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
