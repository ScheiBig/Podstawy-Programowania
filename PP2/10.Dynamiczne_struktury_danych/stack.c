#include "stack.h"

#include <stdlib.h>
#include <limits.h>

#include "my_utils_v3.h"
#include "tested_declarations.h"
#include "rdebug.h"

int stack_init(p_stack * stack, int N)
{
    if (stack == null || N <= 0) { return 1; }
    *stack = (p_stack)calloc(1u, sizeof(struct stack_t));
    p_stack s = *stack;
    if (s == null) { return 2; }
    s->data = (int*)calloc((unsigned)N, sizeof(int));
    if (s->data == null)
    {
        free(s);
        *stack = null;
        return 2;
    }
    s->capacity = N;
    return 0;
}

int stack_push(p_stack stack, int value)
{
    if (stack == null || stack->capacity <= 0 || stack->head < 0 ||
        stack->head > stack->capacity || stack->data == null)
    {
        return 1;
    }
    if (stack->head == stack->capacity)
    {
        int* new_data = (int*)recalloc(stack->data, stack->capacity * sizeof(int), stack->capacity * 2 * sizeof(int));
        if (new_data == null)
        {
            return 2;
        }
        stack->data = new_data;
        stack->capacity *= 2;
    }
    *(stack->data + ((stack->head)++)) = value;
    return 0;
}

int stack_pop(p_stack stack, int* err_code)
{
    if (stack == null || stack->data == null ||
        stack->capacity <= 0 || stack->head < 0 || stack->head > stack->capacity)
    {
        cond_assign_nn(err_code, 1);
        return INT_MIN;
    }
    if (stack->head == 0)
    {
        cond_assign_nn(err_code, 2);
        return INT_MIN;
    }
    cond_assign_nn(err_code, 0);
    return *(stack->data + (--(stack->head)));
}

void stack_display(pc_stack stack)
{
    if (stack == null || stack->data == null ||
        stack->capacity <= 0 || stack->head <= 0 || stack->head > stack->capacity)
    {
        return;
    }
    for (int* s = stack->data + stack->head - 1; s >= stack->data; --s)
    {
        printf("%d ", *s);
    }
    print_n();
}

void stack_free(p_stack stack)
{
    if (stack == null || stack->capacity <= 0 || stack->head < 0 || stack->head > stack->capacity) { return; }
    if (stack->data != null) { free(stack->data); }
    free(stack);
}
