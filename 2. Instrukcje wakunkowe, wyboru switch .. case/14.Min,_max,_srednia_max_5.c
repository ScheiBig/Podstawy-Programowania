#include <stdio.h>

int main()
{
    float min, max, avg,
        num1 = -1, num2 = -1, num3 = -1, num4 = -1, num5 = -1;

    int avg_cnt = 1;

    char buffer[256];

    // char snum1 [20], snum2 [20], snum3 [20], snum4 [20], snum5 [20];

    printf("Input 5 numbers:\n");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%f %f %f %f %f", &num1, &num2, &num3, &num4, &num5);

    avg = num1;
    max = num1;
    min = num1;
    if (num2 != -1)
    {
        if (max < num2)
            max = num2;
        if (min > num2)
            min = num2;
        ++avg_cnt;
        avg += num2;
        if (num3 != -1)
        {
            if (max < num3)
                max = num3;
            if (min > num3)
                min = num3;
            ++avg_cnt;
            avg += num3;
            if (num4 != -1)
            {
                if (max < num4)
                    max = num4;
                if (min > num4)
                    min = num4;
                ++avg_cnt;
                avg += num4;
                if (num5 != -1)
                {
                    if (max < num5)
                        max = num5;
                    if (min > num5)
                        min = num5;
                    ++avg_cnt;
                    avg += num5;
                }
            }
        }
    }

    avg /= avg_cnt;
    printf("%f\n%f\n%.2f\n", min, max, avg);
    return 0;
}
