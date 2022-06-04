#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "my_utils_v3.h"
#include "wordcross_utils.h"

int main()
{
    cstring first;
    cstring second;
    cstring third;
    cstring fourth;
    if ((first = (cstring)calloc(11, sizeof(char))) == null)
    {
        __m_exit(eMEMORY_cantallocate);
    }
    if ((second = (cstring)calloc(11, sizeof(char))) == null)
    {
        free(first);
        __m_exit(eMEMORY_cantallocate);
    }
    if ((third = (cstring)calloc(11, sizeof(char))) == null)
    {
        free(first);
        free(second);
        __m_exit(eMEMORY_cantallocate);
    }
    if ((fourth = (cstring)calloc(11, sizeof(char))) == null)
    {
        free(first);
        free(second);
        free(third);
        __m_exit(eMEMORY_cantallocate);
    }

    print_ln("Enter words:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%10s %10s %10s %10s", first, second, third, fourth) != 4)
    {
        free(first);
        free(second);
        free(third);
        free(fourth);
        __m_exit(eINPUT_invalid);
    }

    cstring* f_s_cross;
    cstring* t_f_cross;
    cstring* all_cross;

    switch (create_double_leading_word_cross(first, second, third, fourth, &all_cross, &f_s_cross, &t_f_cross))
    {
    case 1:
        free(first);
        free(second);
        free(third);
        free(fourth);
        __m_exit(eINPUT_invalid);
    case 2:
        free(first);
        free(second);
        free(third);
        free(fourth);
        _m_exit(0, "Unable to make two crosses");
    case 3:
        free(first);
        free(second);
        free(third);
        free(fourth);
        __m_exit(eMEMORY_cantallocate);
    }


    _print_cross(f_s_cross);
    print_n();
    _print_cross(t_f_cross);
    print_n();
    _print_cross(all_cross);

    destroy(f_s_cross);
    destroy(t_f_cross);
    destroy(all_cross);

    free(first);
    free(second);
    free(third);
    free(fourth);
    return 0;
}
