#include <stdio.h>
#include <limits.h>

#define BUF_LEN 8064

int main()
{
    int nums[1000], acc_vals[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    char buffer[BUF_LEN];
    size_t acc_siz[11] = { 0 }, num_count = 0;

    printf("Enter your numbers:\n");
    if (fgets(buffer, BUF_LEN, stdin) != NULL)
    {
        int len;
        int current;
        for (size_t i = 0; i < BUF_LEN;)
        {
            //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
            if (sscanf(buffer + i, "%d %n", &current, &len) == 1)
            {
                if (current == -1 || num_count >= 1000) break;
                i += len;
                if (current < 0 || current > 10) continue;


                nums[num_count] = current;

                ++num_count;
            }
            else
            {
                printf("Incorrect input\n");
                return 1;
            }
        }
    }
    else
    {
        printf("Incorrect input\n");
        return 1;
    }

    for (size_t i = 0; i < num_count; ++i)
    {
        ++acc_siz[nums[i]];
    }

    for (size_t i = 0; i <= 10; ++i)
    {
        printf("%i - %zu\n", acc_vals[i], acc_siz[i]);
    }

    return 0;
}
