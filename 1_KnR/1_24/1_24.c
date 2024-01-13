#include <stdio.h>
#include <strings.h>

#define MAXLINE 100     /* size of buffer for strings */
#define END 0           /* If there is a newline with no input */
#define TABN 4          /* How big \t should be */
#define FSLASH 47       /* To match / in the loop */
#define AST 42          /* To match * in the loop */
#define SNGQUOTE 39     /* To match ' in the loop */
#define DBLQUOTE 34     /* To match " in the loop */


int get_line(char s[], int limit, int num);
void copy(char to[], char from[]);

int main () {


    int len;
    char output[MAXLINE];
    char input[MAXLINE];
    int i = 0; 
    while ((len = get_line(input, MAXLINE, i)) > END) {
        
        ++i; 
        copy(output, input); 
        printf("%s\n",output);

    }

    return 0;

}


int get_line(char input[], int lim, int line_num) {
    
    int i, c;

    int slash_one = 0;
    int slash_ast_one = 0, slash_ast_two = 0;
    int dblqote = 0, dblqote_start = 0, dblqote_fin = 0;
    int chr_start = 0, chr_fin = 0;


    for (i = 0; i < lim - 2 && (c = getchar()) != EOF && c != '\n'; i++) {
        
        // Store input
        input[i] = c; 
       
        /*          Sort Through //              */
        if(i > 0  && input[i - 2] != FSLASH && input[i-1] == FSLASH && c != FSLASH && c != AST) 
                slash_one = i-1;
        

        /*          Sort Through slash ast              */
        if (i > 1 && input[i-1] == FSLASH && c == AST) 
                slash_ast_one = i-1;
        
        if (i > 1 && input[i-1] == AST && c == FSLASH) 
                slash_ast_two = i;
        


        /*      Sort Through 'J'        */
        if (c == SNGQUOTE && chr_start)
            chr_fin = i;

        if (c == SNGQUOTE && chr_start == 0)
            chr_start = i;

 
        
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


    // If not slash_two then we print error at line number 
    if (slash_one) {
        printf("Error: missing slash at line %i\n", line_num);
        return i;
    }
    
    
    // If non complete asterisk then we let the user know that line has an error
    if (slash_ast_one && !slash_ast_two) {
        printf("Error: missing closing slash for /**/ at line %i\n", line_num);
        return i;
    }
   
    // If missing one quote or the other then we say hey error man
    if (chr_start  && !chr_fin) {
        printf("Error: missing single quote ' at line %i\n", line_num);
        return i;
    }
    
        
    if (dblqote_start && !dblqote_fin) {
        printf("Error: missing double quote \" at line %i\n", line_num);
        return i;
    }

    return i;
    
}

void copy (char to[], char from[]){
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}

