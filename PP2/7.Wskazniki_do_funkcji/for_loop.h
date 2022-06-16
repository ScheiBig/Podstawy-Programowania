#pragma once

typedef void (*iteration)(double);

void for_loop(double start, double step, double end_ex, iteration lambda);

void print_value(double value);
void print_accumulated(double value);
void print_square(double value);
void print_abs(double value);
