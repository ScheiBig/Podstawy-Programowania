#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "my_utils_v2.h"
__include__discard_stdin()
__include__string_endswith()
#include "statistics_utils.h"

int main()
{
    char* in_filename = (char*)malloc(sizeof(char) * 40);
    if (in_filename == null)
    {
        __m_exit(eMEMORY_cantallocate);
    }
    print_ln("Enter input file path:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    scanf("%39s", in_filename);
    discard_stdin();

    enum save_format_t format;

    if (string_endswith(in_filename, ".bin"))
    {
        format = fmt_binary;
    }
    else if (string_endswith(in_filename, ".txt"))
    {
        format = fmt_text;
    }
    else
    {
        free(in_filename);
        __m_exit(eFILE_unsupported);
    }

    int** data;
    switch (load(in_filename, &data, format))
    {
    case 2:
        free(in_filename);
        __m_exit(eFILE_noaccess);
    case 3:
        free(in_filename);
        __m_exit(eFILE_corrupted);
    case 4:
        free(in_filename);
        __m_exit(eMEMORY_cantallocate);
    default: break;
    }

    struct statistic_t* stats;
    int st_size;
    if ((st_size = statistics_row(data, &stats)) < 0)
    {
        destroy(&data);
        free(in_filename);
        __m_exit(eMEMORY_cantallocate);
    }

    for (struct statistic_t* s = stats; s < stats + st_size; ++s)
    {
        printf_ln("%d %d %d %.2f %.2f", s->min, s->max, s->range, s->avg, s->standard_deviation);
    }

    free(stats);
    destroy(&data);
    free(in_filename);
    return 0;
}
