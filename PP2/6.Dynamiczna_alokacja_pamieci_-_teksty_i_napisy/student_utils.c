#include "student_utils.h"

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

#include "my_utils_v3.h"
#include "my_file.h"

struct student_t* read(int* err_code)
{
    struct student_t* stud = (struct student_t*)calloc(1, sizeof(struct student_t));
    if (stud == null)
    {
        cond_assign_nn(err_code, 4);
        return null;
    }
    
    print_ln("Enter student credentials:");
    p_file buffer = fopen("temp", "w+");
    int chr;
    while ((chr = getc(stdin)) != '\n' && chr != EOF)
    {
        putc(chr, buffer);
    }
    fseek(buffer, 0L, SEEK_SET);

    stream_token word = stream_split(buffer, 0L, ",");
    if (word.start_pos == EOF || word.length == 0)
    {
        cond_assign_nn(err_code, 1);
        fclose(buffer);
        free(stud);
        return null;
    }
    stream_to_string_cpy(stud->name, buffer, word.start_pos, min(19, word.length));
    if (strpbrk(stud->name, ASCIIset_numbers) != null)
    {
        cond_assign_nn(err_code, 1);
        fclose(buffer);
        free(stud);
        return null;
    }
    word.length += 2;
    
    word = stream_split_next(word);
    if (word.start_pos == EOF)
    {
        cond_assign_nn(err_code, 1);
        fclose(buffer);
        free(stud);
        return null;
    }
    if (word.length == 0)
    {
        cond_assign_nn(err_code, 2);
        fclose(buffer);
        free(stud);
        return null;
    }
    stream_to_string_cpy(stud->surname, buffer, word.start_pos, min(39, word.length));
    if (strpbrk(stud->surname, ASCIIset_numbers) != null)
    {
        cond_assign_nn(err_code, 2);
        fclose(buffer);
        free(stud);
        return null;
    }
    word.length += 2;

    word = stream_split_next(word);
    if (word.start_pos == EOF)
    {
        cond_assign_nn(err_code, 2);
        fclose(buffer);
        free(stud);
        return null;
    }
    if (word.length == 0)
    {
        cond_assign_nn(err_code, 3);
        fclose(buffer);
        free(stud);
        return null;
    }
    fseek(buffer, word.start_pos, SEEK_SET);
    if (fscanf(buffer, "%d", &stud->index) != 1 || stud->index < 0)
    {
        cond_assign_nn(err_code, 3);
        fclose(buffer);
        free(stud);
        return null;
    }

    cond_assign_nn(err_code, 0);
    fclose(buffer);
    return stud;
}

void destroy(struct student_t** s)
{
    if (s != null && *s != null)
    {
        free(*s);
        *s = null;
    }
}


void show(const struct student_t* p)
{
    if (p != NULL)
    {
        printf("%s %s, %d", p->name, p->surname, p->index);
    }
}

