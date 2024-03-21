#include <stdio.h>
#include <strings.h>

#define BUFFER 1000
#define ZERO 48
#define NINE 57
#define SUL 65
#define BUL 90
#define SLL 97
#define BLL 122
#define NULSPACE 1
/*
 *
 * Assignment 3.3: Write a function expand(s1,s2) that expands shorthand 
 * notations like a-z in the string s1 into the equivalent complete list 
 * abc...xyz in s2. Allow for letters of either case and digits, and be 
 * prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a 
 * leading or trailing - is taken literally.
 *
 * */

/*
 * Case 1 - a - z --> a,b,c,d,e,.....x,y,z
 * Case 2 - a - b - c --> a,b,c
 * Case 3 - a-z0-9 -> a,b,c...x,y,z0123456789
 * Case 4 - -a-z -> a,b,c...x,y,z
 *
 *  0 - 9 --> 48 -> 57
 *  A - Z --> 65 -> 90 
 *  a - z --> 97 -> 122
 * */


void expand(char s1[], char s2[]);
int s2len(char s1[]);


int main () {



    char * test1 = "-0-1-2-3-4-5-9a-z----A-Z";
    char * test2 = "a-z1-2-3-4-5-9A-Z";
    char * test3 = "A-Z1-2-3-4-5-9a-z";
    // Passeed first part
    // printf("len should be %i, and is %i\n", 62, s2len(test1));
    char t1[s2len(test1) + NULSPACE];
    char t2[s2len(test1) + NULSPACE];
    char t3[s2len(test1) + NULSPACE];

    expand(test1, t1);
    printf("Result of t1: %s\n", t1);
    expand(test2, t2);
    printf("Result of t2: %s\n", t2);
    expand(test3, t3);
    printf("Result of t3: %s\n", t3);

    return 0;

}

/*
 * NEED TO MAKE SURE WHAT COMES FIRST COMES OUT FIRST 
 * 0-9a-z == 0,1,2...xyz
 *
 * Try to use Arrays of ranges 0-9 (10) a-z (26), A-Z(26) 
 * and run through s1 and see if slots are filled within the Arrays
 * if even then print out sequence
 *
 * Need to figure out increment for array such that we keep the first 
 * but and replace indefinitely to the next
 * TRY: having an elif (s1[i] is full, replace with new s[i]
 *                else s1[i] to else statement and increment 
 * */
void expand(char s1[], char s2[]){
    
    int len = s2len(s1);


    int i = 0;

    // Used to do the output of the expand
    int order_array[6];
    for (int x = 0; x < 6; x ++) 
        order_array[x] = 0;    

    int oa = 0;
    int z_to_n_filled = 0;
    int z_to_n_filled_two = 0;
    int a_to_z_filled = 0;
    int a_to_z_filled_two = 0;
    int ua_to_uz_filled = 0;
    int ua_to_uz_filled_two = 0;

    while (s1[i] != '\0'){

        if (s1[i] >= ZERO && s1[i] <= NINE){
            if (order_array[oa] == 0 && !z_to_n_filled) {
                order_array[oa++] = s1[i];    
                z_to_n_filled = 1;
            }
            else if (order_array[oa] == 0 && z_to_n_filled && !z_to_n_filled_two) {
                order_array[oa++] = s1[i]; 
                z_to_n_filled_two = 1;
            } 
            else {
                order_array[oa - 1] = s1[i]; 
            }
        }

        if (s1[i] >= SUL && s1[i] <= BUL) {
            if (order_array[oa] == 0 && !ua_to_uz_filled) {
                order_array[oa++] = s1[i]; 
                ua_to_uz_filled = 1;
            }
            else if (order_array[oa] == 0 && ua_to_uz_filled && !ua_to_uz_filled_two) {
                order_array[oa++] = s1[i]; 
            } 
            else {
                order_array[oa - 1] = s1[i];

            }
        }
        if (s1[i] >= SLL && s1[i] <= BLL) {
            if (order_array[oa] == 0 && a_to_z_filled == 0) {
                order_array[oa++] = s1[i];
                a_to_z_filled = 1;
            }
            else if (order_array[oa] == 0 && a_to_z_filled && !a_to_z_filled_two) {
                order_array[oa++] = s1[i]; 
            }
            else 
                order_array[oa - 1] = s1[i]; 
        }
        
        ++i;

    }

    // for (int x = 0; x < 6; x++) 
    //     printf("%i\n", order_array[x]);

    // Add Results to the s2 string 
    int first_limit = order_array[1] - order_array[0] + 1;
    int second_limit = order_array[3] - order_array[2] + 1;
    int third_limit = order_array[5] - order_array[4] + 1;

    // printf("The total of limits is %i\n", first_limit + second_limit + third_limit);
    // printf("The first limit is %i\n", first_limit);
    // printf("The second limit is %i\n", second_limit);
    // printf("The third limit is %i\n", third_limit);

    int let_or_num = order_array[0];
    
    int index = 0;
    for ( ; index < first_limit; index++) {
        s2[index] = let_or_num++; 
    }

    // Continue on updating index here until all are done :)
   
    let_or_num = order_array[2];
    for (; index < first_limit + second_limit; index++) 
        s2[index] = let_or_num++; 

    let_or_num = order_array[4];
    for (index = index; index < first_limit + second_limit + third_limit; index++) 
        s2[index] = let_or_num++; 

    s2[index++] = '\0';
}


/* Bit Rudimentary but don't know an elegant way to extract it 
 *
 *
 * */
int s2len(char s1[]) {
  
    int low_num = 0;
    int high_num = 0;

    int low_big_let = 0;
    int high_big_let = 0;

    int low_sma_let = 0;
    int high_sma_let = 0;


    int i = 0;
    while (s1[i] != '\0'){

        if (s1[i] >= ZERO && s1[i] <= NINE){
            if (low_num == 0) 
                low_num = s1[i];
            else 
                high_num = s1[i];
        }

        if (s1[i] >= SUL && s1[i] <= BUL) {
            if (low_big_let == 0)
                low_big_let = s1[i];
            else
                high_big_let = s1[i];
        }

        if (s1[i] >= SLL && s1[i] <= BLL) {
            if (low_sma_let == 0)
                low_sma_let = s1[i];
            else 
               high_sma_let = s1[i]; 
        }
        i++;
    }

    int res = (1 + high_num - low_num) 
                + (1 + high_big_let - low_big_let)
                + (1 + high_sma_let - low_sma_let);
    
    return res;
}


