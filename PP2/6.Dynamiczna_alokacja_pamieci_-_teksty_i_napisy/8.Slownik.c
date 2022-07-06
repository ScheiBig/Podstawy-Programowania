#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"
#include "my_utils_v3.h"

void _strip(cstring str)
{
    for (cstring s = str + strlen(str) - 1; s >= str; --s)
    {
        if (!isalpha(*s))
        {
            size_t len = strlen(str);
            for (cstring t = s; t < str + len; ++t)
            {
                *t = *(t + 1);
            }
        }
    }
}

int main()
{
    cstring f_name = (cstring)calloc(50, sizeof(char));
    if (f_name == null) { __m_exit(eMEMORY_cantallocate); }

    print_ln("Enter file path: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    scanf("%[^\n]49s", f_name);
    p_file f = fopen(f_name, "r");
    if (f == null)
    {
        free(f_name);
        __m_exit(eFILE_noaccess);
    }
    
    int e;
    dictionary dict = create_dictionary(10, &e);
    if (dict == null)
    {
        free(f_name);
        fclose(f);
        __m_exit(eMEMORY_cantallocate);
    }

    while (true)
    {
        //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
        if (fscanf(f, "%49s", f_name) <= 0) { break; }
        _strip(f_name);
        e = dictionary_add_word(dict, f_name);
        if (e == 2)
        {
            destroy_dictionary(&dict);
            free(f_name);
            fclose(f);
            __m_exit(eMEMORY_cantallocate);
        }
    }

    if (dict->size == 0)
    {
        print_ln("Nothing to show");
    }
    else
    {
        dictionary_display(dict);
    }

    destroy_dictionary(&dict);
    free(f_name);
    fclose(f);
    return 0;
}
