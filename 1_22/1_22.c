#include <stdio.h>

#define MAXLINE 1000     /* size of buffer for strings */
#define END 0           /* If there is a newline with no input */
#define LINEBREAK 10    /* Where we check for the line break */
#define FWDLIM 25 * LINEBREAK / 100


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

    // Use a percentage based i.e. 25% backwards 25% forwards for newline insert
    int scan_bck = 25 * LINEBREAK / 100;  // 5 --> 0
    int scan_fwd = 0;  // 0 --> 5
    int fnd_spt = 0;


    int i, c;
    int j = 0;

    // 20 += incr could be a problem for exit condition...we will see
    for (i = 0; i < lim - 2 && (c = getchar()) != EOF && c != '\n'; i++) {

        if (i % LINEBREAK == 0 && i != 0 && fnd_spt != 0) {
                input[fnd_spt] = '\n';
                fnd_spt = 0;
        }

        // outside of the loop we just add the chars
        if (c == ' ' || c == '\t')
            fnd_spt = i;

        input[i] = c; 
    }

    if (c == '\n') {
        input[i] = c;
        ++i;
    }

    input[i] = '\0';
    return i + j; 
}

void copy (char to[], char from[]) {
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
