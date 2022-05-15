#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "my_utils_v3.h"
#include "student_utils_v2.h"

int main()
{
    struct student_t* p;
    int err_code;
    if ((p = read(&err_code)) == NULL)
    {
        if (err_code == 4)
        {
            __m_exit(eMEMORY_cantallocate);
        }
        _m_exit(err_code, eINPUT_invalid);
    }
    show(p);
    destroy(&p);
    return 0;
}