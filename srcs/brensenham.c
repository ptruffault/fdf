#include "fdf.h"

//void    init_bresenham()
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
