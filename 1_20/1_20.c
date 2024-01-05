#include <stdio.h>

#define MAXLINE 100     /* size of buffer for strings */
#define END 0           /* If there is a newline with no input */
#define TABN 4          /* How big \t should be */


int get_line(char s[], int limit);
void copy(char to[], char from[]);

int main () {


    int len;
    char output[MAXLINE];
    char input[MAXLINE];
    
    while ((len = get_line(input, MAXLINE)) > END) {
        

        copy(output, input); 
        printf("%s\n",output);
    }

    return 0;

}


int get_line(char input[], int lim) {
    
    int i, c, tcnt;
    
    tcnt = 0;
    for (i = 0; i < lim - 2 && (c = getchar()) != EOF && c != '\n'; i++) {
        
        if (tcnt % TABN == 0)
            tcnt = 0;

        if (c == '\t'){
            while (tcnt < TABN) {
                input[i] = ' ';
                ++i;
                ++tcnt;
            }
            c = getchar();
        } 
        input[i] = c;
        
        ++tcnt;
    }

    if (c == '\n') {
        input[i] = c;
        ++i;
    }

    input[i] = '\0';
    return i;
    
}

void copy (char to[], char from[]){
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
