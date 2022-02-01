#pragma once

#include "types_utils.h"

int sort(int tab[], int size, enum direction dir, enum algorithm alg);

int bubble_sort_asc(int tab[], int size);
int bubble_sort_desc(int tab[], int size);
int bubble_sort(int tab[], int size, enum direction dir);

int selection_sort_asc(int tab[], int size);
int selection_sort_desc(int tab[], int size);
int selection_sort(int tab[], int size, enum direction dir);

int insertion_sort_asc(int tab[], int size);
int insertion_sort_desc(int tab[], int size);
int insertion_sort(int tab[], int size, enum direction dir);
