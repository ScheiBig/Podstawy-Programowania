#include "stack.h"

#include <stdlib.h>
#include <stdbool.h>

#include "my_utils_v3.h"
#include "my_file.h"

const struct stack_i STACK = {
    .push = stack_push,
    .pop = stack_pop,
    .destroy = stack_destroy,
    .load = stack_load,
    .save = stack_save,
    .empty = stack_empty
};

int stack_push(stack_s** stack, cstring value)
{
    if (stack == null) { return 1; }
    stack_s* new_node = (stack_s*)MEMORY.allocate_empty(1u, sizeof(stack_s));
    if (new_node == null) { return 2; }
    new_node->sentence = value;
    new_node->prev = *stack;
    *stack = new_node;
    return 0;
}

cstring stack_pop(stack_s** stack, int* err_code)
{
    if (stack == null || STACK.empty(*stack))
    {
        cond_assign_nn(err_code, 1);
        return null;
    }
    cstring value = (*stack)->sentence;
    stack_s* tmp_node = *stack;
    *stack = (*stack)->prev;
    MEMORY.release(tmp_node);
    cond_assign_nn(err_code, 0);
    return value;

}

void stack_destroy(stack_s** stack)
{
    if (stack == null) return;
    while (!STACK.empty(*stack))
    {
        cstring str = STACK.pop(stack, null);
        MEMORY.release(str);
    };
}

int stack_load(stack_s** stack, c_cstring filename)
{
    if (stack == null || !STACK.empty(*stack) ||
        filename == null || strlen(filename) == 0)
    {
        return 1;
    }
    p_file f = fopen(filename, "r");
    if (f == null) { return 2; }

    for (stream_token tok = stream_split(f, 0, "."); tok.delimiters != null; tok = stream_split_next(tok))
    {
        cstring str = (cstring)MEMORY.allocate_empty(tok.length + 2, sizeof(char));
        if (str == null)
        {
            fclose(f);
            STACK.destroy(stack);
            return(3);
        }

        fseek(f, tok.start_pos, SEEK_SET);
        for (size_t i = 0; i < tok.length + 1; ++i)
        {
            *(str + i) = fgetc(f);
        }
        fseek(f, 0l, SEEK_SET);
        if (STACK.push(stack, str) != 0)
        {
            fclose(f);
            STACK.destroy(stack);
            MEMORY.release(str);
            return(3);
        }
    }

    fclose(f);
    return 0;
}

int stack_save(const stack_s* stack, c_cstring filename)
{
    if (stack == null || STACK.empty((stack_s*)stack) ||
        filename == null || strlen(filename) == 0)
    {
        return 1;
    }
    p_file f = fopen(filename, "w");
    if (f == null) { return 2; }


    for (const stack_s* s = stack; s != null; s = s->prev)
    {
        fprintf(f, "%s", s->sentence);
    }

    fclose(f);
    return 0;
}

int stack_empty(stack_s* stack) { return stack == null; }
