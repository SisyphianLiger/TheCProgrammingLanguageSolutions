#include <stdio.h>
#define BUFFER 1000


void escape(char s[], char t[]);

int main() {

    char s[BUFFER];
    char t[BUFFER];

    escape(s, t);

    int i = 0;
    printf("\n");
    while (t[i] != '\0') {
        printf("%c", t[i]);
        i++;
    }

    return 0;
}


void escape(char s[], char t[]){

    int c, i, j;
    i = 0;
    while ((c = getchar()) != EOF) {
        s[i] = c;
        i++;
    }
    s[++i] = '\0';

    i = 0, j = 0;

    while(s[i] != '\0'){
        switch (s[i]) {
            case '\t':
                t[j++] = '\\';
                t[j++] = 't';
                break;
            case '\n':
                t[j++] = '\\';
                t[j++] = 'n';
                break;
            default:
                t[j++] = s[i];
                break;
        }
        i++;
    }
    t[j++] = '\0';
} 
