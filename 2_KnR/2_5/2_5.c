#include <stdio.h>


int any(char s[], char c[]);

int main () {

    char s[] = "test";
    char c[] = "tax";
    int res = any(s, c);
    printf("any is 0 %i \n", res);

    char s1[] = "test";
    char c1[] = "pppppppppllllllllll,,,,....mmmnnnaaaaaajjjjjjjje";
    int res1 = any(s1, c1);
    printf("any is 1 %i \n", res1);
    

    char s2[] = "hello world";
    char c2[] = "ppppppppppppppppppppppppppppp";
    int res2 = any(s2, c2);
    printf("any is -1 %i \n", res2);
    
    char s4[] = "test";
    char c4[] = "pppppppppllllllllll,,,,....mmmnnnaaaaaajjjjjjjjs";
    int res4 = any(s4, c4);
    printf("any is 2 %i \n", res4);
    return 0;
}

int any(char s[], char c[]){
   
    int i, j, sq;
    int is_match = 0;

    for (i = sq = 0; s[i] != '\0'; i++) { 
        for (j = 0; c[j] != '\0'; j++) {
            if (s[i] == c[j]){
                return i;
            }
        }
    }
    return -1;
}



