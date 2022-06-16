#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "my_utils_v3.h"
#include "my_string.h"
#include "char_operations.h"

int main()
{
    char_op funcs[] = { lower_to_upper, upper_to_lower, space_to_dash, reverse_letter };

    char* text = (cstring)calloc(1001, sizeof(char));
    if (text == null) { __m_exit(eMEMORY_cantallocate); }


    printf("Enter a string: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%1000[^\n]s", text) != 1)
    {
        free(text);
        __m_exit(eINPUT_invalid);
    }
    
    int op_n;

    discard_stdin();

    print_ln("Enter a operation no. (0-to_upper, 1-to_lower, 2-pascal_case, 3-flip_ascii):");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d", &op_n) != 1)
    {
        free(text);
        __m_exit(eINPUT_invalid);
    }
    else if (!is_num_in_range(op_n, 0, 3))
    {
        free(text);
        __m_exit(eDATA_invalid);
    }

    char* result = letter_modifier(text, *(funcs + op_n));
    if (result == null)
    {
        free(text);
        __m_exit(eMEMORY_cantallocate);
    }

    printf_ln("%s", result);

    free(result);
    free(text);

    return 0;
}
