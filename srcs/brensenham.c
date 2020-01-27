#include "fdf.h"

void    go_brensenham(t_bresenham bre, t_windows *window, int increm, int h_v)
{
    while (bre.start <= bre.stop)
    {
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


void    bresenham(int x1, int y1, int x2, int y2, t_windows *window)
{
    t_bresenham bre;

    bre.dx = ft_abs(x2 - x1);
    bre.dy = ft_abs(y2 - y1);
    if (bre.dx >= bre.dy)
    {
        bre.start = x1;
        bre.stop = x2;
        bre.p_increm = y1;
        bre.e = -bre.dx;
        bre.m = bre.dy * 2;
        bre.sub = -bre.dx * 2;
        if (y2 >= y1)
            go_brensenham(bre, window, 1, 0);
        else
            go_brensenham(bre, window, -1, 0);
    }
    else
    {
        bre.start = y1;
        bre.stop = y2;
        bre.p_increm = x1;
        bre.e = -bre.dy;
        bre.m = bre.dx * 2;
        bre.sub = -bre.dy * 2;
        if (x2 >= x1)
            go_brensenham(bre, window, 1, 1);
        else
            go_brensenham(bre, window, -1, 1);
    }
}
