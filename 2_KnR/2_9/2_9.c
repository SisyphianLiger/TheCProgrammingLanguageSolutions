#include <stdio.h>

int bitcount(unsigned x);
int bitstantcnt(unsigned x);

int main () {
    
    printf("bitcount(5) RES: %i\n", bitcount(5));
    printf("bitcount(8) RES: %i\n", bitcount(8));
    printf("bitcount(0) RES: %i\n", bitcount(0));
    printf("bitcount(-1) RES: %i\n", bitcount(-1));

    printf("bitstantcnt(5)  RES: %i\n", bitstantcnt(5));
    printf("bitstantcnt(8)  RES: %i\n", bitstantcnt(8));
    printf("bitstantcnt(0)  RES: %i\n", bitstantcnt(0));
    printf("bitstantcnt(-1)  RES: %i\n", bitstantcnt(-1));
}


int bitstantcnt(unsigned x){

    int cnt = 0;
    while (x != 0) {
        x &= (x - 1);
        cnt++;
    }
    return cnt;
}

    
int bitcount(unsigned x){

    int b;

    for (b = 0; x != 0; x >>= 1) 
        if(x & 01)
            b++;
    return b;
}
