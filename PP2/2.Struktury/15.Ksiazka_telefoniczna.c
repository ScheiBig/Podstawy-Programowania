#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "my_utils_v2.h"

typedef struct entry_t
{
    char name[20];
    char last_name[40];
    int number;
} entry_s;

void display(const struct entry_t* p);
int load_phonebook_t(const char* filename, struct entry_t* p, int size);
const struct entry_t* find_by_last_name(const struct entry_t* p, int size, const char* name);

int main()
{
    entry_s contacts[10];
    char f_buffer[101], ln_buffer[40];
    print_ln("Enter file path:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%100s", f_buffer) != 1)
    {
        __m_exit(eFILE_noaccess);
    }
    switch (load_phonebook_t(f_buffer, contacts, 10))
    {
    case -1: case -2:
    {
        __m_exit(eFILE_noaccess);
    }
    case 0:
    {
        __m_exit(eFILE_corrupted);
            
    }
    default:
        break;
    }
    print_ln("Enter last name to find:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%39s", ln_buffer) != 1)
    {
        __m_exit(eINPUT_invalid);
    }
    const entry_s* found;

    if ((found = find_by_last_name(contacts, 10, ln_buffer)) == NULL)
    {
        printf("Couldn't find name");
    }
    else
    {
        display(found);
    }

    return 0;
}

void display(const struct entry_t* p)
{
    if (p != null)
    {
        printf_ln("Name: %s", p->name);
        printf_ln("Last name: %s", p->last_name);
        printf("Phone number: %d", p->number);
    }
}

int load_phonebook_t(const char* filename, struct entry_t* p, int size)
{
    if (filename == null || strlen(filename) == 0 || p == null || size < 1)
    {
        return -1;
    }
    FILE* file;
    if ((file = fopen(filename, "r")) == NULL)
    {
        return -2;
    }
    u_int read_len = 0;
    char buffer[100];
    while (true)
    {
        if (fgets(buffer, 100, file) == null)
        {
            break;
        }
        //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
        if (sscanf(buffer, " %19[^|] | %39[^|] | %d", (p + read_len)->name, (p + read_len)->last_name, &(p + read_len)->number) != 3)
        {
            continue;
        }
        *((p + read_len)->name + strlen((p + read_len)->name) - 1) = str_term;
        *((p + read_len)->last_name + strlen((p + read_len)->last_name) - 1) = str_term;
        ++read_len;
        if (read_len >= (unsigned)size)
        {
            break;
        }
    }

    fclose(file);
    return (int)read_len;
}

const struct entry_t* find_by_last_name(const struct entry_t* p, int size, const char* last_name)
{
    if (p == null || size < 1 || last_name == null || strlen(last_name) == 0)
    {
        return null;
    }
    for (const entry_s* s = p; s < p + size; ++s)
    {
        if (strcmp(s->last_name, last_name) == 0)
        {
            return s;
        }
    }
    return null;
}
