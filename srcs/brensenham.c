#include "fdf.h"

void    brensenham2(int x1, int y1, int x2, int y2, t_windows *window)
{
    int m;
    int e;
    int dx;
    int dy;
    int sub;

    dx = x2 - x1;
    dy = y2 - y1;
    e = -dy;
    m = dx * 2;
    sub = -dy * 2;
    while (y2 <= y1)
    {
        draw_pixel(x1, y1, window);
        e = e + m;
        if (e >= 0)
        {
            e = e - sub;
            x1++;
        }
        y1--;
    }
}

void    brensenham(int x1, int y1, int x2, int y2, t_windows *window)
{
    int m;
    int e;
    int dx;
    int dy;
    int sub;

    dx = x2 - x1;
    dy = y2 - y1;
    e = -dx;
    m = dy * 2;
    sub = -dx * 2;
    while (x1 <= x2)
    {
        draw_pixel(x1, y1, window);
        e = e + m;
        if (e >= 0)
        {
            e = e - sub;
            y1++;
        }
        x1++;
    }
}


void    init_bresenham(int x1, int y1, int x2, int y2, t_windows *window)
{
    if (y2 - y1 < 0)
    {
        brensenham2(x1, y2, x2, y2, window);
    }
    else
    {
        brensenham(x1, y1, x2, y2, window);
    }
}
