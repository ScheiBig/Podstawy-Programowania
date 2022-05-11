#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "my_utils_v2.h"
__include__discard_stdin()
#include "statistics_utils.h"


int main()
{
    int A[] = { 10, 20, 30, 40, 50, 60, 70, -1 };
    int B[] = { 100, 200, 300, 400, 500, 600, 700, 800, -1 };
    int C[] = { 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, -1 };
    int* D[] = { A, B, C, NULL };

    display(D);

    char* out_filename = (char*)malloc(sizeof(char) * 40);
    if (out_filename == null)
    {
        __m_exit(eMEMORY_cantallocate);
    }
    print_ln("Enter output file path:");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    scanf("%39s", out_filename);
    discard_stdin();

    char* tout_filename = (char*)malloc(sizeof(char) * 44);
    if (tout_filename == null)
    {
        free(out_filename);
        __m_exit(eMEMORY_cantallocate);
    }
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.strcpy) -> Dante doesn't provide *_s
    strcpy(tout_filename, out_filename);
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.strcpy) -> Dante doesn't provide *_s
    strcat(tout_filename, ".txt");
    
    if (save(tout_filename, D, fmt_text) == 0)
    {
        print_ln("File saved");
    }
    else
    {
        print_ln(eFILE_cantcreate);
    }
    free(tout_filename);

    char* bout_filename = (char*)malloc(sizeof(char) * 44);
    if (bout_filename == null)
    {
        free(out_filename);
        __m_exit(eMEMORY_cantallocate);
    }
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.strcpy) -> Dante doesn't provide *_s
    strcpy(bout_filename, out_filename);
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.strcpy) -> Dante doesn't provide *_s
    strcat(bout_filename, ".bin");

    if (save(bout_filename, D, fmt_binary) == 0)
    {
        print_ln("File saved");
    }
    else
    {
        print_ln(eFILE_cantcreate);
    }
    free(bout_filename);

    struct statistic_t* stats;

    if (statistics(D, &stats) != 0)
    {
        free(out_filename);
        __m_exit(eMEMORY_cantallocate);
    }

    printf_ln("%d", stats->min);
    printf_ln("%d", stats->max);
    printf_ln("%d", stats->range);
    printf_ln("%f", stats->avg);
    printf_ln("%f", stats->standard_deviation);

    free(stats);
    free(out_filename);
    return 0;
}
