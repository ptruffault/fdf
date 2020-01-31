/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:14:23 by ptruffau          #+#    #+#             */
/*   Updated: 2020/01/24 15:14:28 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <unistd.h>

void    draw_pixel(int x, int y, t_windows *window, int color)
{
	int pixel;

	pixel = (x * 4) + (4 * window->width * y);
	window->img_str[pixel]  = 0;
	window->img_str[pixel + 1] = 0;
	window->img_str[pixel + 2] = 255;
	(void)color;

    //mlx_pixel_put(window->graph_id, window->windows, x, y, color);

}

void draw_lines()
{

}


int angle_check(int angle)
{
	return (angle == - 180 || angle == 0 || angle == 180);
}


void	draw_map_pts(t_windows *window, t_map *data)
{
	int i;
	int j;
	t_point a;
	t_point b;

	i = -1;
	init_pov(data, window);
	window->color = 0xDC143C;
	while (++i < data->height)
	{
		j = -1;
		while (++j < data->width)
		{
			a.x = data->margin_left + j * data->dist_pts_x + (angle_check(data->angle_x) ? 0 : data->points[i][j].z * data->z_multiplicateur * data->sens_x);
			a.y = data->margin_up + i * data->dist_pts_y + (angle_check(data->angle_y) ? 0 : data->points[i][j].z * data->z_multiplicateur * data->sens_y);
			a.color = data->points[i][j].color;


			// right line
			if (j != data->width - 1)
			{
				// right
				b.x = data->margin_left + (j + 1) * data->dist_pts_x + (angle_check(data->angle_x) ? 0 : data->points[i][j + 1].z * data->z_multiplicateur * data->sens_x);
				b.y = data->margin_up + i * data->dist_pts_y + (angle_check(data->angle_y)  ? 0 : data->points[i][j + 1].z * data->z_multiplicateur * data->sens_y);
				b.color = data->points[i][j + 1].color;
				init_brensenham(&a, &b, window);
			}

			// down line
			if (i != data->height - 1)
			{	
				b.x = data->margin_left + j * data->dist_pts_x + (angle_check(data->angle_x) ? 0 : data->points[i + 1][j].z * data->z_multiplicateur * data->sens_x);
				b.y = data->margin_up + (i + 1) * data->dist_pts_y + (angle_check(data->angle_x) ? 0 : data->points[i + 1][j].z * data->z_multiplicateur * data->sens_y);
				b.color = data->points[i + 1][j].color;
				init_brensenham(&a, &b, window);
			}

		}
	}
}

void	draw_new_map(t_windows *win, t_map *map)
{
	int bpp;
	int s_l;
	int endian;

	win->img_ptr = mlx_new_image(win->graph_id, win->width, win->height);
	win->img_str = (unsigned char*)mlx_get_data_addr(win->img_ptr, &bpp, &s_l, &endian);

	draw_map_pts(win, map);
	mlx_put_image_to_window(win->graph_id, win->windows, win->img_ptr, 0,0);
}

