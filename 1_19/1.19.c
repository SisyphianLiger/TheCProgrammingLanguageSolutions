#include <stdio.h>

#define MAXLINE 4
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
        

        revcopy(output, input, MAXLINE); 
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
    j = length;
    for (i = 0; i < length; i++) {
        to[j] = from[i]; 
        --j;
        printf("to[j]: %c at j is: %i \n", to[j], j);
    }
   
    to[j] = '\0';
}
