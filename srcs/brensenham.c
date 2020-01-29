#include "fdf.h"

void    go_brensenham(t_bresenham bre, t_windows *window, int increm, int h_v)
{
    int color;

    color = bre.color_a;
    while (bre.start <= bre.stop)
    {
        if (bre.stop / 2 <= bre.start)
            color = bre.color_b;
        if (h_v == 0)
            draw_pixel(bre.start, bre.p_increm, window);
        else
            draw_pixel(bre.p_increm, bre.start, window);
        bre.e = bre.e + bre.m;
        if (bre.e >= 0)
        {
            bre.e = bre.e + bre.sub;
            bre.p_increm = bre.p_increm + increm;
        }
        bre.start++;
    }
}

void    init_brensenham(t_point *a, t_point *b, t_windows *window)
{
    t_bresenham bre;

    bre.dx = ft_abs(b->x - a->x);
    bre.dy = ft_abs(b->y - a->y);
    bre.color_a = (int)a->color;
    bre.color_b = (int)b->color;
    if (bre.dx >= bre.dy)
    {
        bre.start = a->x;
        bre.stop = b->x;
        bre.p_increm = a->y;
        bre.e = -bre.dx;
        bre.m = bre.dy * 2;
        bre.sub = -bre.dx * 2;
        if (b->y >= a->y)
            go_brensenham(bre, window, 1, 0);
        else
            go_brensenham(bre, window, -1, 0);
    }
    else
    {
        bre.start = a->y;
        bre.stop = b->y;
        bre.p_increm = a->x;
        bre.e = -bre.dy;
        bre.m = bre.dx * 2;
        bre.sub = -bre.dy * 2;
        if (b->x >= a->x)
            go_brensenham(bre, window, 1, 1);
        else
            go_brensenham(bre, window, -1, 1);
    }
}
