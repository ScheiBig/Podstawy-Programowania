#ifndef PODSTAWY_PROGRAMOWANIA_1_TRUE_RAND_H
#define PODSTAWY_PROGRAMOWANIA_1_TRUE_RAND_H

/*
 * Example implementation of crypto-secure, true-pararandom generator
 */


#include <stdio.h>

FILE *___true_rand_file___;

union true_random_data
{
    char raw[8];
    short _short;
    unsigned short _ushort;
    int _int;
    unsigned int _uint;
    long _long;
    unsigned long _ulong;
    long long _longer;
    unsigned long long _ulonger;
};

void init_urandom()
{
    ___true_rand_file___ = fopen("/dev/urandom", "r");
}

union true_random_data generate_true_random()
{
    union true_random_data random;
    fread(random.raw, 1, sizeof(random), ___true_rand_file___);
    return random;
}

void term_urandom()
{
    fclose(___true_rand_file___);
}

#endif //PODSTAWY_PROGRAMOWANIA_1_TRUE_RAND_H
