#include <stdio.h>

typedef unsigned long long int uLonger;

int main()
{
    uLonger dec_powers[21];
    dec_powers[0] = 1;
    dec_powers[1] = 10;
    for (int i = 2; i < 20; ++i) dec_powers[i] = dec_powers[i - 1] * 10;

    for (int i = 0; i < 20; ++i) printf("10 do potegi %2d = %20llu\n", i, dec_powers[i]);

    return 0;
}