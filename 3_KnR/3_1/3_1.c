#include <stdio.h>
#include <time.h>


// #define SMALLBOI INT_MAX / 4
#define SMALLBOI 1000000

int binary_search(int x, int v[], int n);
int b_search_cond(int x, int v[], int n);
int main () {

    int v[SMALLBOI];

    int i;
    for (i = 0; i < SMALLBOI - 1; i++) 
        v[i] = i; 
 
    clock_t t;
    t = clock();
    for (int i = 0; i < SMALLBOI - 1; i++) 
        binary_search(i, v, SMALLBOI);    
    // printf("Binary Search finds %i\n", binary_search(0, v,  SMALLBOI));
    // printf("Binary Search finds %i\n", binary_search(SMALLBOI, v,  SMALLBOI));
    // printf("Binary Search finds %i\n", binary_search(SMALLBOI - 1, v,  SMALLBOI));
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("binary_search() took %f seconds to execute \n", time_taken);


    clock_t t1;
    t1 = clock();
    for (int i = 0; i < SMALLBOI - 1; i++) 
        b_search_cond(i, v, SMALLBOI);    
    // printf("Binary Search COND finds %i\n", b_search_cond(0, v,  SMALLBOI));
    // printf("Binary Search COND finds %i\n", b_search_cond(SMALLBOI, v,  SMALLBOI));
    // printf("Binary Search COND finds %i\n", b_search_cond(SMALLBOI - 1, v,  SMALLBOI));
    t1 = clock() - t1; 
    double time_taken1 = ((double)t)/CLOCKS_PER_SEC;
    printf("b_search_cond() took %f seconds to execute \n", time_taken);

    return 0;
}

int binary_search(int x, int v[], int n){
    
    int low, mid, high;

    low = 0;
    high = n - 1;

    while (low <= high){
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid] + 1)
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}


int b_search_cond(int x, int v[], int n){

    int low, mid, high;
   
    low = 0;
    high = n - 1;

    while (low < high && v[mid] != x){

        if (x > v[mid])
            low = mid + 1;
        else
            high = mid - 1;

        mid = (low + high) / 2;
    }

    if (v[mid] == x)
        return mid;
    else 
        return -1;
}
