#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <stdarg.h>
#include <limits.h>
#include <ctype.h>
#include <stdint.h>

#include "big_numbers.h"

void discard_stdin() { while (fgetc(stdin) != '\n'); }

int main()
{
    big_numbers_ps bn;
    cstring buf = (cstring)calloc(201u, sizeof(char));

    if (buf == null) { __m_exit(eMEMORY_cantallocate); }
    if (create_big_numbers(&bn, 10) != 0)
    {
        free(buf);
        __m_exit(eMEMORY_cantallocate);
    }

    print_ln("Enter numbers: ");
    while (true)
    {
        fgets(buf, 201, stdin);
        if (*buf == '\n') { break; }
        
        if (*(buf + strlen(buf) - 1) != '\n') { discard_stdin(); }
        else { *(buf + strlen(buf) - 1) = str_term; }
        
        switch (add_big_number(bn, buf))
        {
        case 1:
            print_ln(eINPUT_invalid);
            continue;
        case 2:
            print_ln(eMEMORY_cantallocate);
            goto break_switch;
        case 3:
            print_ln("Buffer is full");
            goto break_switch;
        default: continue;
        }
    }
break_switch: {}
    if (bn->size != 0) { display(bn); }
    else { print_ln("Buffer is empty"); }
    destroy_big_numbers(&bn);
    free(buf);
    return 0;
}

