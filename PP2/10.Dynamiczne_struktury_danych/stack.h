#pragma once

typedef struct stack_t
{
    int head;
    int capacity;
    int* data;
}*p_stack;

typedef const struct stack_t* pc_stack;

int stack_init(p_stack* stack, int N);
int stack_push(p_stack stack, int value);
int stack_pop(p_stack stack, int* err_code);
void stack_display(pc_stack stack);
void stack_free(p_stack stack);
