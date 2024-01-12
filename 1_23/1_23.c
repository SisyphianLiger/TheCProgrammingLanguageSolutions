#include <stdio.h>
#include <strings.h>

#define MAXLINE 100     /* size of buffer for strings */
#define END 0           /* If there is a newline with no input */
#define TABN 4          /* How big \t should be */
#define FSLASH 47       /* To match / in the loop */
#define AST 42          /* To match * in the loop */
#define SNGQUOTE 39     /* To match ' in the loop */
#define DBLQUOTE 34     /* To match " in the loop */


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
    
    int i, c;

    int slash_one = 0, slash_two = 0;
    int slash_ast_one = 0, slash_ast_two = 0;
    int dblqote = 0, dblqote_start = 0, dblqote_fin = 0;
    int chr_start = 0, chr_fin = 0;


    for (i = 0; i < lim - 2 && (c = getchar()) != EOF && c != '\n'; i++) {
        
        // Store input
        input[i] = c; 
       
        /*          Sort Through //              */
        if(i > 0 && input[i-1] == FSLASH && c == FSLASH) {
                slash_one = i-1;
                slash_two = i;
        }

        /*          Sort Through slash ast              */
        if (i > 1 && input[i-1] == FSLASH && c == AST) 
                slash_ast_one = i-1;
        
        if (i > 1 && input[i-1] == AST && c == FSLASH) 
                slash_ast_two = i;


        /*      Sort Through 'J'        */
        if (i > 2 && c == SNGQUOTE&& input[i-2] == SNGQUOTE){
            chr_start = i - 2;
            chr_fin = i;
        }
 
        
        /* Sort Through "string constants"      */
        if (c == DBLQUOTE && dblqote == 0){ 
            dblqote_start = i;
            ++dblqote;

        } else if ( c == DBLQUOTE && dblqote == 1 ) {
            dblqote_fin = i;
            dblqote = 0;    
        }

    }



    if (c == '\n') {
        input[i] = c;
        ++i;
    }

    input[i] = '\0';


    // If slash_two is full then we know slash_one is also full
    if (slash_two) {
        int j;
        for (j = slash_one; j < lim - 2; j++) 
            input[j] = ' ';
    }
    

    if (slash_ast_two){
        int k;
        for (k = slash_ast_one; k < slash_ast_two + 1; k++) 
            input[k] = ' ';
    }

    if (chr_start && chr_fin) {
        input[chr_start] = ' ';
        input[chr_start + 1] = ' ';
        input[chr_fin] = ' ';
    }
        
    if (dblqote_fin) {
        int g;
        for (g = dblqote_start; g < dblqote_fin + 1; g++) 
            input[g] = ' ';
    }

    return i;
    
}

void copy (char to[], char from[]){
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}

