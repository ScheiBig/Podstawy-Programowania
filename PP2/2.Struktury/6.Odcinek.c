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

typedef struct segment_t
{
    struct point_t start;
    struct point_t end;
} segment_s;
struct segment_t* read_segment(struct segment_t* p);
void show_segment(const struct segment_t* p);
float length(const struct segment_t* s, int* err_code);

int main()
{
    segment_s segment;
    if (read_segment(&segment) == null)
    {
        _m_exit(eINPUT_invalid, eINPUT_invalid_msg)
    }
    show_segment(&segment);
    printf("%.2f", length(&segment, null));
    return 0;
}

struct point_t* read(struct point_t* p)
{
    if (p == null)
    {
        return null;
    }
    print_ln("Enter x coordinate: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d", &p->x) != 1)
    {
        return null;
    }
    print_ln("Enter y coordinate: ");
    //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
    if (scanf("%d", &p->y) != 1)
    {
        return null;
    }
    return p;
}

struct point_t* set(struct point_t* p, int x, int y)
{
    if (p == null)
    {
        return null;
    }
    p->x = x;
    p->y = y;
    return p;
}

void show(const struct point_t* p)
{
    if (p != null)
    {
        printf_ln("{ x: %d, y: %d }", p->x, p->y);
    }
}

float distance(const struct point_t* p1, const struct point_t* p2, int* err_code)
{
    if (p1 == null || p2 == null)
    {
        cond_assign_nn(err_code, 1)
            return -1;
    }
    cond_assign_nn(err_code, 0)
        return (float)sqrt((double)(p1->x - p2->x) * (p1->x - p2->x) + (double)(p1->y - p2->y) * (p1->y - p2->y));
}

struct segment_t* read_segment(struct segment_t* p)
{
    print_ln("Enter start coordinates: ");
    if (read(&p->start) == null)
    {
        return null;
    }
    print_ln("Enter end coordinates: ");
    if (read(&p->end) == null)
    {
        return null;
    }
    return p;
}

void show_segment(const struct segment_t* p)
{
    if (p != null)
    {
        show(&p->start);
        show(&p->end);
    }
}

float length(const struct segment_t* s, int* err_code)
{
    return distance(&s->start, &s->end, err_code);
}
