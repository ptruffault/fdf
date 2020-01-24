#include "fdf.h"

void    draw_pixel(int x, int y, t_windows *window)
{
    mlx_pixel_put(window->graph_id, window->windows, x, y, 0xE2EDEC);
}
