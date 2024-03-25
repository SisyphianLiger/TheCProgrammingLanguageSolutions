#include <ctype.h>
#include <math.h>
#include <stdio.h>


double atof(char s[]);

int main(int argc, char *argv[]) {
  
    printf("%f\n", atof("123.45e6"));
    printf("%f\n", atof("123.45E-6"));

    return 0;
}

double atof(char s[]){
    
    double val, power;
    int i, sign;
   
    for (i = 0; isspace(s[i]); i++);
    
    sign = (s[i] == '-') ? -1 : 1;
        
    if (s[i] == '+' || s[i] == '-')
        i++;

    for (val = 0.0; isdigit(s[i]); i++) 
        val = 10.0 * val + s[i] - '0';

    if (s[i] == '.')
        i++;

    for (power = 1.0; isdigit(s[i]); i++){
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    // Start to solve
    if (s[i] == 'e' || s[i] == 'E'){
        i++;
        if (s[i] == '-') {
            sign = -1; 
            i++;
        }
        else 
            sign = 1;
        
        for (power = 0.0; isdigit(s[i]); i++) 
            power = 10.0 * power + s[i] - '0';
         

        return sign * val * (pow(10.0, power));
    }

 

    return sign * val / power;
}
