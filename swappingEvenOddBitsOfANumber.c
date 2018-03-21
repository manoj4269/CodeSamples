#include <stdio.h>

int swap_bit(int n){
    int x = n, even_bits, odd_bits;
    even_bits = x & 0xAAAAAAAA;
    odd_bits = x & 0x55555555;
    
    even_bits >>= 1;
    odd_bits <<= 1;
    
    x = even_bits | odd_bits;
    return x;
}

int main()
{
    int x = 23;
    x = swap_bit(23);
    printf("%d", x);
    
}
