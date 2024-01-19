#include <stdio.h>


void squeeze(char s[], char c[]);

int main () {

    char s[] = "Test";
    char c[] = "Tax";
    squeeze(s, c);
    printf("Result should be est and is : %s\n", s);

    char s1[] = "Test";
    char c1[] = "Test";
    squeeze(s1, c1);
    printf("Result should be " " and is : %s\n", s1);
    

    char s2[] = "Hello World";
    char c2[] = "ppppppppppppppppppppppppppppp";
    squeeze(s2, c2);
    printf("Result should be Hello World and is : %s\n", s2);
    return 0;
}

void squeeze(char s[], char c[]){
   
    int i, j, sq;
    int is_match = 0;

    for (i = sq = 0; s[i] != '\0'; i++) {
        
        is_match = 0;
        for (j = 0; c[j] != '\0'; j++) {
            if (s[i] == c[j]){
                is_match = 1;
                break;
            }
        }

        if (!is_match) 
            s[sq++] = s[i]; 
    }
    s[sq] = '\0';
}

