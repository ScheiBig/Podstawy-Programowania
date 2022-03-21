#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "my_utils.h"

struct student_t
{
    char name[20];
    char surname[40];
    int index;
};

struct student_t* read(struct student_t* p, int* err_code);
void show(const struct student_t* p);

int main()
{
    struct student_t p;
    int result;
    if (read(&p, &result) == NULL)
    {
        _e_exit(result, eINPUT_invalid_msg)
    }
    show(&p);
    return 0;
}

struct student_t* read(struct student_t* p, int* err_code)
{
    if (p == NULL)
    {
        cond_assign_nn(err_code, 1)
        return NULL;
    }
    print_ln("Enter student credentials: ");
    char cur_char;
    int i;
    bool had_comma = false;
    //------
    //
    // Name
    // 
    //------
    for (i = 0; i < 19; ++i)
    {
        if ((cur_char = getchar()) == ',')
        {
            had_comma = true;
            break;
        }
        else if (is_letter(cur_char))
        {
            *(p->name + i) = cur_char;
        }
        else
        {
            cond_assign_nn(err_code, 1)
            return NULL;
        }
    }
    *(p->name + i) = str_term;
    if (had_comma)
    {
        if (getchar() != ' ')
        {
            cond_assign_nn(err_code, 1)
            return NULL;
        }
        had_comma = false;
    }
    else
    {
        if (getchar() != ',' || getchar() != ' ')
        {
            cond_assign_nn(err_code, 1)
            return NULL;
        }
    }
    //------
    //
    // Surname
    // 
    //------
    for (i = 0; i < 39; ++i)
    {
        if ((cur_char = getchar()) == ',')
        {
            had_comma = true;
            break;
        }
        else if (is_letter(cur_char) || cur_char == '-' || cur_char == ' ' || cur_char == '.')
        {
            *(p->surname + i) = cur_char;
        }
        else
        {
            cond_assign_nn(err_code, 2)
            return NULL;
        }
    }
    *(p->surname + i) = str_term;
    if (had_comma)
    {
        if (getchar() != ' ')
        {
            cond_assign_nn(err_code, 2)
            return NULL;
        }
    }
    else
    {
        if (getchar() != ',' || getchar() != ' ')
        {
            cond_assign_nn(err_code, 2)
            return NULL;
        }
    }
    //------
    //
    // Index
    // 
    //------
    p->index = 0;
    for (i = 0; i < 9; ++i)
    {
        if ((cur_char = getchar()) == '\n' && i > 0)
        {
            break;
        }
        else if (is_digit(cur_char))
        {
            p->index *= 10;
            p->index += ctoi(cur_char);
        }
        else
        {
            cond_assign_nn(err_code, 3)
            return NULL;
        }
    }

    cond_assign_nn(err_code, 0)
    return p;
}

void show(const struct student_t* p)
{
    if (p != NULL)
    {
        printf("%s %s, %d", p->name, p->surname, p->index);
    }
}

