#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "my_utils.h"

struct point_t
{
    int x;
    int y;
};

struct rectangle_t
{
    struct point_t p;
    int width;
    int height;
};
struct circle_t
{
    struct point_t c;
    float r;
};
struct triangle_t
{
    struct point_t p1;
    struct point_t p2;
    struct point_t p3;
};

enum figure_types
{
    TRIANGLE = 1,
    RECTANGLE,
    CIRCLE
};

struct figure_t
{
    union
    {
        struct triangle_t triangle;
        struct rectangle_t rect;
        struct circle_t circ;
    };
    enum figure_types type;
};

float area_triangle(const struct triangle_t* t);
float area_rectangle(const struct rectangle_t* r);
float area_circle(const struct circle_t* c);
float area_figure(const struct figure_t* f);

void display_triangle(const struct triangle_t* t);
void display_rectangle(const struct rectangle_t* r);
void display_circle(const struct circle_t* c);
void display_figure(struct figure_t* f);

int sort_by_area(struct figure_t** figures, int size);

int main()
{
    int fig_choice;
    struct figure_t figures[50];
    u_int fig_count;
    struct figure_t* f;

    for (fig_count = 0, f = figures; fig_count < 50; ++fig_count, ++f)
    {
        print_ln("Enter figure's type:");
        //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
        if (scanf("%d", &fig_choice) != 1)
        {
            _m_exit(eINPUT_invalid, eINPUT_invalid_msg)
        }
        switch (fig_choice)
        {
        case 0: goto break_for;
        case TRIANGLE:
            print_ln("Enter triangle vertices (x1 y1 x2 y2 x3 y3):");
            //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
            if (scanf("%d %d %d %d %d %d", &f->triangle.p1.x, &f->triangle.p1.y,
                &f->triangle.p2.x, &f->triangle.p2.y, &f->triangle.p3.x, &f->triangle.p3.y) != 6)
            {
                _m_exit(eINPUT_invalid, eINPUT_invalid_msg)
            }
            break;
        case RECTANGLE:
            print_ln("Enter rectangle origin and dimensions (x y width height):");
            //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
            if (scanf("%d %d %d %d", &f->rect.p.x, &f->rect.p.y, &f->rect.width, &f->rect.height) != 4)
            {
                _m_exit(eINPUT_invalid, eINPUT_invalid_msg)
            }
            break;
        case CIRCLE:
            print_ln("Enter circle centre and radius (x y radius):");
            //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) -> Dante doesn't provide *_s
            if (scanf("%d %d %f", &f->circ.c.x, &f->circ.c.y, &f->circ.r) != 3)
            {
                _m_exit(eINPUT_invalid, eINPUT_invalid_msg)
            }
            break;
        default:
            _m_exit(eDATA_invalid, eDATA_invalid_msg)
        }
        f->type = (enum figure_types)fig_choice;
    }
break_for: {}
    struct figure_t* figs[50];
    for (u_int i = 0; i < fig_count; ++i)
    {
        if (double_almost_eq(area_figure(figures + i), -1, 0.000005))
        {
            _m_exit(eDATA_invalid, eDATA_invalid_msg)
        }
        *(figs + i) = figures + i;
    }
    sort_by_area(figs, (int)fig_count);
    for (u_int i = 0; i < fig_count; ++i)
    {
        display_figure(*(figs + i));
    }
    return 0;
}

float area_triangle(const struct triangle_t* t)
{
    if (t == null)
    {
        return -1;
    }
    float area = (1. / 2) * fabsf((float)t->p1.x * (t->p2.y - t->p3.y) + t->p2.x * (t->p3.y - t->p1.y) + t->p3.x * (t->p1.y - t->p2.y));
    if (area > 0)
    {
        return area;
    }
    else
    {
        return -1;
    }
}

float area_rectangle(const struct rectangle_t* r)
{
    if (r == null || r->height <= 0 || r->width <= 0)
    {
        return -1;
    }
    return r->height * r->width;
}

float area_circle(const struct circle_t* c)
{
    if (c == null || c->r <= 0)
    {
        return -1;
    }
    return M_PI * c->r * c->r;
}

float area_figure(const struct figure_t* f)
{
    if (f != null)
    {
        switch (f->type)
        {
        case TRIANGLE: return area_triangle(&f->triangle);
        case RECTANGLE: return area_rectangle(&f->rect);
        case CIRCLE: return area_circle(&f->circ);
        default: return -1;
        }
    }
    else
    {
        return -1;
    }
}


void display_triangle(const struct triangle_t* t)
{
    if (t != null)
    {
        printf_ln("Triangle p1(%d, %d), p2(%d, %d), p3(%d, %d)", t->p1.x, t->p1.y, t->p2.x, t->p2.y, t->p3.x, t->p3.y);
    }
}

void display_rectangle(const struct rectangle_t* rect)
{
    if (rect != null)
    {
        printf_ln("Rectangle (%d, %d), width = %d, height = %d", rect->p.x, rect->p.y, rect->width, rect->height);
    }
}

void display_circle(const struct circle_t* circ)
{
    if (circ != null)
    {
        printf_ln("Circle (%d, %d), radius = %f", circ->c.x, circ->c.y, circ->r);
    }
}

void display_figure(struct figure_t* f)
{
    if (f != null)
    {
        switch (f->type)
        {
        case TRIANGLE:
            display_triangle(&f->triangle);
            return;
        case RECTANGLE:
            display_rectangle(&f->rect);
            return;
        case CIRCLE:
            display_circle(&f->circ);
            return;
        default: break;
        }
    }
}


int sort_by_area(struct figure_t** figures, int size)
{
    if (figures == null || size < 1)
    {
        return 1;
    }
    for (struct figure_t* f = *figures; f < *figures + size; ++f)
    {
        if (f == null)
        {
            return 1;
        }
    }
    struct figure_t* temp;
    float a1, a2;
    for (int i = size; i > 0; --i)
    {
        for (int j = 0; j < (i - 1); ++j)
        {
            a1 = area_figure(*(figures + j));
            a2 = area_figure(*(figures + j + 1));
            if (a1 == -1 || a2 == -1)
            {
                return 1;
            }
            if (a1 < a2)
            {
                temp = *(figures + j);
                *(figures + j) = *(figures + j + 1);
                *(figures + j + 1) = temp;
            }
        }
    }
    return 0;
}
