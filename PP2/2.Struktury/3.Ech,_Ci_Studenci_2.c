#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "my_utils_v2.h"

struct student_t
{
    char name[20];
    char surname[40];
    int index;
    char field[50];
    char faculty[80];
    int year;
};

struct student_t* read(struct student_t* p, int* err_code);
struct student_t* set(
    struct student_t* student,
    const char* name,
    const char* surname,
    int index,
    const char* field,
    const char* faculty,
    int year,
    int* err_code);
void display(const struct student_t* p);
void display_name(const struct student_t* student);
void display_surname(const struct student_t* student);
void display_index(const struct student_t* student);
void display_field(const struct student_t* student);
void display_faculty(const struct student_t* student);
void display_year(const struct student_t* student);

int main()
{
    struct student_t p, me;
    set(&me, "Marcin", "Jeznach", 241204, "Informatyka", "WEEIA", 2022, NULL);
    int result;
    if (read(&p, &result) == NULL)
    {
        print_ln(eINPUT_invalid);
    }
    else
    {
        display(&p);
        print_n();
    }
    display(&me);
    print_n();
    if (result != 0)
    {
        return result;
    }
    display_name(&p);
    display_surname(&p);
    display_index(&p);
    display_field(&p);
    display_faculty(&p);
    display_year(&p);

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
        else if (is_letter(cur_char) || cur_char == '-' || cur_char == ' ' || cur_char == '.')
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
    if (i == 0)
    {
        cond_assign_nn(err_code, 1)
        return NULL;
    }
    if (had_comma)
    {
        if (getchar() != ' ')
        {
            cond_assign_nn(err_code, 2)
            return NULL;
        }
        had_comma = false;
    }
    else
    {
        if (getchar() != ',')
        {
            cond_assign_nn(err_code, 1)
            return NULL;
        }
        if (getchar() != ' ')
        {
            cond_assign_nn(err_code, 2)
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
    if (i == 0)
    {
        cond_assign_nn(err_code, 2)
        return NULL;
    }
    if (had_comma)
    {
        if (getchar() != ' ')
        {
            cond_assign_nn(err_code, 3)
            return NULL;
        }
        had_comma = false;
    }
    else
    {
        if (getchar() != ',')
        {
            cond_assign_nn(err_code, 2)
            return NULL;
        }
        if (getchar() != ' ')
        {
            cond_assign_nn(err_code, 3)
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
        if ((cur_char = getchar()) == ',' && i > 0)
        {
            had_comma = true;
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
    if (i == 0)
    {
        cond_assign_nn(err_code, 3)
        return NULL;
    }
    if (had_comma)
    {
        if (getchar() != ' ')
        {
            cond_assign_nn(err_code, 4)
            return NULL;
        }
        had_comma = false;
    }
    else
    {
        if (getchar() != ',')
        {
            cond_assign_nn(err_code, 3)
            return NULL;
        }
        if (getchar() != ' ')
        {
            cond_assign_nn(err_code, 4)
            return NULL;
        }
    }
    //------
    //
    // Field
    // 
    //------
    for (i = 0; i < 49; ++i)
    {
        if ((cur_char = getchar()) == ',')
        {
            had_comma = true;
            break;
        }
        else if (is_letter(cur_char) || cur_char == '-' || cur_char == ' ' || cur_char == '.')
        {
            *(p->field + i) = cur_char;
        }
        else
        {
            cond_assign_nn(err_code, 4)
            return NULL;
        }
    }
    *(p->field + i) = str_term;
    if (i == 0)
    {
        cond_assign_nn(err_code, 4)
        return NULL;
    }
    if (had_comma)
    {
        if (getchar() != ' ')
        {
            cond_assign_nn(err_code, 5)
            return NULL;
        }
        had_comma = false;
    }
    else
    {
        if (getchar() != ',')
        {
            cond_assign_nn(err_code, 4)
            return NULL;
        }
        if (getchar() != ' ')
        {
            cond_assign_nn(err_code, 5)
            return NULL;
        }
    }
    //------
    //
    // Faculty
    // 
    //------
    for (i = 0; i < 79; ++i)
    {
        if ((cur_char = getchar()) == ',')
        {
            had_comma = true;
            break;
        }
        else if (is_letter(cur_char) || cur_char == '-' || cur_char == ' ' || cur_char == '.')
        {
            *(p->faculty + i) = cur_char;
        }
        else
        {
            cond_assign_nn(err_code, 5)
            return NULL;
        }
    }
    *(p->faculty + i) = str_term;
    if (i == 0)
    {
        cond_assign_nn(err_code, 5)
        return NULL;
    }
    if (had_comma)
    {
        if (getchar() != ' ')
        {
            cond_assign_nn(err_code, 6)
            return NULL;
        }
    }
    else
    {
        if (getchar() != ',')
        {
            cond_assign_nn(err_code, 5)
            return NULL;
        }
        if (getchar() != ' ')
        {
            cond_assign_nn(err_code, 6)
            return NULL;
        }
    }
    //------
    //
    // Year
    // 
    //------
    p->year = 0;
    for (i = 0; i < 9; ++i)
    {
        if ((cur_char = getchar()) == '\n' && i > 0)
        {
            break;
        }
        else if (is_digit(cur_char))
        {
            p->year *= 10;
            p->year += ctoi(cur_char);
        }
        else
        {
            cond_assign_nn(err_code, 6)
            return NULL;
        }
    }
    if (i == 0)
    {
        cond_assign_nn(err_code, 6)
        return NULL;
    }

    cond_assign_nn(err_code, 0)
    return p;
}

struct student_t* set(
    struct student_t* student,
    const char* name,
    const char* surname,
    int index,
    const char* field,
    const char* faculty,
    int year,
    int* err_code)
{
    if (student == NULL)
    {
        cond_assign_nn(err_code, 1)
        return NULL;
    }
    if (name == NULL ||
        surname == NULL ||
        field == NULL ||
        faculty == NULL ||
        strlen(name) > 19 ||
        strlen(surname) > 39 ||
        strlen(field) > 49 ||
        strlen(faculty) > 79)
    {
        cond_assign_nn(err_code, 1)
        return NULL;
    }
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    memcpy(&student->name, name, strlen(name));
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    memcpy(&student->surname, surname, strlen(surname));
    student->index = index;
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    memcpy(&student->field, field, strlen(field));
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    memcpy(&student->faculty, faculty, strlen(faculty));
    student->year = year;
    cond_assign_nn(err_code, 0)
    return student;
}

void display(const struct student_t* p)
{
    if (p != NULL)
    {
        printf("%s %s, index number: %d, was ", p->name, p->surname, p->index);
        if (is_vovel(*p->field))
        {
            printf("an");
        }
        else
        {
            printf("a");
        }
        printf(" %s student at the %s in %d.", p->field, p->faculty, p->year);
    }
}

void display_name(const struct student_t* student)
{
    if (student != NULL)
    {
        printf_ln("Student name: %s", student->name);
    }
}

void display_surname(const struct student_t* student)
{
    if (student != NULL)
    {
        printf_ln("Student surname: %s", student->surname);
    }
}

void display_index(const struct student_t* student)
{
    if (student != NULL)
    {
        printf_ln("Index: %d", student->index);
    }
}

void display_field(const struct student_t* student)
{
    if (student != NULL)
    {
        printf_ln("Field: %s", student->field);
    }
}

void display_faculty(const struct student_t* student)
{
    if (student != NULL)
    {
        printf_ln("Faculty: %s", student->faculty);
    }
}

void display_year(const struct student_t* student)
{
    if (student != NULL)
    {
        printf_ln("Year: %d", student->year);
    }
}
