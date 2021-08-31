#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define TAM 10



void misterio1(char b[TAM], float *dec, int i)
{
    if(i < strlen(b))
    {
        if(b[i] == '1')
            *dec = *dec + pow(2,i);
        
        printf("b[i]: %c if b[i] == 1: %.2f \n", b[i], *dec);

        misterio1(b,dec,++i);
    }
}


float misterio2(char b[TAM], float dec, int i)
{
    if(i < strlen(b))
    { 
        printf("b[i]: %c if b[i] == 1: %.2f \n", b[i], dec);
        
        dec = misterio2(b,dec,i+1);
        if(b[i] == '1')
        dec = dec + pow(2,i);
    }
    return(dec);
}

int main()
{
    
    char str[10] = {'1', '0', '1', '1', '0', '1', '1', '0', '1', '1'};

    float dec = 1.0;

    misterio1(str, &dec, 0);

    printf("\n\n");

    misterio2(str, dec, 0);

    return 0;
}