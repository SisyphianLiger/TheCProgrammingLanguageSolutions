#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>     /* for atof() */ 

#define MAXOP 100       /* Max size of operand or operator */
#define NUMBER '0'      /* signal that a number was found */ 


#define MAXVAL 100       /* maximum depth of vale stack*/
int sp = 0;              /* next free stack position */
double val[MAXVAL];      /* value stack */



// To be split later 
void push(double);
double pop(void);

// To be split later in Header Files
int getop(char []);
int getch(void);
void ungetch(int);

// to be plit into header files
#define BUFSIZE 100
char buf[BUFSIZE]; // buffer for ungetch
int bufp = 0;


int main(int argc, char *argv[]) {

    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s) != EOF)) {
        
        switch (type) {
       
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                 printf("error: zero division\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }

    return 0;
}


/* Simple Stack Operation, pops to a array if the MAXVAL can hold it */
void push(double f) {

    if (sp < MAXVAL) 
        val[sp++] = f;
    else printf("error: stack full, can't push %g\n", f);

}

/* Simple Stack Operation pops the value off the stack so long as a val exists */
double pop(void) {

    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }

}



/* getop get the nex operator of numeric operand */
int getop(char s[]) {
    
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t');

    s[1] = '\0';
    
    if(!isdigit(c) && c != '.')
        return c; // Not a number
   
    i = 0;
    if (isdigit(c))             /* collect integer part of num */
        while(isdigit(s[++i] = c = getch()));

    if (c == '.')               /* collect fraction part */ 
        while (isdigit(s[++i] = c = getch()));

    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    
    return NUMBER;

}

/* getch: get a possibly pushed back character */ 
int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* ungetch: push a charaacter back on input */ 
void ungetch(int c ) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else 
        buf[bufp++] = c;
}

