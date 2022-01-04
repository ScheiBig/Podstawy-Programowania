#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <float.h>

#include "my_utils.h"

#define MAT_SIZ 10

int main()
{
    int M[MAT_SIZ][MAT_SIZ] = { 0 };
    int max = INT_MIN;
    int min = INT_MAX;
    double avg = 0;

    printf("Enter a 10x10 matrix:\n");

    for (size_t r = 0; r < MAT_SIZ; ++r)
    {
        for (size_t c = 0; c < MAT_SIZ; ++c)
        {
            if (scanf("%d", *(M + r) + c) != 1) _e_exit(1, "Incorrect input\n")
                COND_ASSIGN_L(max, M[r][c]);
            COND_ASSIGN_G(min, M[r][c]);
            avg += M[r][c];
        }
    }
    avg /= MAT_SIZ * MAT_SIZ;

    coords2d pmax = { -1, -1, 0 },
        pmin = { -1, -1, 0 },
        pavg = { -1, -1, 0 };

    double min_avg_diff = DBL_MAX;
    double cur_avg_diff;
    int possible_dup = 0;


    for (size_t r = 0; r < MAT_SIZ; ++r)
    {
        for (size_t c = 0; c < MAT_SIZ; ++c)
        {
            if (M[r][c] == max && pmax.set)
            {
                _e_exit(2, "Error\n")
            }
            else if (M[r][c] == max)
            {
                pmax.x = (int)c;
                pmax.y = (int)r;
                pmax.set = 1;
            }

            if (M[r][c] == min && pmin.set)
            {
                _e_exit(2, "Error\n")
            }
            else if (M[r][c] == min)
            {
                pmin.x = (int)c;
                pmin.y = (int)r;
                pmin.set = 1;
            }

            cur_avg_diff = fabs(M[r][c] - avg);
            if (cur_avg_diff < min_avg_diff)
            {
                pavg.x = (int)c;
                pavg.y = (int)r;
                pavg.set = 1;
                possible_dup = 0;
                min_avg_diff = cur_avg_diff;
            }
            else if (cur_avg_diff == min_avg_diff && pavg.set)
            {
                ++possible_dup;
            }
        }
    }
    if (possible_dup)
    {
        _e_exit(2, "Error\n")
    }

    int maxminx = abs(pmax.x - pmin.x);
    int maxminy = abs(pmax.y - pmin.y);
    int minavgx = abs(pmin.x - pavg.x);
    int minavgy = abs(pmin.y - pavg.y);
    int avgmaxx = abs(pavg.x - pmax.x);
    int avgmaxy = abs(pavg.y - pmax.y);
    double l1 = sqrt(maxminx * maxminx + maxminy * maxminy);
    double l2 = sqrt(minavgx * minavgx + minavgy * minavgy);
    double l3 = sqrt(avgmaxx * avgmaxx + avgmaxy * avgmaxy);

    printf("%.2lf %.2lf %.2lf\n", l1, l2, l3);

    return 0;
}
