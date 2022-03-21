#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define __discard_stdin__
#include "my_utils.h"

struct point_t
{
    int x;
    int y;
};
struct point_t* read(struct point_t* p);
struct point_t* set(struct point_t* p, int x, int y);
void show(const struct point_t* p);
float distance(const struct point_t* p1, const struct point_t* p2, int* err_code);

typedef struct point_t point;

int main()
{
    srand(time(NULL));
    struct point p1;
    struct point p2;

    if (read(&p1) == NULL)
    {
        _e_exit(eINPUT_invalid, eINPUT_invalid_msg)
    }
    set(&p2, clip_range(rand(), -100, 100), clip_range(rand(), -100, 100));
    show(&p1);
    show(&p2);
    printf_ln("%.2f", distance(&p1, &p2, NULL));
}

struct point_t* read(struct point_t* p)
{
    if (p == NULL)
    {
        return NULL;
    }
    print_ln("Enter x coordinate: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d", &p->x) != 1)
    {
        return NULL;
    }
    print_ln("Enter y coordinate: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d", &p->y) != 1)
    {
        return NULL;
    }
    return p;
}

struct point_t* set(struct point_t* p, int x, int y)
{
    if (p == NULL)
    {
        return NULL;
    }
    p->x = x;
    p->y = y;
    return p;
}

void show(const struct point_t* p)
{
    if (p != NULL)
    {
        printf_ln("{ x: %d, y: %d }", p->x, p->y);
    }
}

float distance(const struct point_t* p1, const struct point_t* p2, int* err_code)
{
    if (p1 == NULL || p2 == NULL)
    {
        cond_assign_nn(err_code, 1)
        return -1;
    }
    cond_assign_nn(err_code, 0)
    return (float)sqrt((double)(p1->x - p2->x) * (p1->x - p2->x) + (double)(p1->y - p2->y) * (p1->y - p2->y));
}
