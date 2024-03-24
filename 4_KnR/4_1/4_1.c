#include <stdio.h>

/*
 * Write the function strrindex(s,t), which returns the position of
 * the right occurence of t in s or -1 if there is none. 
 * */

int strrindex(char s[], char t[]);

int main(int argc, char *argv[]) {

    char * test1 = "wizardswandwand";
    char * test2 = "nomatchfound";
    char * test3 = "I want to break free";
    
    printf("Test 1 should be 11: is %i\n", strrindex(test1, "wand"));
    printf("Test 2 should be 0: is %i\n", strrindex(test2, "nomatchfound"));
    printf("Test 3 should be -1: is %i\n", strrindex(test3, "biscuits"));
    return 0;
}

/*
 * Solution: On the surface this should be pretty simple, we keep track of 
 * if we are currently in a match...i.e. have a matcher variable when we are 
 * equal...the first time we have a match we record the s_pos, however, if t 
 * is at '\0' then we reset the match variable to 0 and see if the next char 
 * is a match and flip the match var and continue...
 *
 * */


int strrindex(char s[], char t[]){
    
    int pos = -1, tmp_pos = 0,  t_pos = 0, s_pos = 0;

    while (s[s_pos] != '\0') {

        if (s[s_pos] == t[t_pos]) {
            if (!t_pos) {
                tmp_pos = s_pos;
                t_pos++;
            } else if (t[t_pos + 1] == '\0') {
                t_pos = 0;
                pos = tmp_pos;
            } else {
                t_pos++;
            }
        } 
        s_pos++;
    }
    

    return pos;
}
