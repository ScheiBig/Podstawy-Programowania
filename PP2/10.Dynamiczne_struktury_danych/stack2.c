#include "stack2.h"

#include <stdlib.h>
#include <stdbool.h>

#include "my_utils_v3.h"

const struct stack_i STACK = {
    .init = stack_init,
    .push = stack_push,
    .display = stack_display,
    .pop = stack_pop,
    .destroy = stack_destroy,
    .empty = stack_empty
};

int stack_init(p_stack* stack)
{
    if (stack == null) { return 1; }
    *stack = (p_stack)calloc(1u, sizeof(s_stack));
    p_stack s = *stack;
    if (s == null) { return 2; }
    return 0;
}

int stack_push(p_stack stack, int value)
{
    if (stack == null) { return 1; }
    p_node new_node = (p_node)calloc(1u, sizeof(s_node));
    if (new_node == null) { return 2; }
    new_node->data = value;
    new_node->next = stack->head;
    stack->head = new_node;
    return 0;
}

void stack_display(pc_stack stack)
{
    if (STACK.empty(stack)) { return; }
    for (p_node n = stack->head; n != null; n = n->next) { printf("%d ", n->data); }
    print_n();
}

int stack_pop(p_stack stack, int* err_code)
{
    if (STACK.empty(stack))
    {
        cond_assign_nn(err_code, 1);
        return 0;
    }
    int value = stack->head->data;
    p_node tmp_node = stack->head;
    stack->head = stack->head->next;
    free(tmp_node);
    cond_assign_nn(err_code, 0);
    return value;
}

void stack_destroy(p_stack* stack)
{
    if (stack == null || *stack == null) { return; }
    for (; !STACK.empty(*stack); STACK.pop(*stack, null));
    free(*stack);
}

int stack_empty(pc_stack stack)
{
    if (stack == null) { return 2; }
    return stack->head == null;
}

