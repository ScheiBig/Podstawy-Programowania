#include <stdio.h>
#include <math.h>

#define BUF_LEN 8064

int main()
{
    long even_sum = 0, odd_sum = 0;
    char buffer[BUF_LEN];
    size_t num_count = 0;

    printf("Enter the numbers: \n");
    if (fgets(buffer, BUF_LEN, stdin) != NULL)
    {
        int len;
        int current;
        for (size_t i = 0; i < BUF_LEN;)
        {
            if (sscanf(buffer + i, "%d %n", &current, &len) == 1)
            {
                if (current == -1)
                { break; }

                if (current % 2 == 0)
                { even_sum += current; }
                else
                { odd_sum += current; }

                ++num_count;
                i += len;
            }
            else
            {
                printf("Incorrect input");
                return 1;
            }
        }
    }
    else
    {
        printf("Incorrect input");
        return 1;
    }

    printf("Sum if even numbers: %ld\n", even_sum);
    printf("Sum if odd numbers: %ld\n", odd_sum);

    return 0;
}