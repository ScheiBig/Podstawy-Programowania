#include <stdio.h>
#include <limits.h>

#define BUF_LEN 8064

int main()
{
    int nums[100], min = INT_MAX, max = INT_MIN;
    long sum = 0;
    char buffer[BUF_LEN];
    size_t num_count = 0, max_i[100], max_c = 0, min_i[100], min_c = 0;

    printf("Enter up to 100 numbers:\n");
    if (fgets(buffer, BUF_LEN, stdin) != NULL)
    {
        int len;
        int current;
        for (size_t i = 0; i < BUF_LEN;)
        {
            //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
            if (sscanf(buffer + i, "%d %n", &current, &len) == 1)
            {
                if (current == -1 || num_count >= 100) break;

                nums[num_count] = current;

                ++num_count;
                i += len;
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
        if (min == nums[i])
        {
            min_i[min_c] = i;
            ++min_c;
        }
        else if (min > nums[i])
        {
            min_i[0] = i;
            min_c = 1;
            min = nums[i];
        }

        if (max == nums[i])
        {
            max_i[max_c] = i;
            ++max_c;
        }
        else if (max < nums[i])
        {
            max_i[0] = i;
            max_c = 1;
            max = nums[i];
        }
        sum += nums[i];
    }

    double avg = (sum * 1.0) / num_count;
    printf("%zu\n%d\n%d\n%lf\n%ld\n", num_count, min, max, avg, sum);
    for (size_t i = 0; i < min_c; ++i)
    {
        printf("%zu ", min_i[i]);
    }
    printf("\n");
    for (size_t i = 0; i < max_c; ++i)
    {
        printf("%zu ", max_i[i]);
    }
    printf("\n");

    return 0;
}