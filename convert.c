#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

void div_convert(uint32_t n, int base, char *out);

void print_tables(uint32_t n){//Show original, left shift by 3 and with 0xFF
    char bin[33], oct[12], hex[9];

    //og #
    div_convert(n,2,bin);
    div_convert(n, 8, oct);
    div_convert(n, 16, hex);
    printf("Original: Binary=%s Octal=%s Decimal=%u Hex=%s\n",bin, oct, n, hex);

    // Left shift by 3
    uint32_t shifted = n << 3;
    div_convert(shifted, 2, bin);
    div_convert(shifted, 8, oct);
    div_convert(shifted, 16, hex);
    printf("Left Shift by 3: Binary=%s Octal=%s Decimal=%u Hex=%s\n",bin, oct, shifted, hex);

    //0xFF
    uint32_t masked = n & 0xFF;
    div_convert(masked, 2, bin);
    div_convert(masked, 8, oct);
    div_convert(masked, 16, hex);
    printf("Masked with 0xFF: Binary=%s Octal=%s Decimal=%u Hex=%s\n",bin, oct, masked, hex);

}
void sub_convert(uint32_t n, int base, char *out){//Find highest power,subtract multiples
    uint32_t i = 1;

        if (n == 0) {
        out[0] = '0';
        out[1] = '\0';
        return;
    }

    while(i<=n/base){
        i*=base;
    }

int j = 0;
    while (i > 0) {
        int digit = n / i;
        n %= i;
        out[j++] = (digit < 10) ? ('0' + digit) : ('A' + digit - 10);
        i /= base;
    }
    out[j] = '\0';
}


void div_convert(uint32_t n, int base, char *out){//Repeatedly divide by base,collecting remainders
    char buffer[65];
    int i = 0;

    if (n==0){
        out[0]='0';
        out[1]='\0';
        return;
    }while(n>0){
        int remainder = n%base ;
        if(remainder < 10){
            buffer[i++] = '0' + remainder;
        }
        else{
            buffer[i++] = 'A'+(remainder-10);
        }
        n /= base;
    }
    buffer[i]='\0';
    
    for(int j = 0; j<i;j++){
        out[j]=buffer[i-j-1];
    }
    out[i]='\0';
}