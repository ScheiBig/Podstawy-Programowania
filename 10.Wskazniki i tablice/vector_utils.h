#pragma once

int read_vector(int* vec, int size, int stop_value);
void display_vector(const int* vec, int size);

enum direction
{
    ROTATE_RIGHT = 1, ROTATE_LEFT = 2
};
int shift(int* array, int array_size, int positions_to_shift, enum direction dir);

#define vuDATA_invalid -2
#define vuVEC_invalid -1

#ifndef vuEOV
#define vuEOV 0
#endif
