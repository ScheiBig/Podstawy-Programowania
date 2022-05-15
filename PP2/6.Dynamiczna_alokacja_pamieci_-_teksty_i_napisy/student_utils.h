#pragma once

struct student_t
{
    char name[20];
    char surname[40];
    int index;
};

struct student_t* read(int* err_code);
void destroy(struct student_t** s);

void show(const struct student_t* p);
